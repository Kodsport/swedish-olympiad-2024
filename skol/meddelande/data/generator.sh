#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution nils.py

#samplegroup
#sample 1

group group1 20
limits maxn=1
tc_manual ../manual/tc1.in

group group2 20
tc_manual ../manual/tc2.in

group group3 20
tc_manual ../manual/tc3.in

group group4 20
tc_manual ../manual/tc4.in

group group5 20
tc_manual ../manual/tc5.in
