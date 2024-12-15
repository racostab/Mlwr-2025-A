import sys

def main():
    argc = len(sys.argv)
    print(f"argc= {argc}")
    if argc == 1:
        return 0
    else:
        return argc

if __name__ == "__main__":
    exit(main())
