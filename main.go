package main

import (
	"context"
	"github.com/AleksMa/StealLovingYou/delivery"
	"github.com/AleksMa/StealLovingYou/repository"
	usecase "github.com/AleksMa/StealLovingYou/usecase"

	//"database/sql"
	"fmt"
	"github.com/gorilla/mux"
	"github.com/jackc/pgx/v4/pgxpool"
	_ "github.com/lib/pq"
	"log"
	"net/http"
)

var (
	user     string = "stealuser"
	password string = "steal"
	address  string = "localhost:5432"
	name     string = "stealdb"
)

func main() {

	ctx := context.Background()

	dbinfo := fmt.Sprintf("postgresql://%s:%s@%s/%s", user, password, address, name)

	config, _ := pgxpool.ParseConfig(dbinfo)

	db, err := pgxpool.ConnectConfig(ctx, config)

	//ConnConfig: pgx.ConnConfig{
	//	Host:     "localhost",
	//	User:     "docker",
	//	Password: "docker",
	//	Port:     5432,
	//	Database: "docker",
	//},
	//	MaxConnections: 50,

	// db, err := sql.Open("postgres", dbinfo)
	repo := repository.NewDBStore(db, ctx)
	usecases := usecase.NewUseCase(repo)
	api := delivery.NewHandlers(usecases)

	// _, err = db.Exec(models.InitScript)

	if err != nil {
		fmt.Println(err)
	}

	r := mux.NewRouter().PathPrefix("/api").Subrouter()

	r.HandleFunc("/user/{username}", api.CreateUser).Methods("POST")
	r.HandleFunc("/user/{username}", api.GetUser).Methods("GET")
	//r.HandleFunc("/user/{nickname}/profile", api.UpdateUser).Methods("POST")

	r.HandleFunc("/task/{taskname}", api.CreateTask).Methods("POST")
	r.HandleFunc("/task/{taskname}", api.GetTask).Methods("GET")

	r.HandleFunc("/attempt", api.CreateAttempt).Methods("POST")
	r.HandleFunc("/attempt", api.GetAttempt).Methods("GET")

	r.HandleFunc("/result", api.GetResult).Methods("GET")

	r.HandleFunc("/service/status", api.GetStatus).Methods("GET")
	r.HandleFunc("/service/clear", api.Clear).Methods("POST")

	log.Println("http server started on 5000 port: ")
	err = http.ListenAndServe(":5000", r)
	if err != nil {
		log.Println(err)
		return
	}
}
