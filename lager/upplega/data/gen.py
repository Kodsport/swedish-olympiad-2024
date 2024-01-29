#!/usr/bin/python3

import sys
import random
import math

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
k = int(cmdlinearg('k'))

print(n,k)

print(*range(10,10*(n+1),10))
print(*[10]*n)

grenar = [(i,(-1)**random.randint(0,1)*random.randint(1,9)) for i in range(n*10)]
random.shuffle(grenar)
for _ in range(n):
    heights = []
    lengths = []
    for _ in range(10):
        h,l = grenar.pop()
        heights.append(h)
        lengths.append(l)

    print(*heights)
    print(*lengths)        
    

