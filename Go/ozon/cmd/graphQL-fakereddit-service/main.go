package main

import (
	"graphQL-fakereddit-service/internal/auth"
	"graphQL-fakereddit-service/internal/env"
	"graphQL-fakereddit-service/internal/flagparser"
	"graphQL-fakereddit-service/internal/graph"
	"graphQL-fakereddit-service/internal/graph/gen"
	"graphQL-fakereddit-service/internal/server"
	"graphQL-fakereddit-service/internal/server/middleware"
	"graphQL-fakereddit-service/internal/storage"
	inmemory "graphQL-fakereddit-service/internal/storage/inMemory"
	"graphQL-fakereddit-service/internal/storage/postgres"
	"log"
	"os"
	"os/signal"
	"syscall"

	"github.com/99designs/gqlgen/graphql/handler"
	"github.com/99designs/gqlgen/graphql/playground"
	"github.com/gorilla/mux"
)

func main() {
	flags := flagparser.NewConfig()
	env.LoadEnv(flags.Envpath)
	var database storage.Storage
	if flags.TypeMemory {
		database = postgres.New()
	} else {
		database = inmemory.New()
	}
	defer database.Stop()
	Auth := auth.New()

	router := mux.NewRouter()

	srv := handler.NewDefaultServer(gen.NewExecutableSchema(gen.Config{Resolvers: &graph.Resolver{Storage: database, Auth: Auth}}))
	router.Use(middleware.AuthMiddleware)
	router.HandleFunc("/", playground.Handler("GraphQL playground", "/query"))
	router.Handle("/query", srv)

	server := server.New(router)

	go server.Run()
	stop := make(chan os.Signal, 1)
	signal.Notify(stop, syscall.SIGTERM, syscall.SIGINT)
	<-stop

	if err := server.GracefullStop(); err != nil {
		log.Printf("Failed to gracefull shutdown server address %v", server.HTTPServer.Addr)
	} else {
		log.Printf("Gracefull stopping server address %v", server.HTTPServer.Addr)
	}
}
