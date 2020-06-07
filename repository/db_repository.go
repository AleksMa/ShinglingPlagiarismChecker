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
	GetUsers(user *models.User) ([]*models.User, *models.Error)
	//GetUserByID(id int64) (models.User, *models.Error)
	GetUserByUsername(nickname string) (models.User, *models.Error)
	//ChangeUser(user *models.User) *models.Error

	PutTask(task *models.Task) (uint64, *models.Error)
	GetTasks(task *models.Task) ([]*models.Task, *models.Error)
	GetTaskByTaskname(taskname string) (models.Task, *models.Error)

	PutAttempt(attempt *models.Attempt) (uint64, *models.Error)

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

func (store *DBStore) GetUsers(user *models.User) ([]*models.User, *models.Error) {
	users := []*models.User{}

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

func (store *DBStore) PutTask(task *models.Task) (uint64, *models.Error) {
	fmt.Println(task)
	var ID uint64

	insertQuery := `INSERT INTO tasks (taskName, fullName, maxTime, maxMemory) VALUES ($1, $2, $3, $4) RETURNING ID`
	rows := store.DB.QueryRow(store.ctx, insertQuery,
		task.TaskName, task.FullName, task.MaxTime, task.MaxMemory)

	err := rows.Scan(&ID)
	if err != nil {
		fmt.Println(err)
		return 0, models.NewError(http.StatusInternalServerError, err.Error())
	}

	return ID, nil
}

func (store *DBStore) GetTasks(task *models.Task) ([]*models.Task, *models.Error) {
	tasks := []*models.Task{}

	selectStr := "SELECT DISTINCT taskName, fullName, maxTime, maxMemory FROM tasks WHERE taskName=$1"

	rows, err := store.DB.Query(store.ctx, selectStr, task.TaskName)
	if err != nil {
		fmt.Println(err)
		return tasks, models.NewError(http.StatusInternalServerError, err.Error())
	}

	for rows.Next() {
		task := &models.Task{}
		err := rows.Scan(&task.TaskName, &task.FullName, &task.MaxTime, &task.MaxMemory)
		if err != nil {
			return tasks, models.NewError(http.StatusInternalServerError, err.Error())
		}
		tasks = append(tasks, task)
	}

	rows.Close()

	if err != nil {
		return tasks, models.NewError(http.StatusInternalServerError, err.Error())
	}

	return tasks, nil
}

func (store *DBStore) GetTaskByTaskname(taskname string) (models.Task, *models.Error) {
	task := &models.Task{}

	selectStr := "SELECT id, taskName, fullName, maxTime, maxMemory FROM tasks WHERE taskname = $1"
	row := store.DB.QueryRow(store.ctx, selectStr, taskname)

	err := row.Scan(&task.ID, &task.TaskName, &task.FullName, &task.MaxTime, &task.MaxMemory)

	if err != nil {
		fmt.Println(err)
		if err == pgx.ErrNoRows {
			return *task, models.NewError(http.StatusNotFound, err.Error())
		}
		return *task, models.NewError(http.StatusInternalServerError, err.Error())
	}

	return *task, nil
}

func (store *DBStore) PutAttempt(attempt *models.Attempt) (uint64, *models.Error) {
	fmt.Println(attempt)
	var ID uint64

	insertQuery := `INSERT INTO attempts (userID, taskID, memory, time, sourceCode, uploadDate) VALUES 
						((SELECT ID FROM users WHERE userName = $1),
						(SELECT ID FROM tasks WHERE taskName = $2), 
						$3, $4, $5, $6) RETURNING ID`
	rows := store.DB.QueryRow(store.ctx, insertQuery,
		attempt.User, attempt.Task, attempt.Memory, attempt.Time, attempt.SourceCode, attempt.UploadDate)

	err := rows.Scan(&ID)
	if err != nil {
		fmt.Println(err)
		return 0, models.NewError(http.StatusInternalServerError, err.Error())
	}

	return ID, nil
}
