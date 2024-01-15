#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution factorial.cpp

compile gen_rand.py

samplegroup
sample 1

group group1 10
tc 1
for i in {1..100}
do
tc g1-$i gen_rand n=$((RANDOM % 6 + 1)) s=$((RANDOM % 4 + 1))

done