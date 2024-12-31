: '
Programa en Bash está diseñado para determinar la longitud máxima permitida para un nombre de archivo en el sistema operativo donde se ejecuta. 
Lo hace creando archivos con nombres progresivamente más largos hasta que la operación falla.
'

#!/bin/bash

nombre_archivo="a"


longitud_maxima=0

while true; do

    if touch "$nombre_archivo" 2>/dev/null; then
        # Si la creación se  cumple entonces se crea uno archivo más
        longitud_maxima=${#nombre_archivo}
        echo "Archivo creado: $nombre_archivo (Longitud: $longitud_maxima)"

        # Incrementamos el nombre del archivo añadiendo otro carácter
        nombre_archivo+="a"
    else
        # Si falla,  entonces se  llego al límite.
        echo "Se alcanzó el límite máximo. Longitud máxima permitida en el nombre de archivo: $longitud_maxima caracteres."
        break
    fi
done
