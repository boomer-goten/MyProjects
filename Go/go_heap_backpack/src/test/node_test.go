package test

import (
	"NodeTest/internal/node"
	"NodeTest/internal/present"
	"fmt"
	"testing"
)

func TestAreToysBalancedFir(t *testing.T) {
	val_0 := node.TreeNode{false, nil, nil}
	val_1 := node.TreeNode{true, nil, nil}
	val_3 := node.TreeNode{false, &val_0, &val_1}
	val_2 := node.TreeNode{true, nil, nil}
	val_root := node.TreeNode{false, &val_2, &val_3}
	result := node.AreToysBalanced(&val_root)
	expect := true
	if result != expect {
		t.Errorf("test areToysBalanced#1 need %#v, but got %#v", expect, result)
	} else {
		fmt.Printf("PASSED TEST %s\n", t.Name())
	}
}

func TestAreToysBalancedSec(t *testing.T) {
	val_0 := node.TreeNode{true, nil, nil}
	val_1 := node.TreeNode{false, nil, nil}
	val_2 := node.TreeNode{true, nil, nil}
	val_3 := node.TreeNode{true, nil, nil}
	val_4 := node.TreeNode{true, &val_0, &val_1}
	val_5 := node.TreeNode{false, &val_2, &val_3}
	val_root := node.TreeNode{true, &val_4, &val_5}
	result := node.AreToysBalanced(&val_root)
	expect := true
	if result != expect {
		t.Errorf("test areToysBalanced#1 need %#v, but got %#v", expect, result)
	} else {
		fmt.Printf("PASSED TEST %s\n", t.Name())
	}
}

func TestAreToysBalancedThr(t *testing.T) {
	val_0 := node.TreeNode{true, nil, nil}
	val_1 := node.TreeNode{false, nil, nil}
	val_root := node.TreeNode{true, &val_0, &val_1}
	result := node.AreToysBalanced(&val_root)
	expect := false
	if result != expect {
		t.Errorf("test areToysBalanced#1 need %#v, but got %#v", expect, result)
	} else {
		fmt.Printf("PASSED TEST %s\n", t.Name())
	}
}

func TestAreToysBalancedFou(t *testing.T) {
	val_0 := node.TreeNode{true, nil, nil}
	val_1 := node.TreeNode{true, nil, nil}
	val_2 := node.TreeNode{true, nil, &val_0}
	val_3 := node.TreeNode{false, nil, &val_1}
	val_root := node.TreeNode{true, &val_2, &val_3}
	result := node.AreToysBalanced(&val_root)
	expect := false
	if result != expect {
		t.Errorf("test areToysBalanced#1 need %#v, but got %#v", expect, result)
	} else {
		fmt.Printf("PASSED TEST %s\n", t.Name())
	}
}

func TestUnrollGarlandFir(t *testing.T) {
	val_0 := node.TreeNode{true, nil, nil}
	val_1 := node.TreeNode{false, nil, nil}
	val_2 := node.TreeNode{true, nil, nil}
	val_3 := node.TreeNode{true, nil, nil}
	val_4 := node.TreeNode{true, &val_0, &val_1}
	val_5 := node.TreeNode{false, &val_2, &val_3}
	val_root := node.TreeNode{true, &val_4, &val_5}
	result := node.UnrollGarland(&val_root)
	expect := make([]bool, 0)
	expect = append(expect, true, true, false, true, true, false, true)
	if compareSlices(result, expect) != true {
		t.Errorf("test %s need %#v, but got %#v", t.Name(), expect, result)
	} else {
		fmt.Printf("PASSED TEST %s\n", t.Name())
	}
}

func compareSlices(a, b []bool) bool {
	if len(a) != len(b) {
		return false
	}

	for i := 0; i < len(a); i++ {
		if a[i] != b[i] {
			return false
		}
	}

	return true
}

func TestGetNCoolsetPresents(t *testing.T) {
	var presents present.PresentHeap
	presents = append(presents, &present.Present{5, 1}, &present.Present{4, 5}, &present.Present{3, 1}, &present.Present{5, 2})
	value, err := present.GetNCoolestPresents(presents, 2)
	if err != nil {
		t.Error(err)
	}
	expect := make([]*present.Present, 0)
	expect = append(expect, &present.Present{5, 1}, &present.Present{5, 2})
	if compareHeap(value, expect) != true {
		t.Errorf("test %s need %#v, but got %#v", t.Name(), expect, value)
	} else {
		fmt.Printf("PASSED TEST %s\n", t.Name())
	}
}

func compareHeap(old, new present.PresentHeap) bool {
	if len(old) != len(new) {
		return false
	}
	for i := 0; i < len(old); i++ {
		if old[i].Size != new[i].Size || old[i].Value != new[i].Value {
			return false
		}
	}

	return true
}

func TestGrabPresents(t *testing.T) {
	var presents present.PresentHeap
	presents = append(presents, &present.Present{2000, 3}, &present.Present{3000, 4}, &present.Present{1500, 1})
	value := present.GrabPresents(presents, 4)
	if value.Size == 4 && value.Value == 3500 {
		fmt.Printf("PASSED TEST %s\n", t.Name())
	} else {
		t.Errorf("test %s expect size = %d, but got %#v and expect Value = %d, but got %d", t.Name(), 4, value.Size, 3500, value.Value)
	}
}
