package main

import (
	"fmt"
	"os"
	"time"
)

func childThread() {
	for {
		fmt.Printf("\t\t\tH=%d\n", os.Getpid())
		time.Sleep(500 * time.Millisecond) // Optional delay
	}
}

func main() {
	// Start a goroutine (child thread)
	go childThread()

	// Main thread
	for {
		fmt.Printf("\tP=%d\n", os.Getpid())
		time.Sleep(500 * time.Millisecond) // Optional delay
	}
}
