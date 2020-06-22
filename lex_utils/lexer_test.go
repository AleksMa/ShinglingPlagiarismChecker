package lex_utils

import (
	"github.com/stretchr/testify/suite"
	"testing"
)

type LexerTestSuite struct {
	suite.Suite
}

func (s *LexerTestSuite) TestCanonize() {
	testCases := []struct {
		input  string
		result []int
	}{
		{
			input: "int h = atoi(argv[1]);",
			result: []int{
				Keyword,
				Identifier,
				Operator,
				Identifier,
				Separator,
				Identifier,
				Separator,
				Constant,
				Separator,
				Separator,
				Separator,
			},
		},
		{
			input:  "",
			result: []int{},
		},
		{
			input: `  // some comment 
					/* another comment */ int a;
					`,
			result: []int{
				Keyword,
				Identifier,
				Separator,
			},
		},
	}
	for _, tc := range testCases {
		output := Canonize(tc.input)
		s.Require().Equal(tc.result, output)
	}
}

func TestConsumerTestSuite(t *testing.T) {
	suite.Run(t, new(LexerTestSuite))
}
