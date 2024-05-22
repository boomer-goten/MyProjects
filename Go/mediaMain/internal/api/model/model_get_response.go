package model

// Результат выполнения запроса
type ExchangeGetResponse struct {
	Exchanges [][]int `json:"exchanges"`
}
