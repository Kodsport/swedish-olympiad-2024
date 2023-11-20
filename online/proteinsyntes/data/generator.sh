#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution joshuasqrt_mersenne.cpp

compile gen_rand.py
compile gen_hard.py
compile gen_differentlen.py
compile gen_samelen.py
compile gen_aaaaa.py
compile gen_aabb.py

# Generate answers to sample cases
samplegroup
limits maxn=10 maxm=10
sample 1

group group1 10
limits maxn=20 maxm=5
tc 1
tc g1-1 gen_rand n=20 m=5 alphabet_size=20
tc g1-2 gen_rand n=20 m=5 alphabet_size=10
tc g1-3 gen_rand n=20 m=5 alphabet_size=5
tc g1-4 gen_rand n=20 m=5 alphabet_size=2
tc g1-5 gen_rand n=20 m=5 alphabet_size=1

group group2 20
limits maxn=100 maxm=100
include_group group1
tc g2-1 gen_rand n=100 m=100 alphabet_size=20
tc g2-2 gen_rand n=100 m=100 alphabet_size=10
tc g2-3 gen_rand n=100 m=100 alphabet_size=5
tc g2-4 gen_rand n=100 m=100 alphabet_size=2
tc g2-5 gen_rand n=100 m=100 alphabet_size=1


group group3 20
limits maxm=100
include_group group2
tc g3-1 gen_rand n=100000 m=100 maxlen=2000 alphabet_size=20
tc g3-2 gen_rand n=100000 m=100 maxlen=2000 alphabet_size=10
tc g3-3 gen_rand n=100000 m=100 maxlen=2000 alphabet_size=5
tc g3-4 gen_rand n=100000 m=100 maxlen=2000 alphabet_size=2
tc g3-5 gen_rand n=100000 m=100 maxlen=2000 alphabet_size=1
tc g3-6 gen_rand n=100000 m=100 maxlen=100 alphabet_size=5
tc g3-7 gen_hard n=100000 m=100 maxlen=9960
tc g3-8 gen_hard n=100000 m=100 maxlen=5000
tc g3-9 gen_hard n=100000 m=20 maxlen=49960
tc_manual powtwokiller

group group4 25
limits maxn=30000
tc g4-1 gen_rand n=30000 m=100000 maxlen=10 alphabet_size=20
tc g4-2 gen_rand n=30000 m=100000 maxlen=10 alphabet_size=5
tc g4-3 gen_hard n=30000 m=100000 maxlen=6
tc g4-4 gen_hard n=30000 m=4 maxlen=249995
tc g4-5 gen_differentlen n=30000 b=0
tc g4-6 gen_differentlen n=30000 b=1
tc g4-7 gen_samelen n=30000
tc g4-8 gen_aaaaa n=30000 m=1000000
tc g4-9 gen_aabb n=30000 m=1000000
tc powtwokiller

group group5 25
include_group group3
include_group group4
tc g5-1 gen_rand n=100000 m=100000 maxlen=10 alphabet_size=20
tc g5-2 gen_rand n=100000 m=100000 maxlen=10 alphabet_size=10
tc g5-3 gen_rand n=100000 m=100000 maxlen=10 alphabet_size=5
tc g5-4 gen_rand n=100000 m=100000 maxlen=10 alphabet_size=2
tc g5-6 gen_rand n=100000 m=100000 maxlen=10 alphabet_size=5
tc g5-7 gen_hard n=100000 m=100000 maxlen=6
tc g5-8 gen_hard n=100000 m=1000000 maxlen=1 perturb=0
tc g5-9 gen_hard n=100000 m=4 maxlen=249995
tc g5-10 gen_differentlen n=100000 b=0
tc g5-11 gen_differentlen n=100000 b=1
tc g5-12 gen_samelen n=100000
tc g5-13 gen_aaaaa n=100000 m=1000000
tc g5-14 gen_aabb n=100000 m=1000000

#tc_manual ../manual_tests/manual_1.in
