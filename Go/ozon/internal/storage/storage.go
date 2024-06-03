package storage

import (
	"graphQL-fakereddit-service/internal/graph/models/input"
	"graphQL-fakereddit-service/internal/graph/models/types"
)

var DefaultDepth = 3

type Storage interface {
	CreatePost(data input.NewPost, ID int, Name string) (*types.Post, error)
	CreateComment(data input.NewComment, ID int, Name string) (*types.Comment, error)
	AccessComments(data input.ChangeAccessComments, ID int, Name string) (*types.Post, error)
	Register(data input.LoginRegister) (*types.RegistrResponse, error)
	Login(data input.LoginRegister) (int, error)
	GetPost(data *input.CommentPost, limit *int, offset *int) (*types.CommentsConnection, error)
	GetPosts() ([]*types.Post, error)
	Stop() error
}
