package main

import "fmt"

func f1a(n int) {
    for i := 0; i < 10; i++ {
        fmt.Println(n, ":", i)
    }
}

func exercise5() {
  for i := 0; i < 10; i++ {
      go f1a(i)
  }
  var input string
  fmt.Scanln(&input)
}
