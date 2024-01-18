#!/usr/bin/python3

import sys
import random
import math
from random import randint

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))

n = int(cmdlinearg('n'))
ret = int(cmdlinearg("r"))
grid = [['X' for i in range(n)] for j in range(n)]
grid[randint(0,n-1)][randint(0,n-1)]='O'


print(n, ret)
[print("".join(row)) for row in grid]
