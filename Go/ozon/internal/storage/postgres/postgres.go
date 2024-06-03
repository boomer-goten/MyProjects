package postgres

import (
	"errors"
	"fmt"
	"graphQL-fakereddit-service/internal/graph/models/input"
	"graphQL-fakereddit-service/internal/graph/models/types"
	"graphQL-fakereddit-service/internal/storage"
	"os"
	"sync"

	"gorm.io/driver/postgres"
	"gorm.io/gorm"
)

var (
	once     = sync.Once{}
	database *Postgres
)

type Postgres struct {
	Db *gorm.DB
}

func New() *Postgres {
	once.Do(func() {
		db, err := gorm.Open(postgres.Open(os.Getenv("DB")), &gorm.Config{})
		rawDB, _ := db.DB()
		rawDB.SetMaxOpenConns(52)
		rawDB.SetMaxIdleConns(52)
		if err != nil {
			panic("coudn't connect to database")
		}
		database = &Postgres{db}
		database.MigrateDB()
	})
	return database
}

func (p *Postgres) MigrateDB() {
	if !p.Db.Migrator().HasTable(&types.User{}) {
		p.Db.AutoMigrate(&types.User{})
	}
	if !p.Db.Migrator().HasTable(&types.Post{}) {
		p.Db.AutoMigrate(&types.Post{})
		p.Db.Exec("ALTER TABLE posts ADD CONSTRAINT fk_name FOREIGN KEY (user_name) REFERENCES users(name);")
	}
	if !p.Db.Migrator().HasTable(&types.Comment{}) {
		p.Db.AutoMigrate(&types.Comment{})
		p.Db.Exec("ALTER TABLE comments ADD CONSTRAINT fk_name FOREIGN KEY (user_name) REFERENCES users(name);")
		p.Db.Exec("ALTER TABLE comments ADD CONSTRAINT fk_post_id FOREIGN KEY (post_id) REFERENCES posts(id);")
	}
}

func (p *Postgres) Stop() error {
	val, err := p.Db.DB()
	if err != nil {
		return errors.New("failed to get database error: " + err.Error())
	}
	return val.Close()
}

func (p *Postgres) CreatePost(data input.NewPost, ID int, Name string) (*types.Post, error) {
	defaultAllow := true
	if data.AllowComments != nil {
		defaultAllow = *data.AllowComments
	}
	InsertPost := types.Post{UserName: Name, Title: data.Title, Content: data.Content, AllowComments: defaultAllow, Comments: nil}
	if err := p.Db.Model(&types.Post{}).Create(&InsertPost).Error; err != nil {
		return nil, errors.New("internal error create Post")
	}
	return &InsertPost, nil
}

func (p *Postgres) CreateComment(data input.NewComment, ID int, Name string) (*types.Comment, error) {
	var post types.Post
	if err := p.Db.Model(&types.Post{}).Where("id = ?", data.PostID).First(&post).Error; err != nil {
		return nil, errors.New("post  doesn't exist")
	}
	if !post.AllowComments {
		return nil, errors.New("the owner has disabled comments")
	}
	parentComment := types.Comment{}
	if *data.ParentCommentID != 0 {
		if err := p.Db.Model(&types.Comment{}).Where("id = ?", data.ParentCommentID).First(&parentComment).Error; err != gorm.ErrRecordNotFound && err != nil {
			return nil, errors.New("parent comment with current ID doesn't exist")
		}
	}
	InsertComment := types.Comment{PostID: data.PostID, ParentCommentID: data.ParentCommentID, UserName: Name, Text: data.Text, Depth: parentComment.Depth + 1}
	if err := p.Db.Model(&types.Comment{}).Create(&InsertComment).Error; err != nil {
		return nil, errors.New("internal error create Comment")
	}
	return &InsertComment, nil
}

func (p *Postgres) AccessComments(data input.ChangeAccessComments, ID int, Name string) (*types.Post, error) {
	var updatedPost types.Post
	if err := p.Db.Model(&types.Post{}).Where("id = ?", data.PostID).Update("allow_comments", data.AllowComments).First(&updatedPost).Error; err != nil {
		return nil, errors.New("post doesn't exist")
	}
	if updatedPost.UserName != Name {
		return nil, errors.New("only the creator can edit a post")
	}
	return &updatedPost, nil
}

func (p *Postgres) GetPost(data *input.CommentPost, limit *int, offset *int) (*types.CommentsConnection, error) {
	var post types.Post
	if err := p.Db.Model(&types.Post{}).Where("id = ?", data.PostID).First(&post).Error; err != nil {
		return nil, errors.New("post doesn't exist")
	}
	var comments []*types.Comment
	if *data.Depth == -1 {
		*data.Depth = storage.DefaultDepth
	}
	if err := p.Db.Model(&types.Comment{}).Where("post_id = ? AND depth <= ?", data.PostID, data.Depth).Order("depth, parent_comment_id").Limit(*limit).Offset(*offset).Find(&comments).Error; err != nil {
		return nil, errors.New("internal error get comments")
	}
	if len(comments) != 0 {
		idToComment := make(map[int]*types.Comment, len(comments))
		currentDepth := comments[0].Depth
		for i := range comments {
			if currentDepth != comments[i].Depth {
				value := idToComment[*comments[i].ParentCommentID]
				value.ChildComments = append(value.ChildComments, comments[i])
			}
			idToComment[comments[i].ID] = comments[i]
		}
	}
	post.Comments = comments
	page := types.PageInfo{StartCursor: fmt.Sprint(*offset), EndCursor: fmt.Sprint(*offset + len(comments))}
	return &types.CommentsConnection{Post: post, PageInfo: &page}, nil
}

func (p *Postgres) GetPosts() ([]*types.Post, error) {
	posts := make([]*types.Post, 0)
	res := p.Db.Model(&types.Post{}).Find(&posts)
	if res.Error != nil {
		return nil, res.Error
	}
	return posts, nil
}

func (p *Postgres) Register(data input.LoginRegister) (*types.RegistrResponse, error) {
	NewUser := types.User{
		Name:     data.Name,
		Password: data.Password,
	}
	if err := NewUser.EncryptPassword(); err != nil {
		return nil, errors.New("internal application error")
	}
	if err := p.Db.Create(&NewUser).Error; err != nil {
		return nil, errors.New("current user already exists")
	}
	return &types.RegistrResponse{Response: data.Name}, nil
}

func (p *Postgres) Login(data input.LoginRegister) (int, error) {
	user := types.User{}
	result := p.Db.Model(&types.User{}).Where("name = ?", data.Name).First(&user)
	if err := result.Error; err != nil {
		return -1, errors.New("current user doesn't exist")
	}
	if user.CompareHashPassword(data.Password) {
		return user.ID, nil
	} else {
		return user.ID, errors.New("incorrect pasword")
	}
}
