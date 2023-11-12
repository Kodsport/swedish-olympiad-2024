#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution binarysearch.cpp

compile gen_rand.py


group group1 20
tc_manual ../manual/1.in

group group2 20
limits max_t=10
tc_manual ../manual/2.in

group group3 20
limits max_t=1000
tc_manual ../manual/3.in

group group4 20
limits max_t=1000000
tc_manual ../manual/4.in

group group5 20
limits max_t=1000000
tc_manual ../manual/5.in
