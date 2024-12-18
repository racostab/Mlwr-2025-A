package main

import (
	"fmt"
	"os"
	"os/exec"
	"strconv"
)

func main() {
	// Check if the program has the correct number of arguments
	if len(os.Args) != 2 {
		fmt.Println("ERR: no params")
		return
	}

	N, err := strconv.Atoi(os.Args[1]) // Convert argument to integer
	if err != nil {
		fmt.Println("ERROR: Invalid number")
		return
	}

	// Loop to create N processes
	for i := 1; i <= N; i++ {
		cmd := exec.Command("sleep", "1") // Example command to simulate a process
		err := cmd.Start()
		if err != nil {
			fmt.Println("ERROR: Failed to start process")
		} else {
			fmt.Printf("Started Process PID: %d\n", cmd.Process.Pid)
		}
	}
}
