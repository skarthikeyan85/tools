/*
package main

import (
    "fmt"
    "time"
)

func main() {
    c1 := make(chan string)
    c2 := make(chan string)

    go func() {
        for {
            c1 <- "from 1"
            time.Sleep(time.Second * 2)
        }
    }()

    go func() {
        for {
            c2 <- "from 2"
            time.Sleep(time.Second * 3)
        }
    }()

    go func() {
        for {
            select {
            case msg1 := <- c1:
                fmt.Println(msg1)
            case msg2 := <- c2:
                fmt.Println(msg2)
            }
        }
    }()

    var input string
    fmt.Scanln(&input)
}*/

package main

import (
    "fmt"
    "io/ioutil"
    "net/http"
)

type HomePageSize struct {
    URL  string
    Size int
}

func main() {
    urls := []string{
        "http://www.apple.com",
        "http://www.amazon.com",
        "http://www.google.com",
        "http://www.microsoft.com",
    }

    results := make(chan HomePageSize)

    for _, url := range urls {
        go func(url string) {
            res, err := http.Get(url)
            if err != nil {
                panic(err)
            }
            defer res.Body.Close()

            bs, err := ioutil.ReadAll(res.Body)
            if err != nil {
                panic(err)
            }

            results <- HomePageSize{
                URL:  url,
                Size: len(bs),
            }
        }(url)
    }

    var biggest HomePageSize

    for range urls {
        result := <-results
        if result.Size > biggest.Size {
            biggest = result
        }
        fmt.Println("The current home page:", result.URL, result.Size)
    }

    fmt.Println("The biggest home page:", biggest.URL)
}
