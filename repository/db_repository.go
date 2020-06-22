package repository

import (
	"context"
	"fmt"
	"github.com/AleksMa/StealLovingYou/models"
	"github.com/jackc/pgx"
	"github.com/jackc/pgx/v4/pgxpool"
	"net/http"
)

type Repo interface {
	PutUser(user *models.User) (uint64, *models.Error)
	GetUsers(user *models.User) ([]*models.User, *models.Error)
	GetUserByUsername(nickname string) (models.User, *models.Error)

	PutTask(task *models.Task) (uint64, *models.Error)
	GetTasks(task *models.Task) ([]*models.Task, *models.Error)
	GetTaskByTaskname(taskname string) (models.Task, *models.Error)

	PutAttempt(attempt *models.Attempt) (uint64, *models.Error)
	GetAttempt(task string, user string) ([]*models.Attempt, *models.Error)

	GetStatus() (models.Status, *models.Error)
	ReloadDB() *models.Error

	GetResult(task string, user string) ([]*models.Result, *models.Error)

	PutHashes(ID uint64, hashSet models.HashSet) *models.Error
	GetHashes(ID uint64) (*models.HashSet, *models.Error)
	GetSimilarHashes(attempt *models.Attempt) ([]*models.HashObject, *models.Error)

	PutBorrowing(borrowing *models.Borrowing) *models.Error
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
	var ID uint64

	tx, err := store.DB.Begin(store.ctx)
	if err != nil {
		return 0, models.NewError(http.StatusInternalServerError, err.Error())
	}


	insertQuery := `INSERT INTO users (userName, fullName, studentID) VALUES ($1, $2, $3) RETURNING id`
	rows := tx.QueryRow(store.ctx, insertQuery,
		user.UserName, user.FullName, user.StudentID)

	err = rows.Scan(&ID)
	if err != nil {
		tx.Rollback(store.ctx)
		return 0, models.NewError(http.StatusInternalServerError, err.Error())
	}

	tx.Commit(store.ctx)
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

	fmt.Println(attempt.UploadDate)

	err := rows.Scan(&ID)
	if err != nil {
		fmt.Println(err)
		return 0, models.NewError(http.StatusInternalServerError, err.Error())
	}

	insertQuery = `INSERT INTO status (attemptID, status) VALUES
						($1, $2)`
	store.DB.QueryRow(store.ctx, insertQuery, ID, 1)

	return ID, nil
}

func (store *DBStore) GetAttempt(task string, user string) ([]*models.Attempt, *models.Error) {
	var attempts []*models.Attempt
	var args []interface{}

	selectStr := `SELECT u.userName, t.taskName, a.time, a.memory, a.uploaddate, a.sourcecode
					FROM users u
         			JOIN attempts a on u.ID = a.userID
         			JOIN tasks t ON a.taskID = t.ID`

	if task != "" {
		selectStr += " WHERE t.taskname=$1"
		args = append(args, task)
	}

	if user != "" {
		if task != "" {
			selectStr += " AND u.username=$2"
		} else {
			selectStr += " WHERE u.username=$1"
		}
		args = append(args, user)
	}
	selectStr += ";"

	rows, err := store.DB.Query(store.ctx, selectStr, args...)
	if err != nil {
		fmt.Println(err)
		return attempts, models.NewError(http.StatusInternalServerError, err.Error())
	}

	for rows.Next() {
		attempt := &models.Attempt{}
		err := rows.Scan(&attempt.User, &attempt.Task, &attempt.Time,
			&attempt.Memory, &attempt.UploadDate, &attempt.SourceCode)
		if err != nil {
			return attempts, models.NewError(http.StatusInternalServerError, err.Error())
		}
		attempts = append(attempts, attempt)
	}

	rows.Close()

	return attempts, nil
}

