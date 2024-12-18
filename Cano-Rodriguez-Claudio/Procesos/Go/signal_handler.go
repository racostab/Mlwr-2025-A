package main

import (
	"fmt"
	"os"
	"os/signal"
	"syscall"
)

func main() {
	// Create a channel to receive signals
	sigChan := make(chan os.Signal, 1)
	signal.Notify(sigChan, syscall.SIGUSR1)

	fmt.Println("Esperando señales... (envía SIGUSR1 para probar)")

	// Block until a signal is received
	sig := <-sigChan
	fmt.Printf("Señal recibida: %v\n", sig)
}
