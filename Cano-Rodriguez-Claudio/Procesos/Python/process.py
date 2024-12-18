import os
import time

MAX = 5  # Countdown limit

for i in range(3):  # Create 3 child processes
    pid = os.fork()

    if pid == 0:  # Child process
        for k in range(MAX, 0, -1):
            print(f"Child Process [{os.getpid()}]: Countdown = {k}")
            time.sleep(0.5)  # Sleep for 500ms
        os._exit(0)  # Terminate child process

# Parent process exits
