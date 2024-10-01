#!/bin/bash

# Función para el algoritmo de burbuja mejorado
burbuja_mejorado() {
    local arr=("$@")
    local n=${#arr[@]}
    local i j swapped

    for ((i = 0; i < n - 1; i++)); do
        swapped=0
        for ((j = 0; j < n - i - 1; j++)); do
            if (( arr[j] > arr[j + 1] )); then
                # Intercambiar
                temp=${arr[j]}
                arr[j]=${arr[j + 1]}
                arr[j + 1]=$temp
                swapped=1
            fi
        done
        # Si no se hizo ningún intercambio, la lista ya está ordenada
        if (( swapped == 0 )); then
            break
        fi
    done
    echo "${arr[@]}"
}

# Si se pasa un parámetro, se asume que es un archivo
if [ $# -eq 1 ]; then
    if [ -f "$1" ]; then
        numeros=($(cat "$1"))
    else
        echo "El archivo proporcionado no existe."
        exit 1
    fi
# Si no hay parámetros, se piden los números al usuario
elif [ $# -eq 0 ]; then
    read -p "Introduce la cantidad de números a ordenar: " N
    echo "Introduce $N números:"
    for ((i = 0; i < N; i++)); do
        read num
        numeros+=($num)
    done
else
    echo "Uso: $0 [archivo]"
    exit 1
fi

# Llamar a la función para ordenar los números
ordenados=$(burbuja_mejorado "${numeros[@]}")
echo "Números ordenados: $ordenados"

