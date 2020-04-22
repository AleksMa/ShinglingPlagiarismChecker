package models

type Forum struct {
	ID      int64  `json:"-"`
	Slug    string `json:"slug"`
	Title   string `json:"title"`
	Posts   int64  `json:"posts"`
	Threads int32  `json:"threads"`
	Owner   string `json:"user"`
	OwnerID int64  `json:"-"`
}
