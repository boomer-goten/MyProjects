package server

import (
	"context"
	"net/http"
	"os"

	"github.com/gorilla/mux"
)

type App struct {
	HTTPServer *http.Server
}

func New(router *mux.Router) *App {
	// timeout, _ := time.ParseDuration(os.Getenv("SERVER_TIMEOUT"))
	// idleTimeout, _ := time.ParseDuration(os.Getenv("SERVER_IDLECON"))
	server := &http.Server{
		Addr: os.Getenv("HOST"),
		// IdleTimeout:  idleTimeout,
		// ReadTimeout:  timeout,
		// WriteTimeout: timeout,
		Handler: router,
	}
	return &App{HTTPServer: server}
}

func (a *App) Run() {
	a.HTTPServer.ListenAndServe()
}

func (a *App) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	a.HTTPServer.Handler.ServeHTTP(w, r)
}

func (a *App) GracefullStop() error {
	return a.HTTPServer.Shutdown(context.Background())
}
