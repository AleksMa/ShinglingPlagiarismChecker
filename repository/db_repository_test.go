package repository

import (
	"context"
	"github.com/AleksMa/StealLovingYou/models"
	"github.com/DATA-DOG/go-sqlmock"
	"reflect"
	"testing"
)

func TestDBUserStore_GetUsers_Successful(t *testing.T) {
	db, mock, err := sqlmock.New()
	if err != nil {
		t.Fatalf("cant create mock: %s", err)
	}
	defer db.Close()

	var userID int64 = 1

	rows := sqlmock.
		NewRows([]string{"id", "username", "fullname", "studentid"})
	expect := []models.User{
		{userID, "john42", "John Smith", "42"},
	}
	for _, item := range expect {
		rows = rows.AddRow(item.ID, item.UserName, item.FullName, item.StudentID)
	}

	repo := NewDBStore(db, context.Background())

	mock.
		ExpectQuery("SELECT id, username, email, name, password, status, phone FROM users WHERE").
		WithArgs(userID).
		WillReturnRows(rows)

	item, err := repo.GetUserByID(userID)

	if err != nil {
		t.Errorf("unexpected err: %s", err)
		return
	}
	if err := mock.ExpectationsWereMet(); err != nil {
		t.Errorf("there were unfulfilled expectations: %s", err)
		return
	}
	if !reflect.DeepEqual(item, expect[0]) {
		t.Errorf("results not match, want %v, have %v", expect[0], item)
		return
	}
}
