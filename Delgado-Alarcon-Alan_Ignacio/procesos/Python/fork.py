import os
import sys

if len(sys.argv) != 2:
    print("ERR: no params")
    sys.exit(1)

try:
    N = int(sys.argv[1])
except ValueError:
    print("ERR: invalid parameter")
    sys.exit(1)

for i in range(1, N + 1):
    try:
        if os.fork() == -1:
            print("ERROR")
    except OSError:
        print("ERROR")
print(os.getpid())
