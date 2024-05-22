package main

import (
	"exchange-service/app"
	"exchange-service/internal/api"
	"exchange-service/internal/env"
	"exchange-service/internal/logger"
	"os"
	"os/signal"
	"syscall"
)

func main() {
	env.LoadEnv()
	logger := logger.SetupLogger()
	DefaultAPIService := api.NewDefaultAPIService()
	DefaultAPIController := api.NewDefaultAPIController(DefaultAPIService)
	router := api.NewRouter(logger, DefaultAPIController)
	server := app.New(logger, router)
	go server.Run()
	stop := make(chan os.Signal, 1)
	signal.Notify(stop, syscall.SIGTERM, syscall.SIGINT)
	<-stop
	server.GracefullStop()
}
