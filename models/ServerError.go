package models

import (
	"encoding/json"
	"fmt"
)

type ServerError struct {
	Cause  error
	Detail string
	Status int
}

func (e ServerError) Error() string {
	if e.Cause == nil {
		return e.Detail
	}
	return e.Detail + " : " + e.Cause.Error()
}

func (e ServerError) ResponseBody() ([]byte, error) {
	body, err := json.Marshal(e)
	if err != nil {
		return nil, fmt.Errorf("error while parsing response body: %v", err)
	}
	return body, nil
}

func (e ServerError) ResponseHeaders() (int, map[string]string) {
	return e.Status, map[string]string{
		"Content-Type": "application/json; charset=utf-8",
	}
}

func NewServerError(err error, status int, detail string) ServerError {
	return ServerError{
		Cause:  err,
		Detail: detail,
		Status: status,
	}
}
