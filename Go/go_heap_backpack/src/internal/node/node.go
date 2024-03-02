package node

type TreeNode struct {
	HasToy bool
	Left   *TreeNode
	Right  *TreeNode
}

type Queue []*TreeNode

func (q Queue) Len() int { return len(q) }
func (q *Queue) Push(value *TreeNode) {
	*q = append(*q, value)
}

func (q *Queue) Pop() *TreeNode {
	old := *q
	n := (*q).Len()
	if n >= 1 {
		*q = old[1:]
	} else {
		*q = make([]*TreeNode, 0)
		return nil
	}
	return old[0]
}

func (q Queue) Reverse() {
	inputLen := q.Len()
	inputMid := inputLen / 2
	for i := 0; i < inputMid; i++ {
		j := inputLen - i - 1
		q[i], q[j] = q[j], q[i]
	}
}

func AreToysBalanced(root *TreeNode) bool {
	if root == nil {
		return false
	}
	return countToys(root.Left) == countToys(root.Right)
}

func countToys(root *TreeNode) int {
	if root == nil {
		return 0
	}
	count := 0
	if root.HasToy {
		count++
	}
	count += countToys(root.Left) + countToys(root.Right)
	return count
}

// func UnrollGarland(root *TreeNode) []bool {
// 	result := make([]bool, 0)
// 	var stack Queue
// 	stack.Push(root)
// 	for i := 0; stack.Len() != 0; i++ {
// 		size := stack.Len()
// 		if i%2 == 0 {
// 			stack.Reverse()
// 		}
// 		for j := 0; j < size; j++ {
// 			node := (&stack).Pop()
// 			result = append(result, node.HasToy)
// 			(&stack).Push(node)
// 		}
// 		if i%2 == 0 {
// 			stack.Reverse()
// 		}
// 		for j := 0; j < size; j++ {
// 			node := (&stack).Pop()
// 			if node.Left != nil {
// 				(&stack).Push(node.Left)
// 			}
// 			if node.Right != nil {
// 				(&stack).Push(node.Right)
// 			}
// 		}
// 	}
// 	return result
// }

func UnrollGarland(root *TreeNode) []bool {
	result := make([]bool, 0)
	var stack Queue
	stack.Push(root)
	for i := 0; stack.Len() != 0; i++ {
		size := stack.Len()
		old := stack
		if i%2 == 0 {
			stack.Reverse()
		}
		for j := 0; j < size; j++ {
			node := (&stack).Pop()
			result = append(result, node.HasToy)
			oldnode := (&old).Pop()
			if oldnode.Left != nil {
				(&stack).Push(oldnode.Left)
			}
			if oldnode.Right != nil {
				(&stack).Push(oldnode.Right)
			}
		}
	}
	return result
}
