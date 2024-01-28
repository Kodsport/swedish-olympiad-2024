#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution nils.cpp

compile gen_rand.py
compile gen_repeat.py
compile gen_identity.py

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
tc one-3 gen_rand n=1 m=$MAXN mode=permutation
tc one-4 gen_rand n=1 m=$MAXN
tc one-5 gen_repeat n=1 m=$MAXN chain=1
tc one-6 gen_repeat n=1 m=$MAXN chain=100000
tc one-7 gen_repeat n=1 m=$MAXN chain=299999
tc one-8 gen_repeat n=1 m=$MAXN chain=100000 mode=invalid

group group2 17
limits identity=1
limits maxn=$MAXN
tc identity-1 gen_rand n=1 m=10 mode=identity
tc identity-2 gen_rand n=300 m=300 mode=identity
tc identity-3 gen_rand n=300 m=30 mode=identity
tc identity-4 gen_identity n=$MAXN m=100000 mode=random
tc identity-5 gen_identity n=$MAXN m=10000 mode=sorted
tc identity-6 gen_identity n=$MAXN m=10000 mode=cycle1
tc identity-7 gen_identity n=$MAXN m=300 mode=cycle2
tc identity-8 gen_identity n=$MAXN m=10000 mode=cycle2
tc identity-9 gen_identity n=$MAXN m=100000 mode=cycle2

group group3 16
limits maxn=300
tc 2
tc 3
tc small-1 gen_rand n=10 m=10 mode=random
tc small-2 gen_rand n=10 m=10 mode=permutation
tc small-3 gen_rand n=300 m=30 mode=permutation
tc small-4 gen_rand n=300 m=30 mode=chain chain=1
tc small-5 gen_rand n=300 m=30 mode=chain chain=10
tc small-6 gen_rand n=100 m=30 mode=permutation
tc small-7 gen_repeat n=300 m=300
tc small-8 gen_repeat n=300 m=300 chain=100
tc small-9 gen_repeat n=300 m=300 chain=100 mode=invalid
tc small-10 gen_identity n=300 m=20 mode=cycle2

group group4 22
limits maxn=3000
limits permutation=1
tc perm-1 gen_rand n=300 m=30 mode=permutation
tc perm-2 gen_rand n=300 m=60 mode=permutation
tc perm-3 gen_rand n=300 m=10 mode=permutation
tc perm-4 gen_repeat n=3000 m=3000
tc perm-5 gen_identity n=3000 m=100 mode=cycle2

group group5 9
include_group group4
include_group group3
limits maxn=3000
tc medium-1 gen_rand n=300 m=30 mode=chain chain=1
tc medium-2 gen_rand n=300 m=300 mode=chain chain=10
tc medium-3 gen_rand n=300 m=40 mode=chain chain=20
tc medium-4 gen_repeat n=3000 m=3000 chain=1500

group group6 26
include_group group5
include_group group1
include_group group2
limits maxn=$MAXN
tc large-1 gen_rand n=$MAXN m=$MAXN
tc large-2 gen_rand n=$MAXN m=1000 mode=permutation
tc large-3 gen_repeat n=$MAXN m=$MAXN
tc large-4 gen_repeat n=$MAXN m=$MAXN chain=150000
tc large-5 gen_repeat n=$MAXN m=$MAXN chain=150000 mode=invalid

