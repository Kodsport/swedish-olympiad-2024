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
x = int(cmdlinearg('x'))
ret = int(cmdlinearg('r'))
n = 1000
#randint(1,int(cmdlinearg("maxx")))
grid = [['.' for i in range(n)] for j in range(n)]
positions = [(i,j) for i in range(n) for j in range(n)]

random.shuffle(positions)

for i in range(x):
    r,c = positions[i]
    if i==0:
        grid[r][c]='O'
    else:
        grid[r][c]='X'

print(n, ret)
[print("".join(row)) for row in grid]
