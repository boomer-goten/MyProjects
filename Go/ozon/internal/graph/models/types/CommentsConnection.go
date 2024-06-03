package types

type CommentsConnection struct {
	Post     Post      `json:"post"`
	PageInfo *PageInfo `json:"pageInfo"`
	// TotalCount int             `json:"totalCount"`
	// Edges      []*CommentsEdge `json:"edges,omitempty"`

}
