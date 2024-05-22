package api

import (
	"encoding/json"
	"errors"
	"exchange-service/internal/api/model"
	"net/http"
	"strings"
)

var (
	ErrData       = errors.New("invalid data")
	ErrFormtaData = errors.New("invalid format data")
)

type DefaultAPIController struct {
	service      DefaultAPIServicer
	errorHandler ErrorHandler
}

type DefaultAPIOption func(*DefaultAPIController)

func WithDefaultAPIErrorHandler(h ErrorHandler) DefaultAPIOption {
	return func(c *DefaultAPIController) {
		c.errorHandler = h
	}
}

func NewDefaultAPIController(s DefaultAPIServicer, opts ...DefaultAPIOption) Router {
	controller := &DefaultAPIController{
		service:      s,
		errorHandler: DefaultErrorHandler,
	}
	for _, opt := range opts {
		opt(controller)
	}
	return controller
}

func (c *DefaultAPIController) Routes() Routes {
	return Routes{
		"ExchangeGet": Route{
			strings.ToUpper("Get"),
			"/exchange",
			c.ExchangeGet,
		},
	}
}

// ExchangeGet - расчет вариантов размена
func (c *DefaultAPIController) ExchangeGet(w http.ResponseWriter, r *http.Request) {
	d := json.NewDecoder(r.Body)
	d.DisallowUnknownFields()
	destBody := model.ExchangeGetRequest{}
	if err := d.Decode(&destBody); err != nil {
		c.errorHandler(w, r, ErrData, nil)
		return
	}
	if err := model.AssertExchangeGetRequest(destBody); err != nil {
		c.errorHandler(w, r, ErrFormtaData, nil)
		return
	}
	result, err := c.service.ExchangeGet(r.Context(), destBody)
	if err != nil {
		c.errorHandler(w, r, err, &result)
		return
	}
	EncodeJSONResponse(result.Body, &result.Code, w)
}
