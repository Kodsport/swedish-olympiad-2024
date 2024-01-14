#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution harry.py

compile gen_rand.py
compile gen_line.py

samplegroup
sample 1

group group1 10 
include_group sample
limits mode="line"
tc g1-1 gen_line n=100000 k=99999 
tc g1-2 gen_line n=100000 k=50000 
tc g1-3 gen_line n=100000 k=3
tc g1-4 gen_line n=100000 k=2
tc g1-5 gen_line n=100000 k=1
tc g1-6 gen_line n=2 k=1
tc g1-7 gen_line n=1000 k=13
tc g1-8 gen_line n=1000 k=1
tc g1-9 gen_line n=20 k=7

group group2 10 
limits k=1 maxn=1000
tc g1-6
tc g1-8
tc g2-1 gen_rand n=1000 k=1
tc g2-2 gen_rand n=1000 k=1
tc g2-3 gen_rand n=20 k=1

group group3 10 
limits maxn=20
tc 1
tc g1-6
tc g1-9
tc g2-3
tc g3-1 gen_rand n=20 k=19
tc g3-2 gen_rand n=20 k=13
tc g3-3 gen_rand n=20 k=8
tc g3-4 gen_rand n=20 k=3 #this is the only g3 tc that cheese.py is failing on

group group4 15 
include_group group2
limits k=1
tc g1-5
tc g4-1 gen_rand n=100000 k=1
tc g4-2 gen_rand n=100000 k=1

group group5 25 
include_group group2
include_group group3
limits maxn=1000
tc g1-7
tc g5-1 gen_rand n=1000 k=10
tc g5-2 gen_rand n=1000 k=100
tc g5-3 gen_rand n=1000 k=999
#kanske något binärträd?


group group6 30
include_group group1
include_group group4 #group2
include_group group5 #group3 group2
tc g6-1 gen_rand n=100000 k=50000
tc g6-2 gen_rand n=100000 k=1000
tc g6-3 gen_rand n=100000 k=100
