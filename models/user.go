package models

import (
	"log"
	"net/http"
	"regexp"
)

type User struct {
	ID        int64  `json:"-"`
	UserName  string `json:"username"`
	FullName  string `json:"fullname"`
	StudentID string `json:"studentid"`
}

type UserParams struct {
	Limit int
	Since string
	Desc  bool
}

type UpdateUserFields struct {
	About    *string `json:"about"`
	Email    *string `json:"email"`
	Fullname *string `json:"fullname"`
}

var (
	nameRegexp *regexp.Regexp
)

func init() {
	var err error
	nameRegexp, err = regexp.Compile(`^[a-zA-Z0-9_.]+$`)
	if err != nil {
		log.Fatalf("nickname regexp err: %s", err.Error())
	}
}

func (u *User) Validate() *Error {
	if !nameRegexp.MatchString(u.UserName) || u.FullName == "" {
		return NewError(http.StatusBadRequest, "validation failed")
	}
	return nil
}
