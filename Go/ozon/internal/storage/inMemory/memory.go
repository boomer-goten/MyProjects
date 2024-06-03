package inmemory

import (
	"errors"
	"fmt"
	"graphQL-fakereddit-service/internal/graph/models/input"
	"graphQL-fakereddit-service/internal/graph/models/types"
	"sync"
)

type InMemory struct {
	mu           sync.RWMutex
	users        map[string]types.User
	posts        map[int]types.Post
	comments     map[int]*types.Comment
	maxUserID    int
	maxPostID    int
	maxCommentID int
}

func New() *InMemory {
	db := &InMemory{maxUserID: 0, maxPostID: 0}
	db.posts = make(map[int]types.Post)
	db.users = make(map[string]types.User)
	db.comments = make(map[int]*types.Comment)
	db.maxCommentID = 1
	return db
}

func (p *InMemory) CreatePost(data input.NewPost, ID int, Name string) (*types.Post, error) {
	defaultAllow := true
	if data.AllowComments != nil {
		defaultAllow = *data.AllowComments
	}
	InsertPost := types.Post{ID: p.maxUserID, UserName: Name, Title: data.Title, Content: data.Content, AllowComments: defaultAllow, Comments: nil}
	p.mu.Lock()
	p.posts[p.maxUserID] = InsertPost
	p.maxUserID++
	p.mu.Unlock()
	return &InsertPost, nil
}

func (p *InMemory) CreateComment(data input.NewComment, ID int, Name string) (*types.Comment, error) {
	post, ok := p.getPost(data.PostID)
	if !ok {
		return nil, errors.New("post  doesn't exist")
	} else if !post.AllowComments {
		return nil, errors.New("the owner has disabled comments")
	}
	p.mu.Lock()
	defer p.mu.Unlock()
	NewComment := types.Comment{ID: p.maxCommentID, PostID: data.PostID, UserName: Name, Text: data.Text, ParentCommentID: data.ParentCommentID}
	var comments *types.Comment
	if *data.ParentCommentID != 0 {
		comments, ok = p.comments[*data.ParentCommentID]
		if !ok {
			return nil, errors.New("parent comment doesn't exist")
		}
		NewComment.Depth = comments.Depth + 1
		comments.ChildComments = append(comments.ChildComments, &NewComment)
	} else {
		NewComment.Depth = 1
		post.Comments = append(post.Comments, &NewComment)
		p.posts[data.PostID] = post
	}
	p.maxCommentID++
	p.comments[NewComment.ID] = &NewComment
	return &NewComment, nil
}

func (p *InMemory) AccessComments(data input.ChangeAccessComments, ID int, name string) (*types.Post, error) {
	value, ok := p.getPost(data.PostID)
	if !ok {
		return nil, errors.New("post doesn't exist")
	}
	if value.UserName != name {
		return nil, errors.New("you are not the owner of this post")
	}
	value.AllowComments = data.AllowComments
	p.mu.Lock()
	defer p.mu.Unlock()
	p.posts[data.PostID] = value
	return &value, nil
}

func (p *InMemory) GetPost(data *input.CommentPost, limit *int, offset *int) (*types.CommentsConnection, error) {
	post, ok := p.getPost(data.PostID)
	if !ok {
		return nil, errors.New("post doesn't exist")
	}
	ReturnPost := post
	if len(post.Comments) >= *offset+*limit {
		ReturnPost.Comments = post.Comments[*offset:(*offset + *limit)]
	} else {
		ReturnPost.Comments = post.Comments[*offset:]
	}
	page := types.PageInfo{StartCursor: fmt.Sprint(*offset), EndCursor: fmt.Sprint(*offset + len(ReturnPost.Comments))}
	return &types.CommentsConnection{Post: ReturnPost, PageInfo: &page}, nil
}

func (p *InMemory) GetPosts() ([]*types.Post, error) {
	p.mu.RLock()
	defer p.mu.RUnlock()
	posts := make([]*types.Post, 0, len(p.posts))
	for _, value := range p.posts {
		posts = append(posts, &value)
	}
	return posts, nil
}

func (p *InMemory) Register(data input.LoginRegister) (*types.RegistrResponse, error) {
	NewUser := types.User{
		Name:     data.Name,
		Password: data.Password,
	}
	if err := NewUser.EncryptPassword(); err != nil {
		return nil, errors.New("internal application error")
	}
	p.mu.Lock()
	defer p.mu.Unlock()
	_, ok := p.users[data.Name]
	if ok {
		return nil, errors.New("current user already exists")
	}
	NewUser.ID = p.maxUserID
	p.users[data.Name] = NewUser
	p.maxUserID++
	return &types.RegistrResponse{Response: data.Name}, nil
}

func (p *InMemory) Login(data input.LoginRegister) (int, error) {
	p.mu.RLock()
	user, ok := p.users[data.Name]
	p.mu.RUnlock()
	if !ok {
		return -1, errors.New("current user doesn't exist")
	}
	if user.CompareHashPassword(data.Password) {
		return user.ID, nil
	} else {
		return -1, errors.New("incorrect pasword")
	}
}

func (p *InMemory) Stop() error {
	return nil
}

func (p *InMemory) getPost(postID int) (types.Post, bool) {
	p.mu.RLock()
	value, ok := p.posts[postID]
	p.mu.RUnlock()
	return value, ok
}
