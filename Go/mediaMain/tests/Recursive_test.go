package tests

import (
	"exchange-service/internal/api"
	"exchange-service/internal/api/model"
	"testing"
)

func TestRecursiveExchangeFirst(t *testing.T) {
	data := model.ExchangeGetRequest{Amount: 10, Banknotes: []int{5, 2, 1}}
	res := model.ExchangeGetResponse{Exchanges: [][]int{}}
	combination := make([]int, data.Amount)
	uniqueCombination := make(map[string]struct{})
	expectedResult := [][]int{
		{5, 5},
		{5, 2, 2, 1},
		{5, 2, 1, 1, 1},
		{5, 1, 1, 1, 1, 1},
		{2, 2, 2, 2, 2},
		{2, 2, 2, 2, 1, 1},
		{2, 2, 2, 1, 1, 1, 1},
		{2, 2, 1, 1, 1, 1, 1, 1},
		{2, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	}

	res.Exchanges = api.RecursiveExchange(data.Amount, data.Banknotes, res.Exchanges, 0, combination, uniqueCombination)
	flag := true
	for i, value := range res.Exchanges {
		for j := range value {
			if value[j] != expectedResult[i][j] {
				flag = false
			}
		}
	}
	if flag == false {
		t.Error("Incorrect result")
	}
}

func TestRecursiveExchangeSecond(t *testing.T) {
	data := model.ExchangeGetRequest{Amount: 400, Banknotes: []int{5000, 2000, 1000, 500, 200, 100, 50}}
	res := model.ExchangeGetResponse{Exchanges: [][]int{}}
	combination := make([]int, data.Amount)
	uniqueCombination := make(map[string]struct{})
	expectedResult := [][]int{
		{200, 200},
		{200, 100, 100},
		{200, 100, 50, 50},
		{200, 50, 50, 50, 50},
		{100, 100, 100, 100},
		{100, 100, 100, 50, 50},
		{100, 100, 50, 50, 50, 50},
		{100, 50, 50, 50, 50, 50, 50},
		{50, 50, 50, 50, 50, 50, 50, 50},
	}

	res.Exchanges = api.RecursiveExchange(data.Amount, data.Banknotes, res.Exchanges, 0, combination, uniqueCombination)
	flag := true
	for i, value := range res.Exchanges {
		for j := range value {
			if value[j] != expectedResult[i][j] {
				flag = false
			}
		}
	}
	if flag == false {
		t.Error("Incorrect result")
	}
}

func TestRecursiveExchangeThird(t *testing.T) {
	data := model.ExchangeGetRequest{Amount: 400, Banknotes: []int{5000, 2000, 1000, 500}}
	res := model.ExchangeGetResponse{Exchanges: [][]int{}}
	combination := make([]int, data.Amount)
	uniqueCombination := make(map[string]struct{})
	expectedResult := [][]int{}

	res.Exchanges = api.RecursiveExchange(data.Amount, data.Banknotes, res.Exchanges, 0, combination, uniqueCombination)
	flag := true
	for i, value := range res.Exchanges {
		for j := range value {
			if value[j] != expectedResult[i][j] {
				flag = false
			}
		}
	}
	if flag == false {
		t.Error("Incorrect result")
	}
}

func TestRecursiveExchangeFourth(t *testing.T) {
	data := model.ExchangeGetRequest{Amount: 200, Banknotes: []int{5000, 2000, 1000, 500, 200, 100, 50}}
	res := model.ExchangeGetResponse{Exchanges: [][]int{}}
	combination := make([]int, data.Amount)
	uniqueCombination := make(map[string]struct{})
	expectedResult := [][]int{
		{200},
		{100, 100},
		{100, 50, 50},
		{50, 50, 50, 50},
	}

	res.Exchanges = api.RecursiveExchange(data.Amount, data.Banknotes, res.Exchanges, 0, combination, uniqueCombination)
	flag := true
	for i, value := range res.Exchanges {
		for j := range value {
			if value[j] != expectedResult[i][j] {
				flag = false
			}
		}
	}
	if flag == false {
		t.Error("Incorrect result")
	}
}

func TestRecursiveExchangeFifth(t *testing.T) {
	data := model.ExchangeGetRequest{Amount: 100, Banknotes: []int{100, 50, 10}}
	res := model.ExchangeGetResponse{Exchanges: [][]int{}}
	combination := make([]int, data.Amount)
	uniqueCombination := make(map[string]struct{})
	expectedResult := [][]int{
		{100},
		{50, 50},
		{50, 10, 10, 10, 10, 10},
		{10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
	}
	res.Exchanges = api.RecursiveExchange(data.Amount, data.Banknotes, res.Exchanges, 0, combination, uniqueCombination)
	flag := true
	for i, value := range res.Exchanges {
		for j := range value {
			if value[j] != expectedResult[i][j] {
				flag = false
			}
		}
	}
	if flag == false {
		t.Error("Incorrect result")
	}
}
