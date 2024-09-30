#!/bin/bash

# Función para ordenar números usando el algoritmo de burbuja mejorado
ordenar_numeros() {
    numeros=("$@")
    n=${#numeros[@]}
    for ((i = 0; i < n - 1; i++)); do
        intercambiado=false
        for ((j = 0; j < n - i - 1; j++)); do
            if ((numeros[j] > numeros[j + 1])); then
                # Intercambio de números
                temp=${numeros[j]}
                numeros[j]=${numeros[j + 1]}
                numeros[j + 1]=$temp
                intercambiado=true
            fi
        done
        # Si no se realizaron intercambios, el arreglo ya está ordenado
        if ! $intercambiado; then
            break
        fi
    done
    echo "${numeros[@]}"
}

# Comprobación de los parámetros de entrada
if [[ $# -eq 0 ]]; then
    # Leer números desde el teclado
    echo "Ingrese el número de elementos:"
    read N
    echo "Ingrese los $N números separados por espacios:"
    read -a numeros
elif [[ $# -eq 1 ]]; then
    # Leer números desde un archivo
    archivo=$1
    if [[ -f $archivo ]]; then
        mapfile -t numeros < "$archivo"
    else
        echo "El archivo no existe."
        exit 1
    fi
else
    echo "Uso: $0 [ruta_archivo]"
    exit 1
fi

# Ordenar los números y mostrarlos
ordenados=$(ordenar_numeros "${numeros[@]}")
echo "Números ordenados: $ordenados"
