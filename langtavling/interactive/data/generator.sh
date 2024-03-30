#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution cheat.cpp

# Generate answers to sample cases
samplegroup
limits maxn=10
sample 1

group group1 6
limits maxN=100
tc 1
tc_manual ../manual/01-01.txt
tc_manual ../manual/01-02.txt
tc_manual ../manual/01-03.txt
tc_manual ../manual/01-04.txt

group group2 25
limits maxN=15000
tc_manual ../manual/02-01.txt
tc_manual ../manual/02-02.txt
tc_manual ../manual/02-03.txt
tc_manual ../manual/02-04.txt
tc_manual ../manual/02-05.txt

group group3 9
limits maxN=15000
include_group group1
include_group group2
tc_manual ../manual/03-01.txt
tc_manual ../manual/03-02.txt
tc_manual ../manual/03-03.txt
tc_manual ../manual/03-04.txt
tc_manual ../manual/03-05.txt

group group4 30
limits maxN=38000
include_group group3
tc_manual ../manual/04-01.txt
tc_manual ../manual/04-02.txt
tc_manual ../manual/04-03.txt
tc_manual ../manual/04-04.txt

group group5 5
limits maxN=39000
include_group group3
tc_manual ../manual/05-01.txt
tc_manual ../manual/05-02.txt
tc_manual ../manual/05-03.txt
tc_manual ../manual/05-04.txt

group group6 5
limits maxN=40000
include_group group5
tc_manual ../manual/06-01.txt
tc_manual ../manual/06-02.txt
tc_manual ../manual/06-03.txt
tc_manual ../manual/06-04.txt

group group7 5
limits maxN=41000
include_group group6
tc_manual ../manual/07-01.txt
tc_manual ../manual/07-02.txt
tc_manual ../manual/07-03.txt
tc_manual ../manual/07-04.txt

group group8 5
limits maxN=42000
include_group group7
tc_manual ../manual/08-01.txt
tc_manual ../manual/08-02.txt
tc_manual ../manual/08-03.txt
tc_manual ../manual/08-04.txt

group group9 10
limits maxN=43000
include_group group7
tc_manual ../manual/09-01.txt
tc_manual ../manual/09-02.txt
tc_manual ../manual/09-03.txt
tc_manual ../manual/09-04.txt
