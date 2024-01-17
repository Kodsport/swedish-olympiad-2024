#!/bin/bash
. ../../testdata_tools/gen.sh


ulimit -s unlimited
use_solution n2.cpp

compile gen_rand.py

samplegroup
sample 1
sample 2
sample 3

group group1 20
limits maxX=200 r=0
tc 1
tc 2
tc g1-1 gen_rand n=3 x=5 r=0
tc g1-2 gen_rand n=3 x=4 r=0
tc g1-3 gen_rand n=3 x=3 r=0
tc g1-4 gen_rand n=3 x=6 r=0
tc g1-5 gen_rand n=3 x=7 r=0

group group2 20
limits maxX=200 r=1
tc 3
tc g2-1 gen_rand n=3 x=5 r=1
tc g2-2 gen_rand n=3 x=4 r=1
tc g2-3 gen_rand n=3 x=3 r=1
tc g2-4 gen_rand n=3 x=6 r=1
tc g2-5 gen_rand n=3 x=7 r=1
