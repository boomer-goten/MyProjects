package present

import (
	"container/heap"
	"errors"
)

type Present struct {
	Value int
	Size  int
}

type PresentHeap []*Present

func (ph PresentHeap) Len() int {
	return len(ph)
}

func (ph PresentHeap) Swap(i, j int) {
	ph[i], ph[j] = ph[j], ph[i]
}

func (ph PresentHeap) Less(i, j int) bool {
	if ph[i].Value > ph[j].Value {
		return true
	} else if ph[i].Value == ph[j].Value {
		return ph[i].Size < ph[j].Size
	}
	return false
}

func (ph *PresentHeap) Push(x any) {
	present := x.(*Present)
	*ph = append(*ph, present)
}

func (ph *PresentHeap) Pop() any {
	old := *ph
	n := len(old)
	item := old[n-1]
	old[n-1] = nil // avoid memory leak
	*ph = old[0 : n-1]
	return item
}

func GetNCoolestPresents(slicePresents PresentHeap, n int) (PresentHeap, error) {
	if slicePresents.Len() < n || n < 0 {
		return nil, errors.New("Error n size")
	}
	sortedSlice := make([]*Present, 0)
	heap.Init(&slicePresents)
	for i := 0; i < n; i++ {
		sortedSlice = append(sortedSlice, heap.Pop(&slicePresents).(*Present))
	}
	return sortedSlice, nil
}

func GrabPresents(slicePresents PresentHeap, maxWeight int) Present {
	len := slicePresents.Len()
	weights := make([][]int, len+1)
	for i := range weights {
		weights[i] = make([]int, maxWeight+1)
	}
	for i := 1; i <= len; i++ {
		for j := 1; j <= maxWeight; j++ {
			if slicePresents[i-1].Size <= j {
				weights[i][j] = max(weights[i-1][j], slicePresents[i-1].Value+weights[i-1][j-slicePresents[i-1].Size])
			} else {
				weights[i][j] = weights[i-1][j]
			}
		}
	}
	return Present{weights[len][maxWeight], maxWeight}
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}
