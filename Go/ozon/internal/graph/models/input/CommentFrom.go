package input

import "github.com/go-playground/validator"

type CommentFrom struct {
	PostID          int  `json:"postID" validate:"required,min=1"`
	Depth           *int `json:"depth,omitempty"`
	ParentCommentID *int `json:"parentCommentID,omitempty"`
}

func (c CommentFrom) Validate() error {
	validate := validator.New()
	if err := validate.Struct(c); err != nil {
		return err
	}
	return nil
}
