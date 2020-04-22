package useCase

import (
	"fmt"
	"github.com/AleksMa/StealLovingYou/models"
	"github.com/AleksMa/StealLovingYou/repository"
)

type UseCase interface {
	PutUser(user *models.User) (models.Users, *models.Error)
	GetUserByNickname(nickname string) (models.User, *models.Error)
	ChangeUser(userUpd *models.UpdateUserFields, nickname string) (models.User, *models.Error)
	GetUsersByForum(slug string, params models.UserParams) (models.Users, *models.Error)

	PutForum(forum *models.Forum) (models.Forum, *models.Error)
	GetForumBySlug(slug string) (models.Forum, *models.Error)
	GetForumByID(id int64) (models.Forum, *models.Error)

	PutThread(thread *models.Thread) (models.Thread, *models.Error)
	GetThreadBySlug(slug string) (models.Thread, *models.Error)
	GetThreadByID(id int64) (models.Thread, *models.Error)
	GetUserByID(id int64) (models.User, *models.Error)
	GetThreadsByForum(slug string, params models.ThreadParams) (models.Threads, *models.Error)
	UpdateThreadWithID(thread *models.Thread) (models.Thread, *models.Error)
	UpdateThreadWithSlug(thread *models.Thread) (models.Thread, *models.Error)

	PutPost(post *models.Post) (*models.Post, *models.Error)
	PutPostWithSlug(post *models.Post, threadSlug string) (*models.Post, *models.Error)
	GetPostFull(id int64, fields []string) (models.PostFull, *models.Error)
	GetPostByID(id int64) (models.Post, *models.Error)
	ChangePost(post *models.Post) (models.Post, *models.Error)

	PutVote(vote *models.Vote) (models.Thread, *models.Error)
	PutVoteWithSlug(vote *models.Vote, slug string) (models.Thread, *models.Error)

	GetPostsByThreadID(id int64, params models.PostParams) (models.Posts, *models.Error)
	GetPostsByThreadSlug(slug string, params models.PostParams) (models.Posts, *models.Error)

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


func (u *useCase) PutUser(user *models.User) (models.Users, *models.Error) {
	fmt.Println(user)

	if err := user.Validate(); err != nil {
		return nil, err
	}

	users, _ := u.repository.GetDupUsers(user)
	if users != nil && len(users) != 0 {
		fmt.Println("DUP: ", users)
		return users, nil
	}

	_, err := u.repository.PutUser(user)
	return nil, err
}

func (u *useCase) GetUserByNickname(nickname string) (models.User, *models.Error) {
	return u.repository.GetUserByNickname(nickname)
}

func (u *useCase) GetUserByID(id int64) (models.User, *models.Error) {
	return u.repository.GetUserByID(id)
}

func (u *useCase) ChangeUser(userUpd *models.UpdateUserFields, nickname string) (models.User, *models.Error) {
	tempUser, err := u.GetUserByNickname(nickname)
	if err != nil {
		return tempUser, err
	}

	if userUpd.Email != nil {
		tempUser.Email = *userUpd.Email
	}
	if userUpd.Fullname != nil {
		tempUser.Fullname = *userUpd.Fullname
	}
	if userUpd.About != nil {
		tempUser.About = *userUpd.About
	}

	err = u.repository.ChangeUser(&tempUser)
	fmt.Println(*userUpd)
	fmt.Println(tempUser)
	return tempUser, err
}

func (u *useCase) GetUsersByForum(slug string, params models.UserParams) (models.Users, *models.Error) {
	forum, e := u.repository.GetForumBySlug(slug)
	if e != nil {
		return nil, e
	}

	users, e := u.repository.GetUsersByForum(forum.ID, params)
	if e != nil {
		return nil, e
	}

	fmt.Println(users)
	for i, _ := range users {
		user, _ := u.repository.GetUserByID(users[i].ID)
		users[i].Nickname = user.Nickname
		users[i].Fullname = user.Fullname
		users[i].About = user.About
		users[i].Email = user.Email
	}
	return users, nil
}

