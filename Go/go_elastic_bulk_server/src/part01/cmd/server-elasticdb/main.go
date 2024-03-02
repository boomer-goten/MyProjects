package main

import (
	"elasticdb/config/elasticcfg"
	"elasticdb/pkg/db"
	"elasticdb/pkg/elastic"
	"log"
	"server-elasticdb/web/server"
)

func main() {
	var (
		err error
		db  db.Store
	)
	db, err = elastic.NewElasticDefault(elasticcfg.NewElasticCfg())
	if err != nil {
		log.Fatal(err)
	}
	defer db.Close()
	server.RunServer(db)
}
