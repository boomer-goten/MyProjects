package types

type AuthResponse struct {
	Token  string `json:"token"`
	UserID int    `json:"userID"`
}
