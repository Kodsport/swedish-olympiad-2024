#!/usr/bin/env bash

PPATH=$(realpath ..)
. gen.sh

ulimit -s unlimited

use_solution joakim.cc

compile gen.cc

Q=500000

samplegroup
limits line=0 q=$Q maxn=5
sample 1

group group1 10 # small line
limits line=1 q=$Q maxn=99
tc g1-2  gen -n=3  -q=$Q -type=bamboo


group group2 12 # medium line
include_group group1
limits line=1 q=$Q maxn=999
tc g2-1  gen -n=999 -q=$Q -type=bamboo -labeling=none


group group3 21 # large line
include_group group2
limits line=1 q=$Q maxn=24999
tc g3-1  gen -n=24999 -q=$Q -type=bamboo -labeling=none


group group4 14 # small tree
limits line=0 q=$Q maxn=99
include_group group1
tc 1
tc g4-1  gen -n=3  -q=$Q -type=random



group group5 15 # medium tree
limits line=0 q=$Q maxn=999
include_group group2
include_group group4
tc g5-1  gen -n=999 -q=$Q -type=random


group group6 28 # large tree
limits line=0 q=$Q maxn=24999
include_group group3
include_group group5
tc g6-1  gen -n=24999 -q=$Q -type=random

