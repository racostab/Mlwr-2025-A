import os
import time

def hijo():
    time.sleep(2)
    print("quien?... te pregunto")

def padre():
    time.sleep(10)
    os.system("ps")
    print("hijos de...")

for i in range(1, 4):
    try:
        pid = os.fork()
        if pid == 0: 
            hijo()
            os._exit(0)
        else: 
            padre()
    except OSError as e:
        print("ERROR")
        exit(1)
