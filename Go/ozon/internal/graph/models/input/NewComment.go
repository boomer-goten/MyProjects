package input

import "github.com/go-playground/validator"

type NewComment struct {
	PostID          int    `json:"postID" validate:"required,min=1"`
	ParentCommentID *int   `json:"parentCommentID,omitempty"`
	Text            string `json:"text" validate:"required,min=1,max=2000"`
}

func (n NewComment) Validate() error {
	validate := validator.New()
	if err := validate.Struct(n); err != nil {
		return err
	}
	return nil
}
