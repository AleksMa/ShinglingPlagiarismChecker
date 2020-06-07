package models

import (
	"net/http"
)

type Task struct {
	ID        int64  `json:"-"`
	TaskName  string `json:"username"`
	FullName  string `json:"fullname"`
	MaxTime   int64  `json:"maxtime"`
	MaxMemory int64  `json:"maxmemory"`
}

func (t *Task) Validate() *Error {
	if !nameRegexp.MatchString(t.TaskName) || t.FullName == "" {
		return NewError(http.StatusBadRequest, "validation failed")
	}
	return nil
}
