package input

import "github.com/go-playground/validator"

type ChangeAccessComments struct {
	PostID        int  `json:"postID" validate:"required,min=1"`
	AllowComments bool `json:"allowComments"`
}

func (c ChangeAccessComments) Validate() error {
	validate := validator.New()
	if err := validate.Struct(c); err != nil {
		return err
	}
	return nil
}
