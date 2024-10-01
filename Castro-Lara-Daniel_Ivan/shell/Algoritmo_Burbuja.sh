#!/bin/bash

# Función que implementa el algoritmo de burbuja mejorado
bubble_sort_mejorado() {
    local arr=("$@")
    local n=${#arr[@]}
    local swapped

    for ((i = 0; i < n-1; i++)); do
        swapped=false
        for ((j = 0; j < n-i-1; j++)); do
            if (( arr[j] > arr[j+1] )); then
                # Intercambiar
                temp=${arr[j]}
                arr[j]=${arr[j+1]}
                arr[j+1]=$temp
                swapped=true
            fi
        done
        # Si no se hizo ningún intercambio, salir
        if ! $swapped; then
            break
        fi
    done

    # Imprimir el arreglo ordenado
    echo "${arr[@]}"
}

# Si no hay argumentos, leer números desde el teclado
if [ "$#" -eq 0 ]; then
    read -p "Introduce la cantidad de números a ordenar: " N
    declare -a nums
    echo "Introduce los números:"
    for ((i = 0; i < N; i++)); do
        read nums[$i]
    done
    # Llamar a la función para ordenar los números ingresados
    bubble_sort_mejorado "${nums[@]}"
else
    # Si hay parámetros, el primer argumento es el número de elementos
    N=$1
    shift
    if [ "$#" -ne "$N" ]; then
        echo "Error: El número de números proporcionados no coincide con N."
        exit 1
    fi
    # Ordenar los números proporcionados como argumentos
    bubble_sort_mejorado "$@"
fi
