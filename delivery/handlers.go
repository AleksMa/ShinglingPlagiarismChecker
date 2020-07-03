package delivery

import (
	"bytes"
	"encoding/json"
	"fmt"
	"github.com/AleksMa/StealLovingYou/models"
	"github.com/AleksMa/StealLovingYou/swagger"
	useCase2 "github.com/AleksMa/StealLovingYou/usecase"
	"github.com/gorilla/mux"
	"io/ioutil"
	"net/http"
	"path/filepath"
	"strings"
	"time"
)

type Handlers struct {
	usecases useCase2.UseCase
}

func NewHandlers(ucases useCase2.UseCase) *Handlers {
	return &Handlers{
		usecases: ucases,
	}
}

func WriteResponse(w http.ResponseWriter, body []byte, code int) {
	w.Header().Set("Content-Type", "application/json")
	w.WriteHeader(code)
	w.Write(body)
}

func (handlers *Handlers) GetStatus(w http.ResponseWriter, r *http.Request) {
	status, _ := handlers.usecases.GetStatus()

	fmt.Println(status)

	body, _ := json.Marshal(status)

	w.Header().Set("Content-Type", "application/json")
	w.Write(body)
}

func (handlers *Handlers) Clear(w http.ResponseWriter, r *http.Request) {
	handlers.usecases.RemoveAllData()
}

func (handlers *Handlers) CreateUser(w http.ResponseWriter, r *http.Request) {
	var user models.User

	defer r.Body.Close()
	body, _ := ioutil.ReadAll(r.Body)

	fmt.Println(string(body))
	vars := mux.Vars(r)
	username := vars["username"]

	err := json.Unmarshal(body, &user)
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}
	user.UserName = username

	users, e := handlers.usecases.PutUser(&user)
	if e != nil {
		body, _ = json.Marshal(e)
		WriteResponse(w, body, e.Code)
		//http.Error(w, e.Message, e.Code)
		return
	}
	if users != nil {
		body, _ = json.Marshal(users)
		WriteResponse(w, body, http.StatusConflict)
		return
	}
	body, err = json.Marshal(user)
	//http.Error(w, err.Error(), http.StatusInternalServerError)

	WriteResponse(w, body, http.StatusCreated)
}

func (handlers *Handlers) GetUser(w http.ResponseWriter, r *http.Request) {
	vars := mux.Vars(r)
	username := vars["username"]

	user, err := handlers.usecases.GetUserByUsername(username)
	if err != nil {
		body, _ := json.Marshal(err)
		WriteResponse(w, body, err.Code)
		return
	}

	body, _ := json.Marshal(user)

	WriteResponse(w, body, http.StatusOK)
}

func (handlers *Handlers) UpdateUser(w http.ResponseWriter, r *http.Request) {
	var user models.User

	defer r.Body.Close()
	body, _ := ioutil.ReadAll(r.Body)

	fmt.Println(string(body))
	vars := mux.Vars(r)
	username := vars["username"]

	err := json.Unmarshal(body, &user)
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}
	user.UserName = username

	users, e := handlers.usecases.UpdateUser(&user)
	if e != nil {
		body, _ = json.Marshal(e)
		WriteResponse(w, body, e.Code)
		return
	}
	if len(users) > 1 {
		body, _ = json.Marshal(users)
		WriteResponse(w, body, http.StatusConflict)
		return
	}
	body, err = json.Marshal(user)
	//http.Error(w, err.Error(), http.StatusInternalServerError)

	WriteResponse(w, body, http.StatusOK)
}

func (handlers *Handlers) DeleteUser(w http.ResponseWriter, r *http.Request) {
	vars := mux.Vars(r)
	username := vars["username"]

	user, err := handlers.usecases.DeleteUserByUsername(username)
	if err != nil {
		body, _ := json.Marshal(err)
		WriteResponse(w, body, err.Code)
		return
	}

	body, _ := json.Marshal(user)

	WriteResponse(w, body, http.StatusOK)
}

func (handlers *Handlers) CreateTask(w http.ResponseWriter, r *http.Request) {
	var task models.Task

	defer r.Body.Close()
	body, _ := ioutil.ReadAll(r.Body)

	fmt.Println(string(body))
	vars := mux.Vars(r)
	taskname := vars["taskname"]

	err := json.Unmarshal(body, &task)
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}
	task.TaskName = taskname

	tasks, e := handlers.usecases.PutTask(&task)
	if e != nil {
		body, _ = json.Marshal(e)
		WriteResponse(w, body, e.Code)
		return
	}
	if tasks != nil {
		body, _ = json.Marshal(tasks)
		WriteResponse(w, body, http.StatusConflict)
		return
	}
	body, err = json.Marshal(task)

	WriteResponse(w, body, http.StatusCreated)
}

