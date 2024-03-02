package elasticcfg

import (
	"time"

	"github.com/cenkalti/backoff"
	"github.com/elastic/go-elasticsearch/v8"
	"github.com/elastic/go-elasticsearch/v8/esutil"
)

var (
	IndexPlace   string = "places"
	MappingPlace        = `
    {
      "mappings": {
		"properties": {
			"name": {
				"type":  "text"
			},
			"address": {
				"type":  "text"
			},
			"phone": {
				"type":  "text"
			},
			"location": {
			  "type": "geo_point"
			}
		  }
      },
	  "settings": {
		"number_of_shards": 1
	  }
    }`
)

func NewElasticCfg() *elasticsearch.Config {
	retryBackoff := backoff.NewExponentialBackOff()
	e := elasticsearch.Config{
		Addresses: []string{
			"http://localhost:9200",
		},
		// Retry on 429 TooManyRequests statuses
		RetryOnStatus: []int{502, 503, 504},
		// Configure the backoff function
		RetryBackoff: func(i int) time.Duration {
			if i == 1 {
				retryBackoff.Reset()
			}
			return retryBackoff.NextBackOff()
		},
		// Retry up to 5 attempts
		MaxRetries: 5,
	}
	return &e
}

func NewBulkCfg(indexName string, es *elasticsearch.Client) *esutil.BulkIndexerConfig {
	b := esutil.BulkIndexerConfig{
		Index:         indexName,        // The default index name
		Client:        es,               // The Elasticsearch client
		FlushInterval: 30 * time.Second, // The periodic flush interval
		Human:         true,
		Refresh:       "true",
		Pretty:        true,
	}
	return &b
}
