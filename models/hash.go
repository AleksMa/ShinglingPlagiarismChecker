package models

type Hash int64
type HashSet map[Hash]struct{}
type HashObject struct {
	ID      uint64
	Set *HashSet
}
