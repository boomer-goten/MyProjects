package elastic

import (
	"bytes"
	"context"
	"elasticdb/config/elasticcfg"
	"elasticdb/internal/reader"
	"elasticdb/pkg/model"
	"encoding/json"
	"errors"
	"log"
	"strconv"
	"strings"
	"sync"

	"github.com/elastic/go-elasticsearch/v8"
	"github.com/elastic/go-elasticsearch/v8/esutil"
)

type ElasticDB struct {
	client *elasticsearch.Client
	bi     *esutil.BulkIndexer
}

func NewElasticDefault(cfg *elasticsearch.Config) (*ElasticDB, error) {
	es, err := elasticsearch.NewClient(*cfg)
	if err != nil {
		return nil, err
	}
	bi, err := esutil.NewBulkIndexer(*elasticcfg.NewBulkCfg(elasticcfg.IndexPlace, es))
	return &ElasticDB{es, &bi}, err
}

func (e *ElasticDB) Create() error {
	// // Re-create the index
	if res, err := e.client.Indices.Delete([]string{elasticcfg.IndexPlace}, e.client.Indices.Delete.WithIgnoreUnavailable(true)); err != nil || res.IsError() {
		return err
	}
	resp, err := e.client.Indices.Create(elasticcfg.IndexPlace, e.client.Indices.Create.WithPretty(), e.client.Indices.Create.WithBody(strings.NewReader(elasticcfg.MappingPlace)))
	if err != nil {
		return err
	}
	if resp.IsError() {
		return err
	}
	resp.Body.Close()
	return nil
}

func (e *ElasticDB) Insert(reader reader.Reader) error {
	var wg sync.WaitGroup
	var err error
	for {
		var record *model.Place
		record, err = reader.Read()
		if err != nil {
			break
		}
		var data []byte
		// Prepare the data payload: encode article to JSON
		data, err = json.Marshal(*record)

		if err != nil {
			return err
		}
		// Add an item to the BulkIndexer
		wg.Add(1)
		go e.insertPlace(record.ID, data, &wg)
	}
	wg.Wait()
	e.client.Indices.Refresh(e.client.Indices.Refresh.WithIndex(elasticcfg.IndexPlace))
	return nil
}

func (e *ElasticDB) insertPlace(placeID int, place []byte, wg *sync.WaitGroup) {
	defer wg.Done()
	err := (*e.bi).Add(
		context.Background(),
		esutil.BulkIndexerItem{
			// Action field configures the operation to perform (index, create, delete, update)
			Action: "index",
			// DocumentID is the (optional) document ID
			DocumentID: strconv.Itoa(placeID),
			// Body is an `io.Reader` with the payload
			// Body: bytes.NewReader(data),
			Body: strings.NewReader(string(place)),
			// OnFailure is called for each failed operation
			OnFailure: func(ctx context.Context, item esutil.BulkIndexerItem, res esutil.BulkIndexerResponseItem, err error) {
				if err != nil {
					log.Printf("ERRORFP: %s", err)
				} else {
					log.Printf("ERROR: %s: %s", res.Error.Type, res.Error.Reason)
				}
			},
		},
	)
	if err != nil {
		log.Fatalf("Unexpected error: %s", err)
	}
}

func (e *ElasticDB) Close() error {
	if err := (*e.bi).Close(context.Background()); err != nil {
		return err
	}
	return nil
}

func (e *ElasticDB) GetPlaces(limit int, page int) ([]model.Place, int, error) {
	from := (page - 1) * limit
	query := map[string]interface{}{
		"query": map[string]interface{}{
			"match_all": map[string]interface{}{},
		},
		"search_after": []interface{}{
			from,
		},
		"sort": []map[string]interface{}{
			{"_doc": "asc"},
		},
		"size": limit, // Количество документов на странице
	}
	return e.GetQuery(query)
}

func (e *ElasticDB) GetNearPlaces(limit int, latitude, longitude float64) ([]model.Place, int, error) {
	query := map[string]interface{}{
		"query": map[string]interface{}{
			"match_all": map[string]interface{}{},
		},
		"sort": map[string]interface{}{
			"_geo_distance": map[string]interface{}{
				"location": map[string]interface{}{
					"lat": latitude,
					"lon": longitude,
				},
				"order":           "asc",
				"unit":            "km",
				"mode":            "min",
				"distance_type":   "arc",
				"ignore_unmapped": true,
			},
		},
		"size": limit, // Количество документов на странице
	}
	return e.GetQuery(query)
}

func (e *ElasticDB) GetQuery(q map[string]interface{}) ([]model.Place, int, error) {
	var buf bytes.Buffer
	if err := json.NewEncoder(&buf).Encode(q); err != nil {
		return nil, 0, err
	}
	res, err := e.client.Search(
		e.client.Search.WithContext(context.Background()),
		e.client.Search.WithIndex(elasticcfg.IndexPlace),
		e.client.Search.WithBody(&buf),
		e.client.Search.WithTrackTotalHits(true),
		e.client.Search.WithPretty(),
	)
	if err != nil {
		return nil, 0, err
	}
	defer res.Body.Close()

	var r map[string]interface{}
	if err := json.NewDecoder(res.Body).Decode(&r); err != nil {
		return nil, 0, err
	}
	totalSize := int(r["hits"].(map[string]interface{})["total"].(map[string]interface{})["value"].(float64))
	var places []model.Place

	hits, found := r["hits"].(map[string]interface{})["hits"].([]interface{})
	if !found {
		return nil, 0, errors.New("hits not found in search result")
	}
	for _, hit := range hits {
		source := hit.(map[string]interface{})["_source"]
		place := model.Place{
			ID:      int(source.(map[string]interface{})["id"].(float64)),
			Name:    source.(map[string]interface{})["name"].(string),
			Address: source.(map[string]interface{})["address"].(string),
			Phone:   source.(map[string]interface{})["phone"].(string),
			Location: model.Location{
				Latitude:  source.(map[string]interface{})["location"].(map[string]interface{})["lat"].(float64),
				Longitude: source.(map[string]interface{})["location"].(map[string]interface{})["lon"].(float64),
			},
		}
		places = append(places, place)
	}

	return places, totalSize, err
}