func (store *DBStore) GetResult(task string, user string) ([]*models.Result, *models.Error) {
	var results []*models.Result
	var args []interface{}

	selectStr := `SELECT id, userName, taskName, uploadDate, status, percent, 
						 copiedFrom, copiedTask, copiedDate, sourceCode, copiedCode
					FROM results`

	if task != "" {
		selectStr += " WHERE taskname=$1"
		args = append(args, task)
	}

	if user != "" {
		if task != "" {
			selectStr += " AND username=$2"
		} else {
			selectStr += " WHERE username=$1"
		}
		args = append(args, user)
	}
	selectStr += "AND percent > 2;"

	rows, err := store.DB.Query(store.ctx, selectStr, args...)
	if err != nil {
		fmt.Println(err)
		return results, models.NewError(http.StatusInternalServerError, err.Error())
	}

	for rows.Next() {
		result := &models.Result{}
		copied := &models.AttemptSimplification{}
		err := rows.Scan(&result.ID, &result.User, &result.Task, &result.UploadDate, &result.Status, &copied.PlagiarismPercent,
			&copied.User, &copied.Task, &copied.UploadDate, &result.SourceCode, &copied.SourceCode)
		if err != nil {
			return results, models.NewError(http.StatusInternalServerError, err.Error())
		}
		result.CopiedFrom = append(result.CopiedFrom, copied)
		results = append(results, result)
	}

	rows.Close()

	return results, nil
}

func (store *DBStore) PutHashes(ID uint64, hashSet models.HashSet) *models.Error {
	var gID uint64



	for hash := range hashSet {
		insertQuery := `INSERT INTO hashes (attemptID, Hash) VALUES ($1, $2) RETURNING attemptID`
		rows := store.DB.QueryRow(store.ctx, insertQuery,
			ID, hash)

		err := rows.Scan(&gID)
		if err != nil || ID != gID {
			fmt.Println(err)
			return models.NewError(http.StatusInternalServerError, err.Error())
		}
	}

	updateQuery := `UPDATE status SET status=$1 WHERE attemptID=$2`
	_, err := store.DB.Exec(store.ctx, updateQuery,
		3, ID)

	if err != nil {
		return models.NewError(http.StatusInternalServerError, err.Error())
	}
	return nil
}

func (store *DBStore) GetHashes(ID uint64) (*models.HashSet, *models.Error) {

	result := make(models.HashSet)

	selectStr := `SELECT hash FROM hashes
						WHERE attemptID=$1;`

	rows, err := store.DB.Query(store.ctx, selectStr, ID)
	defer rows.Close()
	if err != nil {
		return &result, models.NewError(http.StatusInternalServerError, err.Error())
	}

	for rows.Next() {
		var hash models.Hash

		err := rows.Scan(&hash)
		if err != nil {
			return &result, models.NewError(http.StatusInternalServerError, err.Error())
		}
		result[hash] = struct{}{}
	}


	return &result, nil
}

func (store *DBStore) GetSimilarHashes(attempt *models.Attempt) ([]*models.HashObject, *models.Error) {
	var results []*models.HashObject

	selectStr := `SELECT a.ID FROM attempts a
						JOIN tasks t on a.taskID = t.ID
						WHERE t.taskName=$1;`

	rows, err := store.DB.Query(store.ctx, selectStr, attempt.Task)
	defer rows.Close()
	if err != nil {
		fmt.Println(err)
		return results, models.NewError(http.StatusInternalServerError, err.Error())
	}

	for rows.Next() {
		var attemptID uint64
		err := rows.Scan(&attemptID)
		if err != nil {
			return results, models.NewError(http.StatusInternalServerError, err.Error())
		}
		if attemptID == attempt.ID {
			continue
		}
		hs, e := store.GetHashes(attemptID)
		if e != nil {
			return results, models.NewError(http.StatusInternalServerError, e.Error())
		}
		result := &models.HashObject{
			ID:  attemptID,
			Set: hs,
		}
		results = append(results, result)
	}

	return results, nil
}

func (store *DBStore) PutBorrowing(borrowing *models.Borrowing) *models.Error {
	//fmt.Println(borrowing)
	var ID uint64

	insertQuery := `INSERT INTO borrowings (attemptID, copiedFrom, plagiarismPercent) VALUES ($1, $2, $3) RETURNING attemptID`
	rows := store.DB.QueryRow(store.ctx, insertQuery,
		borrowing.AttemptID, borrowing.CopiedFrom, borrowing.Percent)

	err := rows.Scan(&ID)
	if err != nil || ID != borrowing.AttemptID {
		fmt.Println(err)
		return models.NewError(http.StatusInternalServerError, err.Error())
	}

	return nil
}

//func ( store * DBStore ) PutUsers ( user * models . User ) {
//func ( store * DBStore ) PutUsers ( user *
//	 ( store * DBStore ) PutUsers ( user * models
//	   store * DBStore ) PutUsers ( user * models .
//			 * DBStore ) PutUsers ( user * models . User
//func ( store * DBStore ) PutUsers ( user * models . User )
//func ( store * DBStore ) PutUsers ( user * models . User ) {