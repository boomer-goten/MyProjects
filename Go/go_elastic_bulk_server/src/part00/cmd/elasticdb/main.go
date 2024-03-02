package main

import (
	"elasticdb/config/elasticcfg"
	"elasticdb/internal/csvreader"
	"elasticdb/internal/reader"
	"elasticdb/pkg/db"
	"elasticdb/pkg/elastic"
	"log"
)

func main() {
	filename := "../../../../materials/data.csv"
	var (
		reader reader.Reader
		err    error
		db     db.Store
	)
	db, err = elastic.NewElasticDefault(elasticcfg.NewElasticCfg())
	check(err)
	defer db.Close()
	reader, err = csvreader.NewCSVReader(filename)
	check(err)
	defer reader.Close()
	err = db.Create()
	check(err)
	err = db.Insert(reader)
	check(err)
}

func check(err error) {
	if err != nil {
		log.Fatal(err)
	}
}
