package server

import (
	"encoding/json"
	"html/template"
	"log"
	"net/http"
	"server-elasticdb/internal/store"
	"server-elasticdb/web/templ"
	"strconv"
	"strings"

	"github.com/golang-jwt/jwt"
)

var hmacSampleSecret []byte = []byte("boomer")

const limit = 10

func RunServer(db store.Store) {
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		pageStr := r.URL.Query().Get("page")
		page, err := strconv.Atoi(pageStr)
		if err != nil || page < 0 {
			http.Error(w, "Invalid 'page' value: not valid page", http.StatusBadRequest)
		} else {
			html, err := template.ParseFiles("../../web/templ/template.html")
			if err != nil {
				log.Fatal(err)
			}
			places, total, err := db.GetPlaces(limit, page+1)
			if err != nil {
				http.Error(w, "error to connect database", http.StatusInternalServerError)
			}
			templ := templ.Template{Total: total, Previous: page - 1, Next: page + 1, Last: total / limit, Places: places}
			if page > templ.Last {
				http.Error(w, "Invalid 'page' value: this page does not exist", http.StatusBadRequest)
			} else {
				err = html.Execute(w, templ)
				if err != nil {
					http.Error(w, "error to load this page", http.StatusInternalServerError)
				}
			}
		}
	})
	http.HandleFunc("/api/places", func(w http.ResponseWriter, r *http.Request) {
		pageStr := r.URL.Query().Get("page")
		page, err := strconv.Atoi(pageStr)
		if err != nil || page < 0 {
			http.Error(w, "{\n\tInvalid 'page' value: not valid page\n}", http.StatusBadRequest)
		} else {
			places, total, err := db.GetPlaces(limit, page+1)
			if err != nil {
				http.Error(w, "error to connect database", http.StatusInternalServerError)
			}
			templ := templ.JSONTempl{"Places", templ.Template{total, places, page - 1, page + 1, total / limit}}
			if page > templ.Last {
				http.Error(w, "{\n\tInvalid 'page' value: this page does not exist\n}", http.StatusBadRequest)
			} else {
				jsonData, err := json.MarshalIndent(templ, "", " ")
				if err != nil {
					http.Error(w, "{\n\terror to load this page\n}", http.StatusInternalServerError)
					return
				}
				w.Header().Set("Content-Type", "application/json")
				w.Write(jsonData)
			}
		}
	})

	funct := func(w http.ResponseWriter, r *http.Request) {
		latStr := r.URL.Query().Get("lat")
		lat, errlat := strconv.ParseFloat(latStr, 64)
		lonStr := r.URL.Query().Get("lon")
		lon, err := strconv.ParseFloat(lonStr, 64)
		if errlat != nil || err != nil || lat < 0 || lon < 0 || lat > 180 || lon > 90 {
			http.Error(w, "{\n\tInvalid 'page' coordinates\n}", http.StatusBadRequest)
		} else {
			places, _, err := db.GetNearPlaces(3, lat, lon)
			if err != nil {
				http.Error(w, "error to connect database", http.StatusInternalServerError)
			}
			rec := templ.Recommend{"Recommendation", places}
			jsonData, err := json.MarshalIndent(rec, "", " ")
			if err != nil {
				http.Error(w, "{\n\terror to load this page\n}", http.StatusInternalServerError)
				return
			}
			w.Header().Set("Content-Type", "application/json")
			w.Write(jsonData)
		}
	}

	http.HandleFunc("/api/recommend", http.HandlerFunc(authMiddleware(funct)))

	http.HandleFunc("/api/get_token", func(w http.ResponseWriter, r *http.Request) {
		token := jwt.NewWithClaims(jwt.SigningMethodHS256, jwt.MapClaims{
			"name": "boomergo",
		})
		var t templ.Tokenize
		var err error
		t.JWTToken, err = token.SignedString(hmacSampleSecret)
		if err != nil {
			log.Fatal(err)
		}
		jsonData, err := json.MarshalIndent(t, "", "    ")
		if err != nil {
			http.Error(w, "{\n\terror to load this page\n}", http.StatusInternalServerError)
			return
		}
		w.Header().Set("Content-Type", "application/json")
		w.Header().Set("Authorization", t.JWTToken)
		w.Write(jsonData)
	})
	log.Fatal(http.ListenAndServe(":8888", nil))
}

func authMiddleware(next http.HandlerFunc) http.HandlerFunc {
	return http.HandlerFunc(func(w http.ResponseWriter, r *http.Request) {
		tokenString := r.Header.Get("Authorization")
		if tokenString == "" {
			http.Error(w, "Unauthorized", http.StatusUnauthorized)
			return
		}
		headerParts := strings.Split(tokenString, " ")
		if len(headerParts) != 2 {
			http.Error(w, "Unauthorized", http.StatusUnauthorized)
			return
		}
		token, err := jwt.Parse(headerParts[1], func(token *jwt.Token) (interface{}, error) {
			return hmacSampleSecret, nil
		})
		if err != nil || !token.Valid {
			http.Error(w, "Unauthorized", http.StatusUnauthorized)
			return
		}
		next.ServeHTTP(w, r)
	})
}
