import threading
import os
import time

def child_thread():
    while True:
        print(f"\t\t\tH={os.getpid()}")
        time.sleep(0.5)  # Optional delay

if __name__ == "__main__":
    # Create and start the child thread
    thread = threading.Thread(target=child_thread)
    thread.start()

    # Main thread
    while True:
        print(f"\tP={os.getpid()}")
        time.sleep(0.5)  # Optional delay
