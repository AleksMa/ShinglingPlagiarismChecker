package swagger

import (
	"testing"

	"github.com/stretchr/testify/suite"
)

const (
	htmlFilename = "index.html"
	cssFilename  = "style.css"
	jsFilename   = "script.js"
	pngFilename  = "image.png"
	yamlFilename = "swagger.yaml"
	goFilename   = "main.go"
)

type UtilsTestSuite struct {
	suite.Suite
}

func (s *UtilsTestSuite) TestCheckHandlerUIPath() {
	testCases := []struct {
		path   string
		result bool
	}{
		{
			path:   htmlFilename,
			result: true,
		},
		{
			path:   cssFilename,
			result: true,
		},
		{
			path:   jsFilename,
			result: true,
		},
		{
			path:   pngFilename,
			result: true,
		},
		{
			path:   yamlFilename,
			result: false,
		},
		{
			path:   goFilename,
			result: false,
		},
	}
	for _, tc := range testCases {
		s.Require().Equal(tc.result, checkHandlerUIPath([]byte(tc.path)), tc.path)
	}
}

func (s *UtilsTestSuite) TestCheckHandlerSchemaPath() {
	testCases := []struct {
		path   string
		result bool
	}{
		{
			path:   htmlFilename,
			result: false,
		},
		{
			path:   cssFilename,
			result: false,
		},
		{
			path:   jsFilename,
			result: false,
		},
		{
			path:   pngFilename,
			result: false,
		},
		{
			path:   yamlFilename,
			result: true,
		},
		{
			path:   goFilename,
			result: false,
		},
	}
	for _, tc := range testCases {
		s.Require().Equal(tc.result, checkHandlerSchemaPath([]byte(tc.path)), tc.path)
	}
}

func TestConsumerTestSuite(t *testing.T) {
	suite.Run(t, new(UtilsTestSuite))
}
