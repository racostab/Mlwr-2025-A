# Directorio de prueba
mkdir -p archivos_prueba
cd archivos_prueba

# Bucle para crear archivos con nombres de longitud de 1 hasta 255 caracteres
for i in $(seq 1 25); do
    # Crea un nombre de archivo con "a" repetido i veces
    nombre_archivo=$(printf 'a%.0s' $(seq 1 $i))
    
    # Intenta crear el archivo
    touch "$nombre_archivo"
    
    # Verifica si el archivo fue creado
    if [ -f "$nombre_archivo" ]; then
        echo "Archivo creado con nombre de $i caracteres"
    else
        echo "No se pudo crear el archivo con nombre de $i caracteres"
        break
    fi
done

# Regresa al directorio anterior
cd ..
