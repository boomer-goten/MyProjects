package input

import "github.com/go-playground/validator"

type CommentPost struct {
	PostID int  `json:"postID" validate:"required,min=1"`
	Depth  *int `json:"depth,omitempty"`
}

func (c CommentPost) Validate() error {
	validate := validator.New()
	if err := validate.Struct(c); err != nil {
		return err
	}
	return nil
}
