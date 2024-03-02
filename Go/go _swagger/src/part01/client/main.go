package main

import (
	"bytes"
	"crypto/tls"
	"crypto/x509"
	"encoding/json"
	"flag"
	"fmt"
	"io"
	"log"
	"net/http"
	"os"
)

type BuyCandyBody struct {
	CandyCount *int64  `json:"candyCount"`
	CandyType  *string `json:"candyType"`
	Money      *int64  `json:"money"`
}

var money = flag.Int64("m", 0, "money")
var name = flag.String("k", "", "name")
var count = flag.Int64("c", 0, "countCandy")

func main() {
	flag.Parse()
	client := getClient()
	CandyRequest := BuyCandyBody{Money: money, CandyType: name, CandyCount: count}
	url := "https://candy.tld:3333/buy_candy"
	data, err := json.Marshal(CandyRequest)
	if err != nil {
		log.Fatal(err)
	}
	resp, err := client.Post(url, "application/json", bytes.NewBuffer(data))
	if err != nil {
		log.Fatal(err)
	}
	defer resp.Body.Close()
	body, _ := io.ReadAll(resp.Body)
	fmt.Print(string(body))
}

func getClient() *http.Client {
	data, errs := os.ReadFile("../minica.pem")
	if errs != nil {
		log.Fatal(errs)
	}
	cp, _ := x509.SystemCertPool()
	cp.AppendCertsFromPEM(data)
	config := &tls.Config{
		RootCAs: cp,
	}
	client := &http.Client{
		Transport: &http.Transport{
			TLSClientConfig: config,
		},
	}
	return client
}
