import os
import sys
import struct

# python ./pipes.py

def main():
    fd = os.pipe()
    i = 0

    try:
        while True:
            buf = struct.pack('i', i)
            os.write(fd[1], buf)
            print(i, end=' ', flush=True)
            i += 1
    except KeyboardInterrupt:
        print("\nPrograma interrumpido")
        sys.exit(0)

if __name__ == "__main__":
    main()
