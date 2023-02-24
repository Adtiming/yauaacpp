package main

import (
	"fmt"
	yauaacpp "yauaacpp"
)

func main() {
	var ua = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36"
	evironment, browser := yauaacpp.GetEnvirenmentBrowser(ua)
	fmt.Printf("evironment=%d,browser=%d\n", evironment, browser)
}
