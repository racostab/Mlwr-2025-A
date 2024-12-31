: '
Programa en Bash mide el tiempo de ejecución de un programa o script específico, 
calcula los tiempos de usuario y sistema, y los presenta en formato numérico flotante (en segundos). 
Además, muestra la suma de ambos tiempos.
'

#!/bin/bash

# Verificar si se proporcionó un archivo como argumento
if [ -z "$1" ]; then
  echo "Se debe ingresar argumentos de la siguiente manera: $0 [argumentos del script]"
  exit 1
fi

# Captura el nombre del script y los posibles argumentos
script_to_run=$1
shift # Elimina el primer argumento (nombre del script) de la lista de argumentos
args="$@"

# Ejecuta el script proporcionado con time y redirige la salida de error (tiempos) a un archivo temporal
{ time ./$script_to_run $args; } 2> tiempos.txt

# Extrae los tiempos de "user" y "sys" usando grep y awk
user_time=$(grep "user" tiempos.txt | awk '{print $2}')
sys_time=$(grep "sys" tiempos.txt | awk '{print $2}')

# Convierte los tiempos a formato numérico flotante usando bc
user_time_numeric=$(echo $user_time | sed 's/m/:/' | awk -F: '{print ($1 * 60) + $2}')
sys_time_numeric=$(echo $sys_time | sed 's/m/:/' | awk -F: '{print ($1 * 60) + $2}')

# Calcula la suma de los tiempos
total_time=$(echo "$user_time_numeric + $sys_time_numeric" | bc)

# Muestra los resultados
echo "Tiempo de usuario: $user_time_numeric segundos"
echo "Tiempo de sistema: $sys_time_numeric segundos"
echo "Tiempo total (user + sys): $total_time segundos"


# Limpia el archivo temporal
rm tiempos.txt
