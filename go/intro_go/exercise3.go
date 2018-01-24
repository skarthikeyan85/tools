package main

import "fmt"
import "time"
import "math/rand"

func exercise3() {
  var x [5]int
  i := 0
  for i < len(x) {
    //fmt.Scanf("%d", &x[i])
    r1 := rand.New(rand.NewSource(time.Now().UnixNano()))
    x[i] = r1.Intn(100)
    i++
  }
  for _, value := range x {
    fmt.Println( value)
  }

  slice1 := []int{3,4,13}
  fmt.Println(slice1)
  slice1 = append(slice1, 102,104)

  slice2 := make([]int, 2)
  copy(slice2, slice1)
  slice2[1] = 999
  fmt.Println(slice2)

  map1 := make(map[string]int)
  map1["key"] = 10
  fmt.Println(map1)
  fmt.Println(len(map1))
  delete(map1, "key")
  fmt.Println(map1)
  fmt.Println(map1["key"])
}
