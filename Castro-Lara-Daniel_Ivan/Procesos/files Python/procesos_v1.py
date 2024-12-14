#!/usr/bin/env python3:
"""
    Sistemas Operativos
    Daniel Iván Castro Lara
    Programa en Python de procesos
"""

import os;
import sys;
import time;

pid = os.fork()
match pid : #Switch valido solo para python ver >=3.1
    case -1:
        print("Error in fork.")
    case 0:
        print("Child PID = %d, PPID = %d" % (os.getpid(), os.getppid()))

    case _:
        print("Father PID = {} PPID = {}".format(os.getppid()))

"""
    1.- python <archivo>.py
    No se necesita compilar porque es interpretado.
"""