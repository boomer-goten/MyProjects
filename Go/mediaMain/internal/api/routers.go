package api

import (
	"encoding/json"
	"io"
	"log/slog"
	"net/http"
	"os"

	"exchange-service/internal/api/middleware/logger"

	"github.com/gorilla/mux"
)

type Route struct {
	Method      string
	Pattern     string
	HandlerFunc http.HandlerFunc
}

type Routes map[string]Route

type Router interface {
	Routes() Routes
}

func NewRouter(log *slog.Logger, routers ...Router) *mux.Router {
	router := mux.NewRouter().StrictSlash(true)
	router.Use(logger.LoggerMiddleware(log))
	for _, api := range routers {
		for name, route := range api.Routes() {
			handler := route.HandlerFunc
			router.
				Methods(route.Method).
				Path(route.Pattern).
				Name(name).
				Handler(handler)
		}
	}

	return router
}

func EncodeJSONResponse(i interface{}, status *int, w http.ResponseWriter) error {
	wHeader := w.Header()
	f, ok := i.(*os.File)
	if ok {
		data, err := io.ReadAll(f)
		if err != nil {
			return err
		}
		wHeader.Set("Content-Type", http.DetectContentType(data))
		if status != nil {
			w.WriteHeader(*status)
		} else {
			w.WriteHeader(http.StatusOK)
		}
		_, err = w.Write(data)
		return err
	}
	wHeader.Set("Content-Type", "application/json; charset=UTF-8")
	if status != nil {
		w.WriteHeader(*status)
	} else {
		w.WriteHeader(http.StatusOK)
	}
	if i != nil {
		return json.NewEncoder(w).Encode(i)
	}
	return nil
}
