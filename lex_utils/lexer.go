package lex_utils

import (
	"fmt"
	"github.com/AleksMa/StealLovingYou/models"
	"math"
	"strconv"
	"strings"
	"unicode"
)

const (
	shingle_size = 15
	types_count = Separator + 1
)

const (
	Identifier = iota
	Keyword
	Constant
	StringLiteral
	Operator
	Separator
)

var (
	names map[int]string
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

	names = make(map[int]string)
	names[Identifier] = "Identifier"
	names[Keyword] = "Keyword"
	names[Constant] = "Constant"
	names[StringLiteral] = "StringLiteral"
	names[Operator] = "Operator"
	names[Separator] = "Separator"

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
	tokens := []int{}
	for i := 0; i < len(source); i++ {
		r := rune(source[i])
		if r == '"' {
			i++
			for i < len(source) && source[i] != '"' {
				i++
			}
			tokens = append(tokens, StringLiteral)
		} else if r == '\'' {
			i++
			for i < len(source) && source[i] != '\'' {
				i++
			}
			tokens = append(tokens, Constant)
		} else if unicode.IsDigit(r) {
			for i < len(source) && unicode.IsDigit(rune(source[i])) {
				i++
			}
			i--
			tokens = append(tokens, Constant)
		} else if unicode.IsLetter(r) {
			j := i
			for i < len(source) && (unicode.IsDigit(rune(source[i])) || unicode.IsLetter(rune(source[i]))) {
				i++
			}
			substr := source[j:i]
			if _, ok := keywords_map[substr]; ok {
				tokens = append(tokens, Keyword)
			} else {
				tokens = append(tokens, Identifier)
			}
			i--
		} else if r == ';' || r == ',' || r == '(' || r == ')' || r == '[' || r == ']' || r == '{' || r == '}' {
			tokens = append(tokens, Separator)
		} else {
			if !unicode.IsSpace(r) {
				tokens = append(tokens, Operator)
			}
		}
	}
	return tokens
}

func Canonize(source string) []int {
	return Lex(Normalize(source))
}

func Split(tokens []int) models.HashSet {
	shingles := make(models.HashSet)


	fmt.Print("[")
	for i, t := range tokens {
		fmt.Print(t)
		if i != len(tokens) - 1 {
			fmt.Print(", ")
		}
	}
	fmt.Print("]")

	var s_shingles []string
	var i_shingles [][]int
	for i := 0; i < len(tokens) -shingle_size; i++ {
		num_shingle := tokens[i:i+shingle_size]
		i_shingles = append(i_shingles, num_shingle)
		//fmt.Println(num_shingle)
		fmt.Print("[")
		for i, t := range num_shingle {
			fmt.Print(t)
			if i != len(num_shingle) - 1 {
				fmt.Print(", ")
			}
		}
		fmt.Println("]")
		shingle := ""
		for _, r := range num_shingle {
			shingle += strconv.Itoa(r)
		}
		s_shingles = append(s_shingles, shingle)
		//fmt.Println(shingle)
	}

	for _, i_shingle := range i_shingles {
		var shingle models.Hash = 0
		for j := shingle_size - 1; j >= 0; j-- {
			shingle += models.Hash(i_shingle[j]) * models.Hash(math.Pow(types_count, float64(shingle_size-j-1)))
		}
		shingles[shingle] = struct{}{}
		fmt.Println(shingle)
		//fmt.Println(models.Hash(math.Pow(types_count, float64(shingle_size-1))))
	}

	return shingles
}

func FullAnalise(source string) models.HashSet {
	return Split(Canonize(source))
}
