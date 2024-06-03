package flagparser

import "flag"

type FlagConfig struct {
	Envpath    string
	TypeMemory bool
}

func NewConfig() FlagConfig {
	cfg := FlagConfig{}
	flag.StringVar(&cfg.Envpath, "env", "", "path to env file")
	flag.BoolVar(&cfg.TypeMemory, "type_memory", false, "case false:in_memory, else postgres")
	flag.Parse()
	return cfg
}
