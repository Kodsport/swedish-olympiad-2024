#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution joshua.cpp

compile gen_rand.py
compile gen_spikes.py

# Generate answers to sample cases
samplegroup
sample 1

MAXC=1000000000
MAXN=200000
group group1 9
limits maxn=1000
tc 1
tc g1-1 gen_rand n=1000 c=$MAXC mode=random
tc g1-2 gen_rand n=1000 c=$MAXC mode=random

group group2 14
limits maxc=50
tc 1
tc g2-1 gen_rand n=$MAXN c=50 mode=random
tc g2-2 gen_rand n=$MAXN c=50 mode=random


#for i in {1..1000}
#do
#tc g1-$i gen_rand mode=random

#done

group group3 26 # Random
tc g3-1 gen_rand n=$MAXN c=$MAXC mode=random
tc g3-2 gen_rand n=$MAXN c=$MAXC mode=random

group group4 51
include_group group1
include_group group2
include_group group3
tc g4-1 gen_spikes n=$MAXN c=$MAXC
tc g4-2 gen_spikes n=$MAXN c=999999999
tc g4-3 gen_spikes n=$MAXN c=972356712
