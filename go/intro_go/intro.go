package main

import "fmt"

var x string = "Hello, World"

func main() {
    fmt.Printf("hello world!!\n")
    fmt.Println("1 + 1 =", 1.0 + 1.0)
    fmt.Println("Hello, World"[1])
    fmt.Println("Hello, " + "World")
    fmt.Println(len("Hello, World"))
    fmt.Println(true || false)
    fmt.Println(!true)
    fmt.Println(x)

    /*fmt.Print("Enter a number: ")
    var input float64
    fmt.Scanf("%f", &input)*/
    input := 25.0
    output := input * 2
    fmt.Println(output)

    var (a = 5;b = 10;c = 15)
    fmt.Println(a,b,c)

    exercise2()
    exercise3()
    exercise4()
    exercise5()
}
