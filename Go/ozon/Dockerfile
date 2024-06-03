FROM golang:latest

ENV GOPATH=/

COPY ./ ./

# install psql
RUN apt-get update
RUN apt-get -y install postgresql-client
RUN chmod +x wait.sh

# build service
RUN go mod download
RUN go build -o reddit ./cmd/graphQL-fakereddit-service/main.go 

CMD ["./reddit"]
