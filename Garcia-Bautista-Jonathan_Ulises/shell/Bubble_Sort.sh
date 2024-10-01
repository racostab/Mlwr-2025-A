#!/bin/bash

# Función para realizar Bubble Sort optimizado
bubble_sort() {
    local -n arr=$1
    local n=${#arr[@]}
    local swapped

    for ((i = 0; i < n; i++)); do
        swapped=0
        for ((j = 0; j < n - i - 1; j++)); do
            if (( arr[j] > arr[j+1] )); then
                temp=${arr[j]}
                arr[j]=${arr[j+1]}
                arr[j+1]=$temp
                swapped=1
            fi
        done
        if (( swapped == 0 )); then
            break
        fi
    done
}

# Verificar si se proporcionó un archivo como argumento
if [ $# -eq 0 ]; then
    # Leer números desde el teclado
    read -p "Ingresa el número de elementos (N): " N
    numbers=()
    for ((i = 0; i < N; i++)); do
        read -p "Ingrese el número $((i + 1)): " number
        numbers+=($number)
    done
else
# Leer números desde el archivo proporcionado
    file_path="$1"
    if [ ! -f "$file_path" ]; then
        echo "El archivo no existe."
        exit 1
    fi
    mapfile -t numbers < "$file_path"
fi

# Ordenar los números usando Bubble Sort optimizado
bubble_sort numbers

# Imprimir los números ordenados
echo "Números ordenados: ${numbers[@]}"
