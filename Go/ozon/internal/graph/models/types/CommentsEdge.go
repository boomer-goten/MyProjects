package types

type CommentsEdge struct {
	Node   *Comment `json:"node,omitempty"`
	Cursor string   `json:"cursor"`
}
