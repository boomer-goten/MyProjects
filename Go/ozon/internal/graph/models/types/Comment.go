package types

type Comment struct {
	ID              int        `json:"id"`
	PostID          int        `json:"postID" gorm:"foreignkey:PostID"`
	ParentCommentID *int       `json:"parentCommentID,omitempty"`
	UserName        string     `json:"userName"`
	Text            string     `json:"text"`
	Depth           int        `json:"depth"`
	ChildComments   []*Comment `json:"childComments,omitempty" gorm:"-"`
}

func (u *Comment) TableName() string {
	return "comments"
}
