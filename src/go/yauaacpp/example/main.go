package main

import (
	"fmt"
	yauaacpp "yauaacpp"
)

func main() {
	yauaa := new(yauaacpp.Yauaa)

	fmt.Printf("init with cache\n")
	yauaa.WithCache(100)
	fmt.Printf("init with cache is over\n")

	var ua = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36"
	evironment, browser := yauaa.GetEnvirenmentBrowser(ua)
	fmt.Printf("evironment=%d,browser=%d\n", evironment, browser)
}
