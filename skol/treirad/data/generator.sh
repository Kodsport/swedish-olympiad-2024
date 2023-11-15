#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution cuberoot.py

compile gen_rand.py

samplegroup
sample 1
sample 2
sample 3

group group1 20
limits maxn=30
tc 1
tc 2
tc_manual ../manual/tc1.in

group group2 20
limits maxn=80
tc_manual ../manual/tc2.in

group group3 20
limits maxn=1000
tc_manual ../manual/tc3.in

group group4 20
limits maxn=100000
tc 3
tc_manual ../manual/tc4.in

group group5 20
tc_manual ../manual/tc5.in
