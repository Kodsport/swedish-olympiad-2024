#!/usr/bin/python3

import sys
import random
rand = random.randint

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))

n = int(cmdlinearg("n"))
t = int(cmdlinearg("t"))
s = int(t*float(cmdlinearg("s_ratio")))
sz = int(t/(n*3))

last = 0
intervals = []
for i in range(n):
    l = rand(last+1, last+1+sz)
    r = rand(l+1, l+1+sz)
    intervals.append((l,r))
    last = r

print(n,t,s)
[print(l,r) for l,r in intervals]