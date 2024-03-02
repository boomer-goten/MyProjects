package db

import (
	"elasticdb/internal/reader"
	"elasticdb/pkg/model"
)

type Store interface {
	Insert(reader reader.Reader) error
	Create() error
	Close() error
	GetPlaces(limit int, page int) ([]model.Place, int, error)
	GetNearPlaces(limit int, latitude, longitude float64) ([]model.Place, int, error)
}
