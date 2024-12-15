import os
import time

MAX = 5
SLEEP_DURATION = 0.5  # 500ms

for i in range(1, 4):
    try:
        pid = os.fork()
        if pid == 0: 
            for k in range(MAX, 0, -1):
                print(f"H= {os.getpid()}")
                time.sleep(SLEEP_DURATION)
            os._exit(0)
    except OSError as e:
        print("ERROR")
        exit(1)
