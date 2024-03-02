package csvreader

import (
	"elasticdb/pkg/model"
	"encoding/csv"
	"errors"
	"os"
	"strconv"
)

type CsvReader struct {
	Reader *csv.Reader
	file   *os.File
}

func NewCSVReader(filename string) (*CsvReader, error) {
	file, err := os.Open(filename)
	if err != nil {
		return nil, err
	}
	reader := csv.NewReader(file)
	reader.Comma = '\t'
	return &CsvReader{Reader: reader}, nil
}

func (c *CsvReader) Read() (*model.Place, error) {
	record, err := c.Reader.Read()
	if err != nil {
		return nil, err
	}
	id, _ := strconv.Atoi(record[0])
	id = id + 1
	lon, _ := strconv.ParseFloat(record[4], 64)
	lat, _ := strconv.ParseFloat(record[5], 64)
	if len(record) != 6 {
		return nil, errors.New("bad record")
	}
	place := model.Place{
		ID:      id,
		Name:    record[1],
		Address: record[2],
		Phone:   record[3],
		Location: model.Location{
			Longitude: lon,
			Latitude:  lat,
		},
	}
	return &place, nil
}

func (c *CsvReader) Close() {
	c.file.Close()
}
