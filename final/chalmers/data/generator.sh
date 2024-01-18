#!/usr/bin/env bash

PPATH=$(realpath ..)
. gen.sh

ulimit -s unlimited

use_solution olle_full_solution.py

compile generate.py

samplegroup
limits maxn=5
sample 1
sample 2

group group1 5
limits maxn=2
tc g1-1 generate type=1 n=2 c=2 r=0 seed=1
tc g1-2 generate type=1 n=2 c=2 r=1 seed=101

group group2 10
tc 1
tc 2
include_group group1
limits maxn=10
tc g2-1 generate type=1 n=10 c=10 r=2 seed=1
tc g2-2 generate type=1 n=10 c=10 r=2 seed=2
tc g2-3 generate type=1 n=10 c=10 r=3 seed=3
tc g2-4 generate type=1 n=10 c=5 r=1 seed=3
tc g2-5 generate type=2 n=10 seed=4
tc g2-6 generate type=2 n=10 seed=5


group group3 10
limits maxn=250
include_group group1
include_group group2
tc g3-1 generate type=1 n=250 c=10 r=2 seed=11209
tc g3-2 generate type=1 n=250 c=10 r=4 seed=2
tc g3-3 generate type=1 n=250 c=20 r=7 seed=1209
tc g3-4 generate type=1 n=250 c=2 r=0 seed=13012412
tc g3-5 generate type=1 n=250 c=2 r=0 seed=1315
tc g3-6 generate type=1 n=250 c=2 r=0 seed=1341
tc g3-7 generate type=1 n=250 c=2 r=0 seed=1212309
tc g3-8 generate type=1 n=250 c=2 r=0 seed=12
tc g3-9 generate type=1 n=250 c=10 r=2 seed=151209
tc g3-10 generate type=2 n=250 seed=151209
tc g3-11 generate type=2 n=250 seed=15
tc g3-12 generate type=2 n=250 seed=9

group group4 15
limits maxn=1000
tc g4-1 generate type=2 n=1000 seed=1
tc g4-2 generate type=2 n=498 seed=2 
tc g4-3 generate type=2 n=1000 seed=3 
tc g4-4 generate type=2 n=500 seed=420
tc g4-5 generate type=2 n=500 seed=5 
tc g4-6 generate type=2 n=1000 seed=6 
tc g4-7 generate type=2 n=1000 seed=707
tc g4-8 generate type=2 n=999 seed=8 

group group5 14
limits maxn=500
include_group group1
include_group group2
include_group group3
tc g5-1 generate type=1 n=500 c=10 r=0 seed=112
tc g5-2 generate type=1 n=500 c=10 r=2 seed=1
tc g5-3 generate type=1 n=500 c=10 r=4 seed=2
tc g5-4 generate type=1 n=500 c=21 r=6 seed=3
tc g5-5 generate type=1 n=500 c=15 r=6 seed=5
tc g5-6 generate type=1 n=500 c=19 r=2 seed=7
tc g5-7 generate type=1 n=500 c=19 r=13 seed=123
tc g5-8 generate type=1 n=500 c=20 r=20 seed=41
tc g5-9 generate type=2 n=500 seed=3
tc g5-10 generate type=2 n=500 seed=4
tc g5-11 generate type=2 n=500 seed=5123
tc g5-12 generate type=2 n=500 seed=6

group group6 21
limits maxn=950
include_group group1
include_group group2
include_group group3
include_group group5
tc g6-1 generate type=1 n=950 c=10 r=0 seed=112
tc g6-2 generate type=1 n=950 c=12 r=3 seed=2
tc g6-3 generate type=1 n=950 c=11 r=7 seed=6215
tc g6-4 generate type=1 n=950 c=20 r=7 seed=13
tc g6-5 generate type=1 n=950 c=19 r=7 seed=1341
tc g6-6 generate type=1 n=950 c=20 r=2 seed=13123
tc g6-7 generate type=1 n=950 c=21 r=10 seed=135
tc g6-8 generate type=1 n=950 c=5 r=1 seed=131
tc g6-9 generate type=1 n=950 c=20 r=1 seed=1323
tc g6-10 generate type=2 n=950 seed=1
tc g6-11 generate type=2 n=950 seed=2
tc g6-12 generate type=2 n=950 seed=3

group group7 25
limits maxn=1000
include_group group1
include_group group2
include_group group3
include_group group4
include_group group5
include_group group6
tc g7-1 generate type=1 n=1000 c=17 r=0 seed=192
tc g7-2 generate type=1 n=1000 c=10 r=2 seed=19223
tc g7-3 generate type=1 n=1000 c=12 r=15 seed=1234
tc g7-4 generate type=1 n=1000 c=20 r=0 seed=192314
tc g7-5 generate type=1 n=1000 c=20 r=2 seed=1914
tc g7-6 generate type=1 n=1000 c=19 r=0 seed=1
tc g7-7 generate type=1 n=1000 c=2 r=0 seed=2
tc g7-8 generate type=1 n=1000 c=3 r=1 seed=3
tc g7-9 generate type=1 n=1000 c=20 r=12 seed=4
tc g7-10 generate type=1 n=1000 c=19 r=1 seed=3
tc g7-11 generate type=1 n=1000 c=11 r=2 seed=51
tc g7-12 generate type=1 n=1000 c=12 r=1 seed=13
tc g7-13 generate type=2 n=1000 seed=4
tc g7-14 generate type=2 n=1000 seed=5
tc g7-15 generate type=2 n=1000 seed=1239
tc g7-16 generate type=2 n=1000 seed=7

