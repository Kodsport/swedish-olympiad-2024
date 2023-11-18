#!/bin/bash
REQUIRE_SAMPLE_REUSE=0
. ../../testdata_tools/gen.sh

use_solution nils.cpp

compile gen_rand.py

samplegroup
sample 1
sample 2

group group1 20
tc_manual ../manual/tc1.in

group group2 20
limits max_t=10
tc_manual ../manual/tc2.in

group group3 20
limits max_t=1000
tc_manual ../manual/tc3.in

group group4 20
limits max_t=1000000
tc_manual ../manual/tc4.in

group group5 20
limits max_t=1000000
tc_manual ../manual/tc5.in
