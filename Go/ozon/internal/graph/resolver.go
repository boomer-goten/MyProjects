package graph

// This file will not be regenerated automatically.
//
// It serves as dependency injection for your app, add any dependencies you require here.
import (
	"graphQL-fakereddit-service/internal/auth"
	"graphQL-fakereddit-service/internal/storage"
)

type Resolver struct {
	Storage storage.Storage
	Auth    *auth.Auth
}
