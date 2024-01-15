#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution joshua.cpp

compile gen_rand.py
compile gen_semihard.py
compile gen_longpaths.py

samplegroup
sample 1

group group1 5
limits maxn=100 maxc=8
tc 1
tc g1-1 gen_rand n=100 c=8
tc g1-2 gen_rand n=100 c=8
tc g1-3 gen_rand n=100 c=8

group group2 10
limits maxn=100 maxc=100
include_group group1
tc g2-1 gen_rand n=100 c=100
tc g2-2 gen_rand n=100 c=100
tc g2-3 gen_rand n=100 c=100
tc g2-4 gen_semihard n=100


group group3 25
limits maxn=4000 maxc=2000
include_group group2
tc g3-1 gen_rand n=2000 c=2000
tc g3-2 gen_rand n=2000 c=2000
tc g3-3 gen_rand n=2000 c=2000
tc g3-4 gen_semihard n=2000
tc g3-5 gen_longpaths n=4000

group group5 50
limits maxn=200000 maxc=200000
include_group group3
tc g5-1 gen_rand n=200000 c=200000
tc g5-2 gen_rand n=200000 c=200000
tc g5-3 gen_rand n=200000 c=200000
tc g5-4 gen_semihard n=200000
tc g5-5 gen_longpaths n=200000
