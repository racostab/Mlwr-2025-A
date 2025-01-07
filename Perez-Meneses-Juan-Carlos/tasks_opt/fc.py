import threading
import time
import random

# Número de filósofos
NUM_FILOSOFOS = 5
tenedores = [threading.Semaphore(1) for _ in range(NUM_FILOSOFOS)]
mutex = threading.Semaphore(4)  # Solo 4 filósofos pueden intentar comer a la vez

def filosofo(num):
    while True:
        print(f"Filósofo {num} está pensando 🤔")
        time.sleep(random.uniform(1, 3))  # Tiempo de pensar
        
        # Intentar tomar tenedores
        mutex.acquire()
        tenedores[num].acquire()
        tenedores[(num + 1) % NUM_FILOSOFOS].acquire()
        
        print(f"Filósofo {num} está comiendo 🍝")
        time.sleep(random.uniform(1, 3))  # Tiempo de comer
        
        # Soltar tenedores
        tenedores[num].release()
        tenedores[(num + 1) % NUM_FILOSOFOS].release()
        mutex.release()
        
        print(f"Filósofo {num} ha terminado de comer y está pensando nuevamente 🤔")

# Crear hilos para cada filósofo
hilos = [threading.Thread(target=filosofo, args=(i,)) for i in range(NUM_FILOSOFOS)]
for hilo in hilos:
    hilo.start()
for hilo in hilos:
    hilo.join()
    
    
    
"""

Resultados:

ilósofo 0 está pensando 🤔
Filósofo 1 está pensando 🤔
Filósofo 3 está pensando 🤔
Filósofo 2 está pensando 🤔
Filósofo 4 está pensando 🤔
Filósofo 1 está comiendo 🍝
Filósofo 1 ha terminado de comer y está pensando nuevamente 🤔
Filósofo 1 está pensando 🤔
Filósofo 0 está comiendo 🍝
Filósofo 0 ha terminado de comer y está pensando nuevamente 🤔
Filósofo 0 está pensando 🤔
Filósofo 4 está comiendo 🍝
Filósofo 4 ha terminado de comer y está pensando nuevamente 🤔
Filósofo 4 está pensando 🤔
Filósofo 3 está comiendo 🍝
Filósofo 3 ha terminado de comer y está pensando nuevamente 🤔
Filósofo 3 está pensando 🤔
Filósofo 2 está comiendo 🍝

"""
