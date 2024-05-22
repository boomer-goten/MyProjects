package logger

import (
	"log/slog"
	"os"
)

func SetupLogger() *slog.Logger {
	var log slog.Logger
	logData, err := os.OpenFile(os.Getenv("LOG_PATH"), os.O_RDWR|os.O_APPEND, 0644)
	if err != nil {
		panic("could not open log file" + err.Error())
	}
	level := os.Getenv("LEVEL_LOG")
	switch level {
	case "INFO":
		log = *slog.New(slog.NewTextHandler(logData, &slog.HandlerOptions{AddSource: false, Level: slog.LevelInfo}))
	case "DEBUG":
		log = *slog.New(slog.NewTextHandler(logData, &slog.HandlerOptions{AddSource: false, Level: slog.LevelDebug}))
	case "ERROR":
		log = *slog.New(slog.NewTextHandler(logData, &slog.HandlerOptions{AddSource: false, Level: slog.LevelError}))
	case "WARN":
		log = *slog.New(slog.NewTextHandler(logData, &slog.HandlerOptions{AddSource: false, Level: slog.LevelWarn}))
	}
	return &log
}
