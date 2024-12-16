import threading

NUM_THREADS = 5

def print_hello(thread_id):
    print(f"Hello World! It's me, thread #{thread_id}!")

threads = []
for t in range(NUM_THREADS):
    print(f"In main: creating thread {t}")
    thread = threading.Thread(target=print_hello, args=(t,))
    threads.append(thread)
    thread.start()

for thread in threads:
    thread.join()
