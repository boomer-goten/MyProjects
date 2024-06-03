package types

type Post struct {
	ID            int        `json:"id" gorm:"PrimaryKey:autoIncrement:true"`
	UserName      string     `json:"userName"`
	Title         string     `json:"title"`
	Content       string     `json:"content"`
	AllowComments bool       `json:"allowComments"`
	Comments      []*Comment `json:"comments,omitempty" gorm:"-"`
	// Subscribers   []string   `json:"subscribers,omitempty"`
}

func (u *Post) TableName() string {
	return "posts"
}
