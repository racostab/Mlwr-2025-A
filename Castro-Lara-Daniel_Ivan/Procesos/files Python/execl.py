'''
Programa equivalente a Execl
$ python3 exec.py
'''

import os

def main():

    executable = "/bin/ls"
    
    args = [executable, "-l", "-a"]

    print("Before calling execl...")

    os.execl(executable, *args)

    print("This line will not be printed!")

if __name__ == "__main__":
    main()

