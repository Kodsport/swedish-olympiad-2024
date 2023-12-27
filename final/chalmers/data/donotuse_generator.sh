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
tc g11 generate type=1 n=2 c=2 r=0 seed=1


group group2 10
tc 1
include_group group1
limits maxn=10
tc g21 generate type=1 n=10 c=10 r=2 seed=1230


group group3 10
limits maxn=250
include_group group1
include_group group2
tc g31 generate type=1 n=250 c=10 r=2 seed=11209



group group4 30
limits maxn=500
include_group group1
include_group group2
include_group group3
tc g41 generate type=1 n=500 c=10 r=0 seed=112


group group5 40
limits maxn=1000
include_group group1
include_group group2
include_group group3
include_group group4
tc g51 generate type=1 n=1000 c=17 r=2 seed=192

