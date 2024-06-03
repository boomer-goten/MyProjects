package input

import "github.com/go-playground/validator"

type NewPost struct {
	Title         string `json:"title" validate:"required,min=5"`
	Content       string `json:"content" validate:"required,min=10"`
	AllowComments *bool  `json:"allowComments,omitempty"`
}

func (n NewPost) Validate() error {
	validate := validator.New()
	if err := validate.Struct(n); err != nil {
		return err
	}
	return nil
}
