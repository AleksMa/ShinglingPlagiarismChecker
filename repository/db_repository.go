package repository

import (
	"context"
	"fmt"
	"github.com/AleksMa/StealLovingYou/models"
	"github.com/jackc/pgx"
	"github.com/jackc/pgx/v4/pgxpool"
	"net/http"
	//"strconv"
)

type Repo interface {
	PutUser(user *models.User) (uint64, *models.Error)
	GetUsers(user *models.User) (models.Users, *models.Error)
	//GetUserByID(id int64) (models.User, *models.Error)
	GetUserByUsername(nickname string) (models.User, *models.Error)
	//ChangeUser(user *models.User) *models.Error

	GetStatus() (models.Status, *models.Error)
	ReloadDB() *models.Error
}

type DBStore struct {
	DB  *pgxpool.Pool
	ctx context.Context
}

func NewDBStore(pool *pgxpool.Pool, ctx context.Context) Repo {
	return &DBStore{
		pool,
		ctx,
	}
}

func (store *DBStore) GetStatus() (models.Status, *models.Error) {
	tx, _ := store.DB.Begin(context.Background())
	defer tx.Rollback(context.Background())

	status := &models.Status{}

	//row := tx.QueryRow(store.ctx, `SELECT count(*) FROM forums`)
	//row.Scan(&status.Forum)
	//
	//row = tx.QueryRow(store.ctx, `SELECT count(*) FROM posts`)
	//row.Scan(&status.Post)
	//
	//row = tx.QueryRow(store.ctx, `SELECT count(*) FROM threads`)
	//row.Scan(&status.Thread)

	row := tx.QueryRow(store.ctx, `SELECT count(*) FROM users`)
	row.Scan(&status.User)

	tx.Commit(store.ctx)

	return *status, nil
}

func (store *DBStore) ReloadDB() *models.Error {
	_, err := store.DB.Exec(store.ctx, models.InitScript)
	if err != nil {
		return models.NewError(http.StatusInternalServerError, err.Error())
	}
	return nil
}

func (store *DBStore) PutUser(user *models.User) (uint64, *models.Error) {
	fmt.Println(user)
	var ID uint64

	insertQuery := `INSERT INTO users (userName, fullName, studentID) VALUES ($1, $2, $3) RETURNING id`
	rows := store.DB.QueryRow(store.ctx, insertQuery,
		user.UserName, user.FullName, user.StudentID)

	err := rows.Scan(&ID)
	if err != nil {
		fmt.Println(err)
		return 0, models.NewError(http.StatusInternalServerError, err.Error())
	}

	return ID, nil
}

func (store *DBStore) GetUsers(user *models.User) (models.Users, *models.Error) {
	users := models.Users{}

	selectStr := "SELECT DISTINCT userName, fullName, studentID FROM users WHERE userName=$1 OR studentID=$2"

	rows, err := store.DB.Query(store.ctx, selectStr, user.UserName, user.StudentID)
	if err != nil {
		fmt.Println(err)
		return users, models.NewError(http.StatusInternalServerError, err.Error())
	}

	for rows.Next() {
		user := &models.User{}
		err := rows.Scan(&user.UserName, &user.FullName, &user.StudentID)
		if err != nil {
			return users, models.NewError(http.StatusInternalServerError, err.Error())
		}
		users = append(users, user)
	}

	rows.Close()

	if err != nil {
		return users, models.NewError(http.StatusInternalServerError, err.Error())
	}

	return users, nil
}

func (store *DBStore) GetUserByUsername(nickname string) (models.User, *models.Error) {
	user := &models.User{}

	selectStr := "SELECT id, userName, fullName, studentID FROM users WHERE username = $1"
	row := store.DB.QueryRow(store.ctx, selectStr, nickname)

	err := row.Scan(&user.ID, &user.UserName, &user.FullName, &user.StudentID)

	if err != nil {
		fmt.Println(err)
		if err == pgx.ErrNoRows {
			return *user, models.NewError(http.StatusNotFound, err.Error())
		}
		return *user, models.NewError(http.StatusInternalServerError, err.Error())
	}

	return *user, nil
}
//
//func (store *DBStore) GetUserByID(id int64) (models.User, *models.Error) {
//	user := &models.User{}
//
//	selectStr := "SELECT id, nickname, about, email, fullname FROM users WHERE id = $1"
//	row := store.DB.QueryRow(store.ctx, selectStr, id)
//
//	err := row.Scan(&user.ID, &user.Nickname, &user.About, &user.Email, &user.Fullname)
//
//	if err != nil {
//		fmt.Println(err)
//		if err == pgx.ErrNoRows {
//			return *user, models.NewError(http.StatusNotFound, err.Error())
//		}
//		return *user, models.NewError(http.StatusInternalServerError, err.Error())
//	}
//
//	return *user, nil
//}
//
//func (store *DBStore) ChangeUser(user *models.User) *models.Error {
//
//	insertQuery := `UPDATE users SET about=$1, email=$2, fullname=$3 WHERE nickname=$4`
//	_, err := store.DB.Exec(store.ctx, insertQuery,
//		user.About, user.Email, user.Fullname, user.Nickname)
//
//	if err != nil {
//		if pgerr, ok := err.(pgx.PgError); ok && pgerr.Code == "23505" {
//			return models.NewError(http.StatusConflict, err.Error())
//		}
//		return models.NewError(http.StatusInternalServerError, err.Error())
//	}
//
//	return nil
//}
