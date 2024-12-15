import os
import sys
import time
from multiprocessing import Process, Lock

counter = 0
lock = Lock()

def proceso(pid):
    global counter
    while True:
        with lock:
            try:
                with open("contador.txt", "r") as fileRead:
                    counter = int(fileRead.read().strip())
                print(f"{'\t\t' * pid}<Value R: {counter}, PID: {os.getpid()}>")
                counter += 1
                time.sleep(1)
                with open("contador.txt", "w") as fileWrite:
                    fileWrite.write(f"{counter}\n")
                print(f"{'\t\t' * pid}<Value W: {counter}, PID: {os.getpid()}>")
            except FileNotFoundError:
                print("ERR: file operation failed")
                break

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("ERR: no params")
        sys.exit(1)

    N = int(sys.argv[1])

    processes = []
    for i in range(N):
        p = Process(target=proceso, args=(i,))
        p.start()
        processes.append(p)

    for p in processes:
        p.join()
