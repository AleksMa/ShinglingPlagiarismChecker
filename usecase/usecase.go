package usecase

import (
	"fmt"
	"github.com/AleksMa/StealLovingYou/models"
	"github.com/AleksMa/StealLovingYou/repository"
)

type UseCase interface {
	PutUser(user *models.User) ([]*models.User, *models.Error)
	GetUserByUsername(nickname string) (models.User, *models.Error)
	//ChangeUser(userUpd *models.UpdateUserFields, nickname string) (models.User, *models.Error)

	PutTask(task *models.Task) ([]*models.Task, *models.Error)
	GetTaskByTaskname(taskname string) (models.Task, *models.Error)

	GetStatus() (models.Status, error)
	RemoveAllData() error
}

type useCase struct {
	repository repository.Repo
}

func NewUseCase(repo repository.Repo) UseCase {
	return &useCase{
		repository: repo,
	}
}

func (u *useCase) GetStatus() (models.Status, error) {
	return u.repository.GetStatus()
}

func (u *useCase) RemoveAllData() error {
	return u.repository.ReloadDB()
}


func (u *useCase) PutUser(user *models.User) ([]*models.User, *models.Error) {
	fmt.Println(user)

	if err := user.Validate(); err != nil {
		return nil, err
	}

	users, _ := u.repository.GetUsers(user)
	if users != nil && len(users) != 0 {
		fmt.Println("DUP: ", users)
		return users, nil
	}

	_, err := u.repository.PutUser(user)
	return nil, err
}

func (u *useCase) GetUserByUsername(nickname string) (models.User, *models.Error) {
	return u.repository.GetUserByUsername(nickname)
}

//func (u *useCase) GetUserByID(id int64) (models.User, *models.Error) {
//	return u.repository.GetUserByID(id)
//}

//func (u *useCase) ChangeUser(userUpd *models.UpdateUserFields, nickname string) (models.User, *models.Error) {
//	tempUser, err := u.GetUserByUsername(nickname)
//	if err != nil {
//		return tempUser, err
//	}
//
//	if userUpd.Email != nil {
//		tempUser.Email = *userUpd.Email
//	}
//	if userUpd.Fullname != nil {
//		tempUser.Fullname = *userUpd.Fullname
//	}
//	if userUpd.About != nil {
//		tempUser.About = *userUpd.About
//	}
//
//	err = u.repository.ChangeUser(&tempUser)
//	fmt.Println(*userUpd)
//	fmt.Println(tempUser)
//	return tempUser, err
//}

func (u *useCase) PutTask(task *models.Task) ([]*models.Task, *models.Error) {
	fmt.Println(task)

	if err := task.Validate(); err != nil {
		return nil, err
	}

	tasks, _ := u.repository.GetTasks(task)
	if tasks != nil && len(tasks) != 0 {
		fmt.Println("DUP: ", tasks)
		return tasks, nil
	}

	_, err := u.repository.PutTask(task)
	return nil, err
}

func (u *useCase) GetTaskByTaskname(taskname string) (models.Task, *models.Error) {
	return u.repository.GetTaskByTaskname(taskname)
}
