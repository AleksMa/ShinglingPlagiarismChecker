package delivery

import (
	"encoding/json"
	"fmt"
	useCase2 "github.com/AleksMa/StealLovingYou/useCase"
	"github.com/gorilla/mux"
	"io/ioutil"
	"net/http"
	"strconv"
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
	nickname := vars["nickname"]

	err := json.Unmarshal(body, &user)
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}
	user.Nickname = nickname

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
	nickname := vars["nickname"]

	user, err := handlers.usecases.GetUserByNickname(nickname)
	if err != nil {
		body, _ := json.Marshal(err)
		WriteResponse(w, body, err.Code)
		return
	}

	body, _ := json.Marshal(user)

	WriteResponse(w, body, http.StatusOK)
}

func (handlers *Handlers) UpdateUser(w http.ResponseWriter, r *http.Request) {
	var userUpd models.UpdateUserFields
	var e *models.Error

	defer r.Body.Close()
	body, _ := ioutil.ReadAll(r.Body)

	fmt.Println(string(body))
	vars := mux.Vars(r)
	nickname := vars["nickname"]

	err := json.Unmarshal(body, &userUpd)
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}

	user, e := handlers.usecases.ChangeUser(&userUpd, nickname)
	if e != nil {
		body, _ = json.Marshal(e)
		WriteResponse(w, body, e.Code)
		return
	}

	body, _ = json.Marshal(user)

	WriteResponse(w, body, http.StatusOK)
}

func (handlers *Handlers) GetUsers(w http.ResponseWriter, r *http.Request) {
	vars := mux.Vars(r)
	slug := vars["slug"]

	query := r.URL.Query()
	var params models.UserParams
	var err error

	params.Limit, err = strconv.Atoi(query.Get("limit"))
	if err != nil {
		params.Limit = -1
	}
	params.Since = query.Get("since")
	fmt.Println("SINCE: ", params.Since)
	params.Desc = query.Get("desc") == "true"

	users, e := handlers.usecases.GetUsersByForum(slug, params)
	if e != nil {
		body, _ := json.Marshal(e)
		WriteResponse(w, body, e.Code)
		return
	}

	fmt.Println(users)

	body, _ := json.Marshal(users)

	WriteResponse(w, body, http.StatusOK)
}

