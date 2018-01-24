package main

import (
  "fmt"
  "math"
  "strings"
  "os"
  "path/filepath";
  "container/list";
)

type Circle struct {
    x, y, r float64
}

type Shape interface {
    area() float64
}

func (c *Circle) area() float64 {
    return math.Pi * c.r*c.r
}

func totalArea(circles ...Circle) float64 {
    var total float64
    for _, c := range circles {
        total += c.area()
    }
    return total
}

func exercise4() {
  //c := new(Circle)
  c := &Circle{0, 0, 5}
  fmt.Println(c)
  fmt.Println(*c)
  fmt.Println(totalArea(*c))
  fmt.Println(strings.Count("testtest", "test"))
  fmt.Println(strings.Split("a-b-c-d-e", "-"))
  filepath.Walk(".", func(path string, info os.FileInfo, err error) error {
        fmt.Println(path)
        return nil
    })

  var x list.List

  x.PushBack(1)
  x.PushBack(2)
  x.PushBack(3)

  for e := x.Front(); e != nil; e=e.Next() {
      fmt.Println(e.Value.(int))
  }
}
