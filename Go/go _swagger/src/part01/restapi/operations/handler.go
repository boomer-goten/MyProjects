package operations

/*
#include <stdlib.h>
#include "../../internal/external_c/cow.c"
*/
import "C"
import (
	"fmt"
	"unsafe"

	"github.com/go-openapi/runtime/middleware"
)

type Candy struct {
	Candys map[string]int64
}

func DefaultCandys() *Candy {
	candyMap := make(map[string]int64)
	candyMap["CE"] = 10
	candyMap["AA"] = 15
	candyMap["NT"] = 17
	candyMap["DE"] = 21
	candyMap["YR"] = 23
	return &Candy{candyMap}
}

func (e *Candy) Handle(params BuyCandyParams) middleware.Responder {
	value, ok := e.Candys[*params.Order.CandyType]
	if !ok {
		return &BuyCandyBadRequest{&BuyCandyBadRequestBody{"Простите извините такой конфеты в ассортименте нет"}}
	}
	if *params.Order.Money < 0 || *params.Order.CandyCount < 0 {
		return &BuyCandyBadRequest{&BuyCandyBadRequestBody{"Ха вы пытаетесь меня обмануть, отрицательных денег или количества конфет не существует"}}
	}
	total := value * (*params.Order.CandyCount)
	if total <= *params.Order.Money {
		phrase := "Thank you"
		cPhrase := C.CString(phrase)
		defer C.free(unsafe.Pointer(cPhrase))
		result := C.ask_cow(cPhrase)
		defer C.free(unsafe.Pointer(result))
		return &BuyCandyCreated{&BuyCandyCreatedBody{(*params.Order.Money - total), C.GoString(result)}}
	}
	return &BuyCandyPaymentRequired{&BuyCandyPaymentRequiredBody{fmt.Sprintf("Вам нужно больше денег на %#v!", total-*params.Order.Money)}}
}
