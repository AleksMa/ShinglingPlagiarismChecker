package models

import (
	"time"
)

type Result struct {
	ID                uint64                    `json:"-"`
	User              string                   `json:"user"`
	Task              string                   `json:"task"`
	UploadDate        time.Time                `json:"uploadDate"`
	SourceCode        string                   `json:"sourceCode"`
	Status            int8                     `json:"status"`
	PlagiarismPercent int8                     `json:"status"`
	CopiedFrom        []*AttemptSimplification `json:"copiedFrom"`
}
