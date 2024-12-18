import os

def main():
    r, w = os.pipe()  # Create a pipe
    message = "abcde"

    pid = os.fork()
    if pid == 0:  # Child process
        os.close(w)  # Close write end
        rbuf = os.read(r, 5).decode()
        print(f"H: {rbuf}")
        os.close(r)
    else:  # Parent process
        os.close(r)  # Close read end
        os.write(w, message.encode())
        print(f"P: {message}")
        os.close(w)

if __name__ == "__main__":
    main()
