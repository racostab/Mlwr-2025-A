import os
import subprocess

# python ./execl

pid = os.getpid()
print(f"El pid actual es: {pid}\n")

try:
    os.execl("/bin/ps", "ps", "-fea")
except Exception as e:
    print(f"Error al ejecutar execl: {e}")
