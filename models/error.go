package models

type Error struct {
	Code    int    `json:"-"`
	Message string `json:"message"`
}

func NewError(code int, msg string) *Error {
	return &Error{
		Code:    code,
		Message: msg,
	}
}

func (err Error) Error() string {
	return err.Message
}
