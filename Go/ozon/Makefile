.PHONY: run_service_postgres
run_service_postgres:
	@go run ./cmd/graphQL-fakereddit-service/main.go -env=./env/.env -type_memory=true

.PHONY: run_service_in_memory
run_service_in_memory:
	@go run ./cmd/graphQL-fakereddit-service/main.go -env=./env/.env -type_memory=false

.PHONY: run_gqglen
run_gqglen:
	@go get github.com/99designs/gqlgen
	@go run github.com/99designs/gqlgen

.PHONY: compose-build-run
compose-build-run:
	@docker-compose up --build reddit

.PHONY: compose-build
compose-build:
	@docker-compose build reddit

.PHONY: compose-run
compose-run:
	@docker-compose up reddit

.PHONY: compose-down
compose-down:
	@docker-compose down