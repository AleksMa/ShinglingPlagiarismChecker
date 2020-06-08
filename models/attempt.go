package models

import (
	"time"
)

type Attempt struct {
	ID         int64     `json:"-"`
	User       string    `json:"user"`
	Task       string    `json:"task"`
	Time       int64     `json:"time"`
	Memory     int64     `json:"memory"`
	SourceCode string    `json:"sourceCode"`
	UploadDate time.Time `json:"uploadDate"`
}

type AttemptSimplification struct {
	ID         int64     `json:"-"`
	User       string    `json:"user"`
	Task       string    `json:"task"`
	SourceCode string    `json:"sourceCode"`
	UploadDate time.Time `json:"uploadDate"`
}
