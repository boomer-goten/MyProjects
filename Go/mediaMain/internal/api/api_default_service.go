package api

import (
	"context"
	"exchange-service/internal/api/model"
	"fmt"
	"net/http"
	"sort"
)

type DefaultAPIService struct{}

func NewDefaultAPIService() DefaultAPIServicer {
	return &DefaultAPIService{}
}

// BannerGet - Получение всех вариантов размена для указанной суммы денег.
func (s *DefaultAPIService) ExchangeGet(ctx context.Context, data model.ExchangeGetRequest) (Response, error) {
	Response := model.ExchangeGetResponse{}
	combination := make([]int, data.Amount)
	mapData := make(map[string]struct{})
	Response.Exchanges = RecursiveExchange(data.Amount, data.Banknotes, Response.Exchanges, 0, combination, mapData)
	return NewResponse(http.StatusOK, Response), nil
}

func RecursiveExchange(amount int, banknots []int, result [][]int, index int, combination []int, mapData map[string]struct{}) [][]int {
	if amount == 0 {
		newCombination := make([]int, index)
		copy(newCombination, combination[:index])
		sort.Slice(newCombination, func(i, j int) bool { return newCombination[i] > newCombination[j] })
		key := fmt.Sprintf("%v", newCombination)
		_, ok := mapData[key]
		if !ok {
			result = append(result, newCombination)
			mapData[key] = struct{}{}
		}
		return result
	}
	for i := 0; i < len(banknots); i++ {
		if amount >= banknots[i] {
			combination[index] = banknots[i]
			result = RecursiveExchange(amount-banknots[i], banknots, result, index+1, combination, mapData)
		}
	}
	return result
}
