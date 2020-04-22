package models

import "time"

type Post struct {
	Author   string    `json:"author"`
	Created  time.Time `json:"created"`
	Forum    string    `json:"forum"`
	ID       int64     `json:"id"`
	IsEdited bool      `json:"isEdited"`
	Message  string    `json:"message"`
	Parent   int64     `json:"parent"`
	Thread   int64     `json:"thread"`
	ForumID  int64     `json:"-"`
	AuthorID int64     `json:"-"`
}

type PostFull struct {
	Author *User   `json:"author"`
	Forum  *Forum  `json:"forum"`
	Post   *Post   `json:"post"`
	Thread *Thread `json:"thread"`
}

type PostParams struct {
	Limit int
	Since int
	Desc  bool
	Sort  int
}

type Posts []*Post

const (
	Flat = iota
	Tree
	ParentTree
)
