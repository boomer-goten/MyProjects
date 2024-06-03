package auth

import (
	"context"
	"errors"
	"graphQL-fakereddit-service/internal/server/middleware"
	"os"
	"strconv"

	"github.com/golang-jwt/jwt"
)

var ErrNoUserInContext = errors.New("no userID in context")

type Auth struct{}

func New() *Auth {
	return &Auth{}
}

func (a *Auth) CreateToken(ID int, Name string) (string, error) {
	claims := jwt.MapClaims{}
	claims["id"] = strconv.Itoa(ID)
	claims["name"] = Name
	token := jwt.NewWithClaims(jwt.SigningMethodHS256, claims)
	return token.SignedString([]byte(os.Getenv("SECRET_KEY")))
}

func (a *Auth) CheckUserID(ctx context.Context) (int, string, error) {
	if ctx.Value(middleware.ContextAuthKey) == nil {
		return -1, "", ErrNoUserInContext
	}
	ID, ok := ctx.Value(middleware.ContextAuthKey).(string)
	if !ok || ID == "" {
		return -1, "", ErrNoUserInContext
	}
	name := ctx.Value(middleware.ContextAuthName).(string)
	IntID, err := strconv.Atoi(ID)
	if err != nil {
		return -1, "", ErrNoUserInContext
	}
	return IntID, name, nil
}
