#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution lca.cpp

compile gen_rand.py
compile gen_binary.py

samplegroup
sample 1

group group1 10 # O(NQ)
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

#group group3 10 # Line sweep
#limits goal=1
#tc g2-1 gen_rand n=3000   q=100000 querymode=samegoal
#tc g2-2 gen_rand n=30000  q=100000 querymode=samegoal
#tc g2-3 gen_rand n=300000 q=100000 querymode=samegoal

group group4 25 # O(h) queries
limits isbinary=1
tc g4-1 gen_binary h=18 q=100000 prob_down=0.1 querymode=random
tc g4-2 gen_binary h=18 q=100000 prob_down=0.5 querymode=random
tc g4-3 gen_binary h=18 q=100000 prob_down=0.9 querymode=random

#group group5 15 # O(N^2 bitset)
#limits goal=1
#tc g2-1 gen_rand n=3000   q=100000 querymode=samegoal
#tc g2-2 gen_rand n=30000  q=100000 querymode=samegoal
#tc g2-3 gen_rand n=300000 q=100000 querymode=samegoal

#group group6 30 # Full
#limits goal=1
#tc g2-1 gen_rand n=3000   q=100000 querymode=samegoal
#tc g2-2 gen_rand n=30000  q=100000 querymode=samegoal
#tc g2-3 gen_rand n=300000 q=100000 querymode=samegoal
