#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution lca.cpp

compile gen_rand.py

samplegroup
sample 1

group group1 10
include_group sample
limits n=1000 q=1000
tc g1-1 gen_rand n=10   q=1000 querymode=random
tc g1-2 gen_rand n=100  q=1000 querymode=random
tc g1-3 gen_rand n=1000 q=1000 querymode=random

group group2 10 # Same goal
limits goal=1
tc g2-1 gen_rand n=3000   q=100000 querymode=samegoal
tc g2-2 gen_rand n=30000  q=100000 querymode=samegoal
tc g2-3 gen_rand n=300000 q=100000 querymode=samegoal
