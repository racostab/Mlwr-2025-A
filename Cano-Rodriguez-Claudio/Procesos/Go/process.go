package main

import (
	"fmt"
	"os"
	"sync"
	"time"
)

const MAX = 5 // Countdown limit

func countdown(wg *sync.WaitGroup, id int) {
	defer wg.Done()
	for k := MAX; k >= 1; k-- {
		fmt.Printf("Child Process [%d]: Countdown = %d\n", os.Getpid(), k)
		time.Sleep(500 * time.Millisecond)
	}
}

func main() {
	var wg sync.WaitGroup

	for i := 1; i <= 3; i++ {
		wg.Add(1)
		go countdown(&wg, i)
	}

	wg.Wait()
}
