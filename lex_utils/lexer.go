package lex_utils

import (
	"github.com/AleksMa/StealLovingYou/models"
	"math"
	"strconv"
	"strings"
	"unicode"
)

const (
	shingle_size = 20
	types_count = 4
)

const (
	KEYWORD = iota
	OPERATOR
	IDENTIFIER
	CONSTANT
	VARIABLE_TYPE
	CYCLE
	CONDITION
)

var (
	keywords = []string{
		"auto",
		"break",
		"case",
		"const",
		"char",
		"continue",
		"default",
		"do",

		"double",
		"else",
		"enum",
		"extern",
		"float",
		"for",
		"goto",
		"if",

		"int",
		"long",
		"register",
		"return",
		"short",
		"signed",
		"sizeof",
		"static",

		"struct",
		"switch",
		"typedef",
		"union",
		"unsigned",
		"void",
		"volatile",
		"while",
	}
	keywords_map = make(map[string]struct{})
)

func init() {
	for _, kw := range keywords {
		keywords_map[kw] = struct{}{}
	}
}

func Normalize(source string) string {
	singeComment := false
	multipleComment := false
	var res, subres string
	for i := 0; i < len(source); i++ {
		switch {
		case singeComment && source[i] == '\n':
			singeComment = false
		case i+1 < len(source) && multipleComment && source[i] == '*' && source[i+1] == '/':
			multipleComment = false
			i++
		case singeComment || multipleComment:
			continue
		case i+1 < len(source) && source[i] == '/' && source[i+1] == '*':
			multipleComment = true
			i++
		case i+1 < len(source) && source[i] == '/' && source[i+1] == '/':
			singeComment = true
			i++
		default:
			subres += string(source[i])
		}
	}

	for j := 0; j < len(subres); j++ {
		if subres[j] == '\n' || subres[j] == '\r' || subres[j] == '\t' {
			res += " "
		} else {
			res += string(subres[j])
		}
	}

	subres = res
	res = ""

	for j := 0; j < len(subres); j++ {
		if subres[j] == ' ' {
			for j < len(subres) && subres[j] == ' ' {
				j++
			}
			j--
			res += " "
		} else {
			res += strings.ToLower(string(subres[j]))
		}
	}

	return res
}

func Lex(source string) []int {
	var tokens []int
	for i := 0; i < len(source); i++ {
		r := rune(source[i])
		if r == '"' {
			i++
			for i < len(source) && source[i] != '"' {
				i++
			}
			tokens = append(tokens, CONSTANT)
		} else if r == '\'' {
			i++
			for i < len(source) && source[i] != '\'' {
				i++
			}
			tokens = append(tokens, CONSTANT)
		} else if unicode.IsDigit(r) {
			for i < len(source) && unicode.IsDigit(rune(source[i])) {
				i++
			}
			i--
			tokens = append(tokens, CONSTANT)
		} else if unicode.IsLetter(r) {
			j := i
			for i < len(source) && (unicode.IsDigit(rune(source[i])) || unicode.IsLetter(rune(source[i]))) {
				i++
			}
			substr := source[j:i]
			if _, ok := keywords_map[substr]; ok {
				tokens = append(tokens, KEYWORD)
			} else {
				tokens = append(tokens, IDENTIFIER)
			}
			i--
		} else {
			if !unicode.IsSpace(r) {
				tokens = append(tokens, OPERATOR)
			}
		}
	}
	return tokens
}

func Split(tokens []int) models.HashSet {
	shingles := make(models.HashSet)

	var s_shingles []string
	for i := 0; i < len(tokens) -shingle_size; i++ {
		num_shingle := tokens[i:i+shingle_size]
		shingle := ""
		for _, r := range num_shingle {
			shingle += strconv.Itoa(r)
		}
		s_shingles = append(s_shingles, shingle)
	}

	for _, s_shingle := range s_shingles {
		var shingle models.Hash = 0
		for j := shingle_size - 1; j >= 0; j-- {
			shingle += models.Hash(s_shingle[j]) * models.Hash(math.Pow(types_count, float64(shingle_size-j-1)))
		}
		shingles[shingle] = struct{}{}
	}

	return shingles
}

func FullAnalize(source string) models.HashSet {
	return Split(Lex(Normalize(source)))
}