func (handlers *Handlers) GetTask(w http.ResponseWriter, r *http.Request) {
	vars := mux.Vars(r)
	taskname := vars["taskname"]

	task, err := handlers.usecases.GetTaskByTaskname(taskname)
	if err != nil {
		body, _ := json.Marshal(err)
		WriteResponse(w, body, err.Code)
		return
	}

	body, _ := json.Marshal(task)

	WriteResponse(w, body, http.StatusOK)
}

func (handlers *Handlers) UpdateTask(w http.ResponseWriter, r *http.Request) {
	var task models.Task

	defer r.Body.Close()
	body, _ := ioutil.ReadAll(r.Body)

	fmt.Println(string(body))
	vars := mux.Vars(r)
	taskname := vars["taskname"]

	err := json.Unmarshal(body, &task)
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}
	task.TaskName = taskname

	tasks, e := handlers.usecases.UpdateTask(&task)
	if e != nil {
		body, _ = json.Marshal(e)
		WriteResponse(w, body, e.Code)
		return
	}
	if len(tasks) > 1 {
		body, _ = json.Marshal(tasks)
		WriteResponse(w, body, http.StatusConflict)
		return
	}
	body, err = json.Marshal(task)

	WriteResponse(w, body, http.StatusOK)
}

func (handlers *Handlers) DeleteTask(w http.ResponseWriter, r *http.Request) {
	vars := mux.Vars(r)
	taskname := vars["taskname"]

	task, err := handlers.usecases.DeleteTaskByTaskname(taskname)
	if err != nil {
		body, _ := json.Marshal(err)
		WriteResponse(w, body, err.Code)
		return
	}

	body, _ := json.Marshal(task)

	WriteResponse(w, body, http.StatusOK)
}

func (handlers *Handlers) CreateAttempt(w http.ResponseWriter, r *http.Request) {
	var attempt models.Attempt

	defer r.Body.Close()
	body, _ := ioutil.ReadAll(r.Body)

	err := json.Unmarshal(body, &attempt)
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}

	attempt.UploadDate = time.Now()

	t := time.Now()
	e := handlers.usecases.PutAttempt(&attempt)
	fmt.Println(time.Now().Sub(t))

	if e != nil {
		body, _ = json.Marshal(e)
		WriteResponse(w, body, e.Code)
		return
	}

	body, err = json.Marshal(attempt)

	WriteResponse(w, body, http.StatusCreated)
}

func (handlers *Handlers) GetAttempt(w http.ResponseWriter, r *http.Request) {
	user := r.FormValue("user")
	task := r.FormValue("task")

	attempts, err := handlers.usecases.GetAttempt(task, user)
	if err != nil {
		body, _ := json.Marshal(err)
		WriteResponse(w, body, err.Code)
		return
	}

	body, _ := json.Marshal(attempts)

	WriteResponse(w, body, http.StatusOK)
}

func (handlers *Handlers) GetResult(w http.ResponseWriter, r *http.Request) {
	user := r.FormValue("user")
	task := r.FormValue("task")

	attempts, err := handlers.usecases.GetResult(task, user)
	if err != nil {
		body, _ := json.Marshal(err)
		WriteResponse(w, body, err.Code)
		return
	}

	body, _ := json.Marshal(attempts)

	WriteResponse(w, body, http.StatusOK)
}

func (handlers *Handlers) HandleSwagger(w http.ResponseWriter, r *http.Request) {
	body, err := ioutil.ReadFile(filepath.Join("/Users/a.mamaev/go/src/StealLovingYou/swagger/static", "index.html"))
	if err != nil {
		fmt.Println(err)
		WriteResponse(w, body, http.StatusInternalServerError)
	}
	body = bytes.Replace(body, []byte("%EXTERNAL_NAME%"), append([]byte("http://"), []byte(r.Host)...), -1)
	w.Header().Set("Content-Type", "text/html")
	w.WriteHeader(http.StatusOK)
	w.Write(body)
}

func (handlers *Handlers) LoadSwagger(w http.ResponseWriter, r *http.Request) {
	vars := mux.Vars(r)
	filename := vars["filename"]
	fmt.Println(filename)

	path := "/Users/a.mamaev/go/src/StealLovingYou/swagger/static"
	if swagger.CheckHandlerSchemaPath([]byte(filename)) {
		path = "/Users/a.mamaev/go/src/StealLovingYou/swagger"
	}

	body, err := ioutil.ReadFile(filepath.Join(path, filename))
	if err != nil {
		fmt.Println(err)
		WriteResponse(w, body, http.StatusInternalServerError)
	}
	if strings.HasSuffix(filename, ".css") {
		w.Header().Set("Content-Type", "text/css")
	}
	w.WriteHeader(http.StatusOK)
	w.Write(body)
}
