#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution joshua_dp.cpp

compile gen_rand.py

# Generate answers to sample cases
samplegroup
sample 1

group group1 20
tc 1
for i in {1..2000}
do
tc g1-$i gen_rand n=$((RANDOM % 30 + 1)) alpha=$((RANDOM % 8 + 1))

done
