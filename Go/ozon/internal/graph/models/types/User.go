package types

import "golang.org/x/crypto/bcrypt"

type User struct {
	ID       int    `json:"id" gorm:"primaryKey:autoIncrement:true"`
	Name     string `json:"name" gorm:"index:idx_name,unique,foreignKey:ID"`
	Password string `json:"password"`
}

func (u *User) TableName() string {
	return "users"
}

func (u *User) EncryptPassword() error {
	hashPass, err := bcrypt.GenerateFromPassword([]byte(u.Password), bcrypt.MinCost)
	if err != nil {
		return err
	}
	u.Password = string(hashPass)
	return nil
}

func (u *User) CompareHashPassword(password string) bool {
	err := bcrypt.CompareHashAndPassword([]byte(u.Password), []byte(password))
	return err == nil
}
