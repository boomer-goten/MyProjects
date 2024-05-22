package api

import (
	"net/http"
)

// Обработчик ошибок
type ErrorHandler func(w http.ResponseWriter, r *http.Request, err error, result *Response)

func DefaultErrorHandler(w http.ResponseWriter, r *http.Request, err error, result *Response) {
	if result == nil {
		EncodeJSONResponse(err.Error(), func(i int) *int { return &i }(http.StatusBadRequest), w)
	} else {
		EncodeJSONResponse(err.Error(), &result.Code, w)
	}

}
