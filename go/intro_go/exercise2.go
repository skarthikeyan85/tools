package main

import "fmt"

func f2() (r int) {
    r = 1395
    return
}

func exercise2() {
    fmt.Printf("Whatever\n")
    i := 1
    for i <= 10 {
      switch i {
        case 1: fmt.Print("One ")
        case 2: fmt.Print("Two ")
        default: fmt.Print("Unkn ")
      }
      if (i%2 == 0) {
        fmt.Println(i, "even")
      } else {
        fmt.Println(i, "odd")
      }
      i++
    }
    fmt.Println(f2())
}
