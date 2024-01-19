#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution nils.cpp

compile gen_rand.py

# Generate answers to sample cases
samplegroup
sample 1
sample 2
sample 3

BILLION=1000000000
MAXN=100000
MILLION=1000000

group group1 10
limits n=1
tc_manual ../manual/n1_covers.in
tc_manual ../manual/n1_notcovers.in
tc_manual ../manual/n1_small.in
tc_manual ../manual/n1_endpoint.in
tc_manual ../manual/n1_endpoint2.in
tc_manual ../manual/n1_endpoint3.in
tc_manual ../manual/n1_endpoint4.in
tc_manual ../manual/n1_startpoint.in
tc_manual ../manual/n1_startpoint2.in

group group2 25
include_group group1
limits n=1000
tc 1
tc 2
tc g2-1 gen_rand n=1000 t=$BILLION s_ratio=0.01
tc g2-2 gen_rand n=1000 t=$BILLION s_ratio=0.05
tc g2-3 gen_rand n=1000 t=$BILLION s_ratio=0.1
tc g2-4 gen_rand n=1000 t=$BILLION s_ratio=0.2
tc g2-5 gen_rand n=1000 t=$BILLION s_ratio=0.4 mode=12
tc_manual ../manual/endpoints1.in
tc_manual ../manual/endpoints2.in
tc_manual ../manual/n3_endpoints.in
tc_manual ../manual/n3_endpoints1.in


group group3 30
limits t=$MILLION
tc g3-1 gen_rand n=$MAXN t=$MILLION s_ratio=0.01
tc g3-2 gen_rand n=$MAXN t=$MILLION s_ratio=0.05
tc g3-3 gen_rand n=$MAXN t=$MILLION s_ratio=0.1
tc g3-4 gen_rand n=$MAXN t=$MILLION s_ratio=0.2
tc g3-5 gen_rand n=$MAXN t=$MILLION s_ratio=0.4 mode=12
tc_manual ../manual/g3_zero.in
tc n1_endpoint
tc n1_endpoint2
tc n1_endpoint3
tc n1_startpoint
tc n3_endpoints
tc n3_endpoints1

group group4 35
include_group group2
include_group group3
tc 3
tc g4-1 gen_rand n=$MAXN t=$BILLION s_ratio=0.01
tc g4-2 gen_rand n=$MAXN t=$BILLION s_ratio=0.05
tc g4-3 gen_rand n=$MAXN t=$BILLION s_ratio=0.1
tc g4-4 gen_rand n=$MAXN t=$BILLION s_ratio=0.2
tc g4-5 gen_rand n=$MAXN t=$BILLION s_ratio=0.5 mode=12
