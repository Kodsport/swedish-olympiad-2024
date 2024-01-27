#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution quadratic.cpp

compile gen_rand.py

# Generate answers to sample cases
samplegroup
sample 1
sample 2

MAXN=300000

group group1 17
limits identity=1
limits maxn=$MAXN
tc identity-1 gen_rand n=1 m=10 mode=identity
tc identity-2 gen_rand n=300 m=300 mode=identity
tc identity-3 gen_rand n=300 m=30 mode=identity

group group2 16
limits maxn=300
tc 1
tc 2
tc small-1 gen_rand n=10 m=10 mode=random
tc small-2 gen_rand n=10 m=10 mode=permutation
tc small-3 gen_rand n=300 m=30 mode=permutation
tc small-4 gen_rand n=10 m=10 mode=chain chain=1
tc small-5 gen_rand n=300 m=30 mode=chain chain=1
tc small-6 gen_rand n=300 m=30 mode=chain chain=10
tc small-7 gen_rand n=300 m=100 mode=chain chain=40
tc small-8 gen_rand n=100 m=30 mode=permutation
tc small-9 gen_rand n=300 m=30 mode=permutation

group group3 22
limits maxn=3000
limits permutation=1
tc perm-1 gen_rand n=300 m=30 mode=permutation
tc perm-2 gen_rand n=300 m=60 mode=permutation
tc perm-3 gen_rand n=300 m=10 mode=permutation

group group4 18
include_group group3
include_group group2
limits maxn=3000
tc medium-1 gen_rand n=300 m=30 mode=chain chain=1
tc medium-2 gen_rand n=300 m=300 mode=chain chain=10
tc medium-3 gen_rand n=300 m=40 mode=chain chain=20

group group5 27
include_group group4
include_group group1
limits maxn=$MAXN
tc large-1 gen_rand n=300 m=300
# TODO
