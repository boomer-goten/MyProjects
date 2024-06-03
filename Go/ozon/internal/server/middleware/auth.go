package middleware

import (
	"context"
	"fmt"
	"net/http"
	"os"

	"github.com/golang-jwt/jwt"
)

type ContextKey string

func (c ContextKey) String() string {
	return string(c)
}

var ContextAuthKey = ContextKey("id")
var ContextAuthName = ContextKey("name")

func AuthMiddleware(next http.Handler) http.Handler {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		tokenParam := r.Header.Get("token")
		token, err := parse(tokenParam)
		if err != nil {
			next.ServeHTTP(w, r)
			return
		}
		claims, ok := token.Claims.(jwt.MapClaims)
		if !ok || !token.Valid {
			next.ServeHTTP(w, r)
			return
		}
		id, ok := claims["id"].(string)
		name := claims["name"].(string)
		if !ok {
			next.ServeHTTP(w, r)
			return
		}
		ctx := context.WithValue(r.Context(), ContextAuthKey, id)
		ctx = context.WithValue(ctx, ContextAuthName, name)
		next.ServeHTTP(w, r.WithContext(ctx))
	})
}

func parse(tokenParam string) (*jwt.Token, error) {
	return jwt.Parse(tokenParam, func(token *jwt.Token) (interface{}, error) {
		if _, ok := token.Method.(*jwt.SigningMethodHMAC); !ok {
			return nil, fmt.Errorf("unexpected signing method")
		}
		return []byte(os.Getenv("SECRET_KEY")), nil
	})
}
