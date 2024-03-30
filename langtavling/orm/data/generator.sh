#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution waz.cpp

# Generate answers to sample cases
samplegroup
sample 1
sample 2

group group1 15
limits maxN=10
tc 1
tc 2
tc_manual ../manual/p1.in
tc_manual ../manual/p2.in
tc_manual ../manual/p4.in
tc_manual ../manual/p5.in
tc_manual ../manual/p6.in
tc_manual ../manual/p7.in
tc_manual ../manual/p8.in
tc_manual ../manual/waz0.in
tc_manual ../manual/waz1.in
tc_manual ../manual/waz2.in
tc_manual ../manual/waz3.in
tc_manual ../manual/waz4.in
tc_manual ../manual/waz5.in
tc_manual ../manual/waz6.in
tc_manual ../manual/waz7.in
tc_manual ../manual/waz8.in
tc_manual ../manual/waz9.in
tc_manual ../manual/waz10.in
tc_manual ../manual/waz11.in
tc_manual ../manual/waz12.in


group group2 25
limits maxN=40
include_group group1
tc_manual ../manual/waz13.in
tc_manual ../manual/waz14.in
tc_manual ../manual/waz15.in
tc_manual ../manual/waz16.in
tc_manual ../manual/waz17.in
tc_manual ../manual/waz18.in
tc_manual ../manual/waz19.in
tc_manual ../manual/waz20.in
tc_manual ../manual/waz21.in
tc_manual ../manual/waz22.in

group group3 30
limits maxN=300
include_group group2
tc_manual ../manual/waz23.in
tc_manual ../manual/waz24.in
tc_manual ../manual/waz25.in
tc_manual ../manual/waz26.in
tc_manual ../manual/waz27.in
tc_manual ../manual/waz28.in
tc_manual ../manual/waz29.in
tc_manual ../manual/waz30.in
tc_manual ../manual/waz31.in
tc_manual ../manual/waz32.in
tc_manual ../manual/waz33.in
tc_manual ../manual/waz34.in


group group4 30
include_group group3
tc_manual ../manual/waz35.in
tc_manual ../manual/waz36.in
tc_manual ../manual/waz37.in
tc_manual ../manual/waz38.in
tc_manual ../manual/waz39.in
tc_manual ../manual/waz40.in
tc_manual ../manual/waz41.in
tc_manual ../manual/waz42.in


