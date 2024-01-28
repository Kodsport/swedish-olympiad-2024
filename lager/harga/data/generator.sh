#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution nils.cpp

compile gen_rand.py

# Generate answers to sample cases
samplegroup
sample 1
sample 2
sample 3

MAXN=300000

group group1 10
limits maxn=$MAXN
tc 1
tc one-1 gen_rand n=1 m=10
tc one-2 gen_rand n=1 m=1
tc one-3 gen_rand n=1 m=300

group group2 17
limits identity=1
limits maxn=$MAXN
tc identity-1 gen_rand n=1 m=10 mode=identity
tc identity-2 gen_rand n=300 m=300 mode=identity
tc identity-3 gen_rand n=300 m=30 mode=identity

group group3 16
limits maxn=300
tc 2
tc 3
tc small-1 gen_rand n=10 m=10 mode=random
tc small-2 gen_rand n=10 m=10 mode=permutation
tc small-3 gen_rand n=300 m=30 mode=permutation
tc small-4 gen_rand n=10 m=10 mode=chain chain=1
tc small-5 gen_rand n=300 m=30 mode=chain chain=1
tc small-6 gen_rand n=300 m=30 mode=chain chain=10
tc small-7 gen_rand n=300 m=100 mode=chain chain=40
tc small-8 gen_rand n=100 m=30 mode=permutation
tc small-9 gen_rand n=300 m=30 mode=permutation
tc small-10 gen_rand n=300 m=30 mode=permutation
tc small-11 gen_rand n=300 m=30 mode=permutation
tc small-12 gen_rand n=300 m=30 mode=permutation
tc small-13 gen_rand n=300 m=30 mode=permutation

group group4 22
limits maxn=3000
limits permutation=1
tc perm-1 gen_rand n=300 m=30 mode=permutation
tc perm-2 gen_rand n=300 m=60 mode=permutation
tc perm-3 gen_rand n=300 m=10 mode=permutation

group group5 9
include_group group4
include_group group3
limits maxn=3000
tc medium-1 gen_rand n=300 m=30 mode=chain chain=1
tc medium-2 gen_rand n=300 m=300 mode=chain chain=10
tc medium-3 gen_rand n=300 m=40 mode=chain chain=20

group group6 26
include_group group5
include_group group1
include_group group2
limits maxn=$MAXN
tc large-1 gen_rand n=300 m=300
# TODO
