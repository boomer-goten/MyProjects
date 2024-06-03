package input

import "github.com/go-playground/validator"

type LoginRegister struct {
	Name     string `json:"name" validate:"required,min=1"`
	Password string `json:"password" validate:"required,min=1"`
}

func (l LoginRegister) Validate() error {
	validate := validator.New()
	if err := validate.Struct(l); err != nil {
		return err
	}
	return nil
}
