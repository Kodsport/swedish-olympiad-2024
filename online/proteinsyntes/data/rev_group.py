#!/usr/bin/python3

import sys
import random
import math
import os


group="""
tc g5-15 gen_hard n=100000 m=1000000 maxlen=1 perturb=0

"""


for i in group.split("\n"):
    if i=="":
        continue
    s = i.split(" ")
    print(f"{s[0]} {s[1]}r rev c=\"{' '.join(s[2:])} 694201337\"")