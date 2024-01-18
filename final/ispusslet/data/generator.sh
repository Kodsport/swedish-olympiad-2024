#!/bin/bash
. ../../testdata_tools/gen.sh


# TODO testcases:
# Start node lives inside cycle, needs to switch parity
# Start nodes needs to walk to cycle to switch parity
# Impossible due to bipartite odd
# Possible due to bipartite even
# More general-purpose??

ulimit -s unlimited
use_solution joshua.cpp

compile gen_rand.py
compile gen_full.py

samplegroup
sample 1
sample 2
sample 3

#for i in {1..100}
#do
#tc g1-$i gen_rand maxx=200
#done

group group1 20
limits maxX=200 r=0
tc 1
tc 2
tc g1-1 gen_rand n=1000 x=200 r=0
tc g1-2 gen_rand n=15 x=200 r=0
tc g1-3 gen_rand n=20 x=200 r=0
tc g1-4 gen_rand n=30 x=200 r=0
tc g1-5 gen_rand n=60 x=200 r=0
#
tc g1-6 gen_full n=14 r=0


group group2 20
limits maxX=200 r=1
tc 3
tc_manual ../manual/odd.in
tc_manual ../manual/walkodd.in
tc_manual ../manual/disconnected.in
tc g2-1 gen_rand n=1000 x=200 r=1
tc g2-2 gen_rand n=15 x=200 r=1
tc g2-3 gen_rand n=20 x=200 r=1
tc g2-4 gen_rand n=30 x=200 r=1
tc g2-5 gen_rand n=60 x=200 r=1
#
tc g2-6 gen_full n=14 r=1


group group3 5
limits maxX=5000 r=0
include_group group1
tc g3-1 gen_rand n=1000 x=5000 r=0
tc g3-2 gen_rand n=75 x=5000 r=0
tc g3-3 gen_rand n=100 x=5000 r=0
tc g3-4 gen_rand n=200 x=5000 r=0
tc g3-5 gen_rand n=300 x=5000 r=0
tc g3-6 gen_full n=70 r=0

group group4 15
limits maxX=12000 r=0
include_group group3
tc g4-1 gen_full n=108 r=0

group group5 40
limits maxX=12000 r=1
include_group group2
tc g5-6 gen_full n=108 r=1
tc g5-1 gen_rand n=1000 x=12000 r=1
tc g5-2 gen_rand n=110 x=12000 r=1
tc g5-3 gen_rand n=200 x=12000 r=1
tc g5-4 gen_rand n=300 x=12000 r=1
tc g5-5 gen_rand n=400 x=12000 r=1
