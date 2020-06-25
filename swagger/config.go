package swagger

import (
	"os"
	"path/filepath"
)

// Config is a struct with main swagger attributes
type Config struct {
	SchemaPath     string `toml:"schema-path"`
	UIPath         string `toml:"ui-path"`
	SchemaFilename string `toml:"schema-filename"`
	IndexFilename  string `toml:"index-filename"`
	Body           []byte
}

// NewConfig creates a new instance of Config with path options
func NewConfig() *Config {
	swaggerConfig := &Config{
		SchemaFilename: "swagger.yaml",
		IndexFilename:  "index.html",
	}
	return swaggerConfig
}

func (sw *Config) checkSchemaPath() bool {
	_, err := os.Stat(filepath.Join(sw.SchemaPath, sw.SchemaFilename))
	return err == nil
}

func (sw *Config) checkUIPath() bool {
	_, err := os.Stat(filepath.Join(sw.UIPath, sw.IndexFilename))
	return err == nil
}

// IsValid checks if paths are set correctly
func (sw *Config) IsValid() bool {
	return sw.checkSchemaPath() && sw.checkUIPath()
}

// IsEnabled checks if index.html was downloaded in Init
func (sw *Config) IsEnabled() bool {
	return len(sw.Body) > 0
}
