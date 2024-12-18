import os
import sys

# Check if the program has the correct number of arguments
if len(sys.argv) != 2:
    print("ERR: no params")
    sys.exit(1)

N = int(sys.argv[1])  # Convert argument to integer

# Loop to create N child processes
for i in range(N):
    try:
        pid = os.fork()
        if pid == 0:
            # Child process
            print(f"Child Process PID: {os.getpid()}")
            os._exit(0)  # Exit child process
    except OSError:
        print("ERROR: Failed to fork")

# Parent process prints its PID
print(f"Parent Process PID: {os.getpid()}")
