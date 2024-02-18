#!/usr/bin/env bash

PPATH=$(realpath ..)
. gen.sh

ulimit -s unlimited

use_solution olle_one_rat.py

compile generate.py

samplegroup
limits maxn=5 maxk=2
sample 1

group group1 100
limits maxn=1000 maxk=1
tc 1
tc g1-1 generate n=4 k=1 seed=420
tc g1-2 generate n=10 k=1 seed=1
tc g1-3 generate n=1000 k=1 seed=1
