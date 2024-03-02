package templ

import (
	"elasticdb/pkg/model"
)

type Template struct {
	Total    int           `json:"total"`
	Places   []model.Place `json:"places"`
	Previous int           `json:"prev_page"`
	Next     int           `json:"next_page"`
	Last     int           `json:"last_page"`
}

type JSONTempl struct {
	Name string `json:"name"`
	Template
}

type Recommend struct {
	Name   string        `json:"name"`
	Places []model.Place `json:"places"`
}

type Tokenize struct {
	JWTToken string `json:"token"`
}
