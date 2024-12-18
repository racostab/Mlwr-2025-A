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

	// Receive message
	_, _, err = syscall.Syscall6(syscall.SYS_MSGRCV, msgid, uintptr(unsafe.Pointer(&message)), 100, 1, 0, 0)
	if err != 0 {
		fmt.Println("Error receiving message")
		os.Exit(1)
	}

	fmt.Printf("Data received is: %s\n", string(message.Text[:]))

	// Remove message queue
	syscall.Syscall(syscall.SYS_MSGCTL, msgid, syscall.IPC_RMID, 0)
}
