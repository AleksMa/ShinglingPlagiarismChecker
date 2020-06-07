package delivery

import (
	"encoding/json"
	"fmt"
	"github.com/AleksMa/StealLovingYou/models"
	useCase2 "github.com/AleksMa/StealLovingYou/usecase"
	"github.com/gorilla/mux"
	"io/ioutil"
	"net/http"
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

//func (handlers *Handlers) UpdateUser(w http.ResponseWriter, r *http.Request) {
//	var userUpd models.UpdateUserFields
//	var e *models.Error
//
//	defer r.Body.Close()
//	body, _ := ioutil.ReadAll(r.Body)
//
//	fmt.Println(string(body))
//	vars := mux.Vars(r)
//	nickname := vars["nickname"]
//
//	err := json.Unmarshal(body, &userUpd)
//	if err != nil {
//		http.Error(w, err.Error(), http.StatusInternalServerError)
//		return
//	}
//
//	user, e := handlers.usecases.ChangeUser(&userUpd, nickname)
//	if e != nil {
//		body, _ = json.Marshal(e)
//		WriteResponse(w, body, e.Code)
//		return
//	}
//
//	body, _ = json.Marshal(user)
//
//	WriteResponse(w, body, http.StatusOK)
//}

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
