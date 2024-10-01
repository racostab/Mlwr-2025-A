#!/bin/bash

# Función que ordena e imprime los números
ordenar_numeros() {
    numeros=("$@")
    # Ordenar los números
    IFS=$'\n' ordenados=($(sort -n <<<"${numeros[*]}")) #Leer datos eneros pero a manera de salto de linea (delimitador) y se almacena en ordenados
    unset IFS
    echo "Números ordenados: ${ordenados[@]}" #impresión en terminal de los números ordenados
}

# Verificar si se ha proporcionado un argumento
if [ $# -eq 0 ]; then  #Si el numero de argumentos pasados al script es 0  entonces pide los números manualmente
    read -p "Ingresa la cantidad de números a ordenar: " N  #Entrada de datos  que se almacenara en la variable N

    # Comprobar si N es un número positivo
    if ! [[ $N =~ ^[0-9]+$ ]] || [ $N -le 0 ]; then   #Expresión regular que pregunta que solo haya números enteros positivos
        echo "Por favor, ingresa un número positivo válido."
        exit 1 #La salida uno termina el script con un error
    fi  #Cierra sección del if

    # Leer los números desde el teclado
    numeros=()   #Array vacío que almacenara los numeros
    for ((i = 1; i <= N; i++)); do   #for que se ejecuta N veces desde 1 para solicitar numeros
        read -p "Ingresa el número $i: " num
        if ! [[ $num =~ ^[0-9]+$ ]]; then
            echo "Por favor, ingresa solo números enteros positivos."
            exit 1
        fi
        numeros+=("$num")  #Si el número es valido entonces se le suma al array
    done  # fin del bucle for
        # Ordenar y mostrar los números
    ordenar_numeros "${numeros[@]}"  #Llama la función solicitandole los numeros del array

elif [ $# -eq 1 ]; then #si se proporcionó un argumento de texto con los números
    archivo=$1

    # Verificar si el archivo existe
    if [ ! -f "$archivo" ]; then
        echo "El archivo $archivo no existe."
        exit 1
    fi

    # Leer los números del archivo
    numeros=()
    while IFS= read -r linea; do   #Lectura línea por línea del archivo de texto
        if ! [[ $linea =~ ^[0-9]+$ ]]; then  #verificación línea por línea que sea entero positivo
            echo "El archivo contiene una línea que no es un número entero positivo: $linea"
            exit 1
        fi
        numeros+=("$linea")
    done < "$archivo"

    # Ordenar y mostrar los números
    ordenar_numeros "${numeros[@]}"
elif [ $# -eq 1 ]; then #si se ´proporcionó un argumento de texto con los números
    archivo=$1

    # Verificar si el archivo existe
    if [ ! -f "$archivo" ]; then
        echo "El archivo $archivo no existe."
        exit 1
    fi

    # Leer los números del archivo
    numeros=()
    while IFS= read -r linea; do   #Lectura línea por línea del archivo de texto
        if ! [[ $linea =~ ^[0-9]+$ ]]; then  #verificación línea por línea que sea entero positivo
            echo "El archivo contiene una línea que no es un número entero positivo: $linea"
            exit 1
        fi
        numeros+=("$linea")
    done < "$archivo"

    # Ordenar y mostrar los números
    ordenar_numeros "${numeros[@]}"

else
    echo "Solo acepta un argumento como el siguiente: $0 [archivo]"  #Si el script recibe mas de un argumento muestra como se debe de colocar el  d>    exit 1

fi
