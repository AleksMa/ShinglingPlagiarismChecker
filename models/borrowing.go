package models

const BorrowingThreshold int8 = 0

type Borrowing struct {
	AttemptID  uint64
	CopiedFrom uint64
	Percent    int8
}
