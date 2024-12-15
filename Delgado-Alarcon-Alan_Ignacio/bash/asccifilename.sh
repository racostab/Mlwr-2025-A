# Directorio de prueba
mkdir -p archivos_ascii
cd archivos_ascii

# Genera una cadena con todos los caracteres ASCII del 0 al 254
nombre_archivo=$(printf '\\x%02x' {0..254} | xargs -0 printf)
# nombre_archivo=$(printf '%s' {0..255} | xargs -0 printf)

# Crea el archivo con ese nombre
touch "$nombre_archivo"

# Verifica si el archivo fue creado
if [ -f "$nombre_archivo" ]; then
    echo "Archivo creado con nombre de 255 caracteres ASCII"
else
    echo "No se pudo crear el archivo con nombre de 255 caracteres"
fi
s
# Regresa al directorio anterior
cd ..
