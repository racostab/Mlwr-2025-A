#!/bin/bash

# Función para ordenar números usando el algoritmo de burbuja mejorado
bubble_sort() {
  local arr=("$@")
  local n=${#arr[@]}
  local swapped

  for ((i = 0; i < n-1; i++)); do
    swapped=0
    for ((j = 0; j < n-i-1; j++)); do
      if (( arr[j] > arr[j+1] )); then
        # Intercambia los números
        temp=${arr[j]}
        arr[j]=${arr[j+1]}
        arr[j+1]=$temp
        swapped=1
      fi
    done
    # Si no hubo intercambio, el array ya está ordenado
    if (( swapped == 0 )); then
      break
    fi
  done

  echo "${arr[@]}"
}

# Función para leer los números y ejecutar el ordenamiento
run_sorting() {
  # Pedir N y los números si no se pasan como argumento
  read -p "Introduce el número de elementos N: " N
  numbers=()
  for ((i = 0; i < N; i++)); do
    read -p "Introduce un número: " num
    numbers+=("$num")
  done

  # Llamar a la función de ordenamiento
  sorted_numbers=$(bubble_sort "${numbers[@]}")
  echo "Números ordenados: $sorted_numbers"
}

# Bucle para permitir que el usuario repita o salga
while true; do
  run_sorting
  
  # Preguntar si el usuario quiere ordenar otra vez o salir
  read -p "¿Quieres ordenar otra vez? (s/n): " option
  if [[ $option != "s" ]]; then
    echo "Saliendo..."
    break
  fi
done
