#!/usr/bin/env bash

PPATH=$(realpath ..)
. gen.sh

ulimit -s unlimited

use_solution olle_one_rat.py

compile generate.py

samplegroup
limits maxn=5 maxk=2
sample 1

group group1 5
limits maxn=2 maxk=1
tc g1-1 generate n=2 k=1 seed=1
tc g1-2 generate n=2 k=1 seed=2
tc g1-3 generate n=2 k=1 seed=3

group group2 5
limits maxn=3 maxk=2
include_group group1
tc 1
tc g2-1 generate n=3 k=1 seed=11
tc g2-2 generate n=3 k=1 seed=12
tc g2-3 generate n=3 k=2 seed=13
tc g2-4 generate n=3 k=2 seed=14

group group3 20
limits maxn=1000 maxk=1
include_group group1
tc g3-1 generate n=1000 k=1 seed=101
tc g3-2 generate n=999 k=1 seed=102
tc g3-3 generate n=101 k=1 seed=103
tc g3-4 generate n=998 k=1 seed=104

group group4 15
limits maxn=1000 maxk=999
tc g4-1 generate n=1000 k=500 line=1 seed=51
tc g4-2 generate n=1000 k=1 line=1 seed=52
tc g4-3 generate n=1000 k=51 line=1 seed=53
tc g4-4 generate n=1000 k=999 line=1 seed=54

group group5 17
limits maxn=50 maxk=49
include_group group1
include_group group2
tc g5-1 generate n=50 k=25 seed=21
tc g5-2 generate n=50 k=10 seed=22
tc g5-3 generate n=50 k=49 seed=23
tc g5-4 generate n=50 k=3 seed=24

group group6 38
limits maxn=1000 maxk=999
include_group group1
include_group group2
include_group group3
include_group group4
include_group group5
tc g6-1 generate n=1000 k=500 seed=31
tc g6-2 generate n=1000 k=50 seed=32
tc g6-3 generate n=1000 k=999 seed=33
tc g6-4 generate n=1000 k=900 seed=34
tc g6-5 generate n=1000 k=10 seed=35

