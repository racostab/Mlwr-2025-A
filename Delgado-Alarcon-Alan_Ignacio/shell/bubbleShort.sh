#!/bin/bash

function optimized_bubble_sort() {
    local array=("$@")
    local n=${#array[@]}
    local swapped

    for ((i = 0; i < n; i++)); do
    swapped=0
    for ((j = 0; j < n - i - 1; j++)); do
        if ((array[j] > array[j+1])); then
            # Intercambiar
            temp=${array[j]}
            array[j]=${array[j+1]}
            array[j+1]=$temp
            swapped=1
        fi
    done

    if ((swapped == 0)); then
        break
    fi
    done

    echo "${array[@]}"
}

# Leer números desde el teclado
function read_numbers_from_input() {
    read -p "Ingresa el número de elementos: " N
    declare -a numbers
    echo "Ingresa $N números separados por espacios:"
    read -a numbers
    optimized_bubble_sort "${numbers[@]}"
}

# Leer números desde el archivo
function read_numbers_from_file() {
    local file_path=$1
    if [[ -f "$file_path" ]]; then
        mapfile -t numbers < "$file_path"
        optimized_bubble_sort "${numbers[@]}"
    else
        echo "El archivo no existe."
    fi
}

# Verificar si se pasó un parámetro (ruta de archivo)
if [[ $# -eq 1 ]]; then
    read_numbers_from_file "$1"
else
    read_numbers_from_input
fi
