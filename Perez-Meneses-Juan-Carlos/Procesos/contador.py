import os
import time
import fcntl

# python ./contador.py

def proceso(pid):
    i = 0
    while True:
        try:
            with open("contador.txt", "r+") as f:
                fcntl.flock(f, fcntl.LOCK_EX)
                i = int(f.read().strip())
                i += 1
                f.seek(0)
                f.write(str(i))
                fcntl.flock(f, fcntl.LOCK_UN)
                print(f"<PID: {os.getpid()}, Valor del contador: {i}>")
                time.sleep(0.1)
        except Exception as e:
            print(f"Error: {e}")
            return

if __name__ == "__main__":
    with open("contador.txt", "w") as f:
        f.write("0")
    
    for i in range(2):
        pid = os.fork()
        if pid == 0:
            proceso(i)
            os._exit(0)
    
    for _ in range(2):
        os.wait()
