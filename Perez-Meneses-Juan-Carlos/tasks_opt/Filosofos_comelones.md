# Problema de los Filósofos Comelones
El Problema de los Filósofos Comelones es un clásico en la programación concurrente e ilustra los desafíos de la sincronización en sistemas operativos y multihilo. Fue planteado por Edsger Dijkstra en 1965.

1) Descripción del Problema: 
Cinco filósofos se sientan alrededor de una mesa circular para comer espagueti. Cada filósofo alterna entre dos estados:

* Pensar 🤔
* Comer 🍝
  
2) Condiciones:
* Cada filósofo tiene un plato de espagueti frente a él.
* Para comer, necesita dos tenedores (uno a su izquierda y otro a su derecha).
* Hay exactamente cinco tenedores, uno entre cada par de filósofos.
* Un filósofo puede tomar un tenedor si este no está siendo usado por su vecino.
* Solo puede comer si logra obtener ambos tenedores al mismo tiempo.


3) Problemas Clásicos:
- Interbloqueo (Deadlock): Si todos los filósofos toman un tenedor a su izquierda al mismo tiempo, ninguno podrá comer porque nadie soltará el tenedor que ya tiene.
- Hambre (Starvation): Algunos filósofos pueden quedarse eternamente esperando si no obtienen los dos tenedores.
- Competencia (Livelock): Los filósofos intentan comer, pero ceden constantemente el tenedor sin lograr comer.


🛠️ Soluciones Clásicas:

1️⃣ Jerarquía de Recursos
- A cada tenedor se le asigna un número.
- Los filósofos deben tomar siempre el tenedor de menor número antes que el mayor.
- Evita el interbloqueo.
  
2️⃣ Permisos (Semáforos):
- Se utiliza un semáforo global con un número máximo de permisos (ej. 4 permisos para 5 filósofos).
- Así, nunca todos los filósofos podrán tomar un tenedor al mismo tiempo.

3️⃣ Filósofo Asimétrico:
- Un filósofo toma el tenedor de la izquierda primero y otro toma el de la derecha primero.
- Reduce las posibilidades de interbloqueo.
