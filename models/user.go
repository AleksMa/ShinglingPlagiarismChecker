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

type Users []*User

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
	nicknameRegexp *regexp.Regexp
	emailRegexp    *regexp.Regexp
)

func init() {
	var err error
	nicknameRegexp, err = regexp.Compile(`^[a-zA-Z0-9_.]+$`)
	if err != nil {
		log.Fatalf("nickname regexp err: %s", err.Error())
	}

	emailRegexp, err = regexp.Compile("^[a-zA-Z0-9.!#$%&''*+/=?^_`" + `{|}~-]+@[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?(?:\.[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?)+$`)
	if err != nil {
		log.Fatalf("email regexp err: %s", err.Error())
	}
}

func (u *User) Validate() *Error {
	if !(nicknameRegexp.MatchString(u.UserName) &&
		u.FullName != "") {
		return NewError(http.StatusBadRequest, "validation failed")
	}

	return nil
}
