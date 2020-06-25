package swagger

import (
	"bytes"
	"io/ioutil"
	"path/filepath"
)

// CheckHandlerUIPath checks if request gets swagger UI files
func CheckHandlerUIPath(path []byte) bool {
	return bytes.HasSuffix(path, []byte("css")) ||
		bytes.HasSuffix(path, []byte("js")) ||
		bytes.HasSuffix(path, []byte("html")) ||
		bytes.HasSuffix(path, []byte("png"))
}

// CheckHandlerSchemaPath checks if request gets swagger yaml schema
func CheckHandlerSchemaPath(path []byte) bool {
	return bytes.HasSuffix(path, []byte("yaml"))
}

// CreateHandler creates handler function for http.go
//func CreateHandler(swaggerConfig *Config) func(ctx *fasthttp.RequestCtx) {
//	return func(ctx *fasthttp.RequestCtx) {
//		path := ctx.Path()
//		if checkHandlerUIPath(path) {
//			fasthttp.FSHandler(swaggerConfig.UIPath, 2)(ctx)
//			return
//		}
//		if checkHandlerSchemaPath(path) {
//			fasthttp.FSHandler(swaggerConfig.SchemaPath, 2)(ctx)
//			return
//		}
//		// bytes.Replace returns a *copy* of the slice s with the first n non-overlapping instances of old replaced by new
//		body := bytes.Replace(swaggerConfig.Body, []byte("%EXTERNAL_NAME%"), append([]byte("http://"), ctx.Host()...), 1)
//		ctx.Response.Header.Set("Content-Type", "text/html")
//		if _, err := ctx.Write(body); err != nil {
//			sentry.CaptureException(err)
//			ctx.Error("response write error", fasthttp.StatusInternalServerError)
//		}
//	}
//}

// Init defines SwaggerConfig paths in http.go
func Init(swaggerConfig *Config) error {
	body, err := ioutil.ReadFile(filepath.Join(swaggerConfig.UIPath, swaggerConfig.IndexFilename))
	if err != nil {
		return err
	}
	swaggerConfig.Body = body
	return nil
}
