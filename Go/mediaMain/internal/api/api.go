package api

import (
	"context"
	"exchange-service/internal/api/model"
	"net/http"
)

// Предобработка запросов
type DefaultAPIRouter interface {
	ExchangeGet(http.ResponseWriter, *http.Request)
}

// Выполнение логики запроса
type DefaultAPIServicer interface {
	ExchangeGet(ctx context.Context, data model.ExchangeGetRequest) (Response, error)
}
