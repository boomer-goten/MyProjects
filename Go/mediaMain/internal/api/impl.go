package api

// Результат запросы в виде кода ответа и тела ответа
type Response struct {
	Code int
	Body interface{}
}

func NewResponse(code int, body interface{}) Response {
	return Response{
		Code: code,
		Body: body,
	}
}
