package models

const BorrowingThreshold int8 = 60

type Borrowing struct {
	AttemptID  uint64
	CopiedFrom uint64
	Percent    int8
}
