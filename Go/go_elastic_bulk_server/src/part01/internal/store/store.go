package store

import "elasticdb/pkg/model"

type Store interface {
	GetPlaces(limit int, page int) ([]model.Place, int, error)
	GetNearPlaces(limit int, latitude, longitude float64) ([]model.Place, int, error)
}
