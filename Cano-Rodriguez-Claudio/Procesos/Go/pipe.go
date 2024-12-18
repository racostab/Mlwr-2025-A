package main

import (
	"fmt"
	"os"
)

func main() {
	pr, pw, _ := os.Pipe() // Create a pipe
	message := "abcde"
	buffer := make([]byte, 5)

	if pid, _ := os.ForkExec("/proc/self/exe", nil, nil); pid == 0 { // Child process
		pw.Close()              // Close write end
		pr.Read(buffer)         // Read from pipe
		fmt.Printf("H: %s\n", string(buffer))
		pr.Close()
	} else { // Parent process
		pr.Close()              // Close read end
		pw.Write([]byte(message))
		fmt.Printf("P: %s\n", message)
		pw.Close()
	}
}
