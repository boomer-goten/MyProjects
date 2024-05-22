package model

import (
	"github.com/go-playground/validator"
)

// Тело входящего запроса
type ExchangeGetRequest struct {
	// Сумма Денег
	Amount int `json:"amount" validate:"required,min=1"`
	// Доступные номиналы банкнот
	Banknotes []int `json:"banknotes" validate:"required,min=1"`
}

// Проверка полей структуры
func AssertExchangeGetRequest(obj ExchangeGetRequest) error {
	validate := validator.New()
	if err := validate.Struct(obj); err != nil {
		return err
	}
	return nil
}
