package main

import (
	"fmt"
	"os"
	"syscall"
	"unsafe"
)

type Message struct {
	Type int64
	Text [100]byte
}

func main() {
	key, _ := syscall.Ftok("progfile", 65)

	// Create message queue
	msgid, _, err := syscall.Syscall(syscall.SYS_MSGGET, uintptr(key), 0666|syscall.IPC_CREAT, 0)
	if err != 0 {
		fmt.Println("Error creating message queue")
		os.Exit(1)
	}

	var message Message
	message.Type = 1

	// Prompt user for input
	fmt.Print("Write data >> ")
	fmt.Scanln(&message.Text)

	// Send message
	_, _, err = syscall.Syscall(syscall.SYS_MSGSND, msgid, uintptr(unsafe.Pointer(&message)), 100, 0)
	if err != 0 {
		fmt.Println("Error sending message")
		os.Exit(1)
	}

	fmt.Printf("Data sent is: %s\n", message.Text)
}
