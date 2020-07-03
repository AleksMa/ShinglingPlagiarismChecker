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



var (
	Timing int64
	Count int64
)

func main() {

	defer func() {
		fmt.Println("COUNT:", Count)
		if Count != 0 {
			fmt.Println("TIMING:", Timing / Count)
		}
	}()

	ctx := context.Background()

	dbinfo := fmt.Sprintf("postgresql://%s:%s@%s/%s?pool_max_conns=200000", user, password, address, name)

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
	usecases := usecase.NewUseCase(repo, &Timing, &Count)
	api := delivery.NewHandlers(usecases)

	// _, err = db.Exec(models.InitScript)

	if err != nil {
		fmt.Println(err)
	}

	r := mux.NewRouter()

	r.HandleFunc("/user/{username}", api.CreateUser).Methods("POST")
	r.HandleFunc("/user/{username}", api.GetUser).Methods("GET")
	r.HandleFunc("/user/{username}", api.UpdateUser).Methods("PUT")
	r.HandleFunc("/user/{username}", api.DeleteUser).Methods("DELETE")
	//r.HandleFunc("/user/{nickname}/profile", api.UpdateUser).Methods("POST")

	r.HandleFunc("/task/{taskname}", api.CreateTask).Methods("POST")
	r.HandleFunc("/task/{taskname}", api.GetTask).Methods("GET")
	r.HandleFunc("/task/{taskname}", api.UpdateTask).Methods("PUT")
	r.HandleFunc("/task/{taskname}", api.DeleteTask).Methods("DELETE")

	r.HandleFunc("/attempt", api.CreateAttempt).Methods("POST")
	r.HandleFunc("/attempt", api.GetAttempt).Methods("GET")

	r.HandleFunc("/result", api.GetResult).Methods("GET")

	r.HandleFunc("/service/status", api.GetStatus).Methods("GET")
	r.HandleFunc("/service/clear", api.Clear).Methods("POST")

	r.HandleFunc("/admin/swagger", api.HandleSwagger).Methods("GET")
	r.HandleFunc("/admin/swagger/{filename:.*}", api.LoadSwagger).Methods("GET")
	r.HandleFunc("/admin/{filename:.*}", api.LoadSwagger).Methods("GET")

	log.Println("http server started on 5000 port: ")

	err = http.ListenAndServe(":5000", r)
	if err != nil {
		log.Println(err)
		return
	}
}
