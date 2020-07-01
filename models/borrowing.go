package models

const BorrowingThreshold int8 = 20

type Borrowing struct {
	AttemptID  uint64
	CopiedFrom uint64
	Percent    int8
}
