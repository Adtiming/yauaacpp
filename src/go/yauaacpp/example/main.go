package main

import (
	"fmt"
	yauaacpp "yauaacpp"
)

func main() {
	var ua = "Mozilla/5.0 (Linux; Android 10; U705AC) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/110.0.0.0 Mobile Safari/537.36"
	evironment, browser := yauaacpp.GetEnvirenmentBrowser(ua)
	fmt.Printf("evironment=%d,browser=%d\n", evironment, browser)
	// yauaacpp.CacheSize(100)
	// evironment, browser := yauaacpp.GetEnvirenmentBrowser(ua)
	// fmt.Printf("evironment=%d,browser=%d\n", evironment, browser)

}
