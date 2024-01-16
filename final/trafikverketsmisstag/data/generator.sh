#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution joshua_faster.cpp

compile gen_rand.py
compile gen_semihard.py
compile gen_longpaths.py
compile gen_chains.py

samplegroup
sample 1

group group1 5
limits maxn=100 maxc=8
tc 1
tc g1-1 gen_rand n=100 c=8
tc g1-2 gen_rand n=100 c=8
tc g1-3 gen_rand n=100 c=8
tc g1-4 gen_rand n=100 c=8
tc g1-5 gen_rand n=100 c=8
tc g1-6 gen_rand n=100 c=8

group group2 10
limits maxn=100 maxc=100
include_group group1
tc g2-1 gen_rand n=100 c=100
tc g2-2 gen_semihard n=100


group group3 25
limits maxn=4000 maxc=4000
include_group group2
tc g3-1 gen_rand n=4000 c=2000
tc g3-2 gen_semihard n=4000
tc g3-3 gen_longpaths n=4000

group group4 10
limits maxn=4000 diameter=50
tc g4-1 gen_chains n=4000 len=24
tc g4-2 gen_chains n=4000 len=10
tc g4-3 gen_chains n=4000 len=5

group group5 50
include_group group3
include_group group4
tc g5-1 gen_rand n=200000 c=200000
tc g5-2 gen_semihard n=200000
tc g5-3 gen_longpaths n=200000
