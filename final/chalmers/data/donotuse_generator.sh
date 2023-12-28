#!/usr/bin/env bash

PPATH=$(realpath ..)
. gen.sh

ulimit -s unlimited

use_solution olle_full_solution.py

compile generate.py

samplegroup
limits maxn=5
sample 1

group group1 10 
limits maxn=2
tc g1-1 generate type=1 n=2 c=2 r=0 seed=1


group group2 10
tc 1
include_group group1
limits maxn=10
tc g2-1 generate type=1 n=10 c=10 r=2 seed=1230


group group3 10
limits maxn=250
include_group group1
include_group group2
tc g3-1 generate type=1 n=250 c=10 r=2 seed=11209



group group4 20
limits maxn=500
include_group group1
include_group group2
include_group group3
tc g4-1 generate type=1 n=500 c=10 r=0 seed=112

group group5 25
limits maxn=950
include_group group1
include_group group2
include_group group3
include_group group4
tc g5-1 generate type=1 n=950 c=10 r=0 seed=112
tc g5-2 generate type=1 n=950 c=12 r=3 seed=112
tc g5-3 generate type=1 n=950 c=11 r=7 seed=112

group group6 25
limits maxn=1000
include_group group1
include_group group2
include_group group3
include_group group4
include_group group5
tc g6-1 generate type=1 n=1000 c=17 r=0 seed=192
tc g6-2 generate type=1 n=1000 c=10 r=2 seed=19223
tc g6-3 generate type=1 n=1000 c=12 r=15 seed=1234
tc g6-4 generate type=1 n=1000 c=20 r=0 seed=192314
tc g6-5 generate type=1 n=1000 c=20 r=2 seed=1914
tc g6-6 generate type=1 n=1000 c=19 r=0 seed=11914

