import os
import sys
import time

# python ./pipes_2.py

def main():
    fd = os.pipe()
    tam = 5
    pid = os.fork()
    if pid == -1:
        print("Error de creación")
        sys.exit(1)
    
    elif pid == 0:
        os.close(fd[1])
        buf = os.read(fd[0], tam)
        os.close(fd[0])
        print(f"H= {buf.decode()}")
        os._exit(0)

    else:
        time.sleep(1)
        os.close(fd[0])
        os.write(fd[1], b"abcde")
        os.close(fd[1])
        print(f"P= abcde")
        os.wait()

if __name__ == "__main__":
    main()
