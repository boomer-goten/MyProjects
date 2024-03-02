package reader

import "elasticdb/pkg/model"

type Reader interface {
	Read() (*model.Place, error)
	Close()
}
