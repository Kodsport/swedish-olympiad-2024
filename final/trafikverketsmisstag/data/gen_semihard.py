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

edges = []
p = 0
last = 0
while p < n*0.9:
    edges.append((p+1,p+2))
    last = p+2
    p+=1

while p < n-1:
    edges.append((randint(int(last*0.9),p+1), p+2))
    p+=1



people = []
l = n//2
r = l+2
while l >= 1 and r <= n:
    people.append((l, r))
    people.append((r, l+1))
    l-=1
    r+=1

random.shuffle(people)
random.shuffle(edges)
print(n,len(people))
for e in edges:
    print(e[0],e[1])
for p in people:
    print(p[0],p[1])