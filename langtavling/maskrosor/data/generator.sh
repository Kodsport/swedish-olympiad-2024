#!/bin/bash
. ../../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution maskrosor.cpp

# Generate answers to sample cases
samplegroup
sample 1
sample 2

group group1 5
limits maxR=4 maxC=4
tc 1
tc 2
tc_manual ../manual/01-01.txt
tc_manual ../manual/01-02.txt
tc_manual ../manual/01-03.txt
tc_manual ../manual/01-04.txt
tc_manual ../manual/01-05.txt
tc_manual ../manual/01-06.txt
tc_manual ../manual/01-07.txt
tc_manual ../manual/01-08.txt
tc_manual ../manual/01-09.txt
tc_manual ../manual/01-10.txt
tc_manual ../manual/01-11.txt
tc_manual ../manual/01-12.txt
tc_manual ../manual/01-13.txt
tc_manual ../manual/01-14.txt
tc_manual ../manual/01-15.txt
tc_manual ../manual/01-16.txt

group group2 10
limits maxR=40 maxC=40
include_group group1
tc_manual ../manual/02-01.txt
tc_manual ../manual/02-02.txt
tc_manual ../manual/02-03.txt
tc_manual ../manual/02-04.txt
tc_manual ../manual/02-05.txt
tc_manual ../manual/02-06.txt
tc_manual ../manual/02-07.txt
tc_manual ../manual/02-08.txt
tc_manual ../manual/02-09.txt
tc_manual ../manual/02-10.txt
tc_manual ../manual/02-11.txt
tc_manual ../manual/02-12.txt
tc_manual ../manual/02-13.txt
tc_manual ../manual/02-14.txt
tc_manual ../manual/02-15.txt
tc_manual ../manual/02-16.txt

group group3 15
limits maxR=40
include_group group2
tc_manual ../manual/03-01.txt
tc_manual ../manual/03-02.txt
tc_manual ../manual/03-03.txt
tc_manual ../manual/03-04.txt
tc_manual ../manual/03-05.txt
tc_manual ../manual/03-06.txt
tc_manual ../manual/03-07.txt
tc_manual ../manual/03-08.txt
tc_manual ../manual/03-09.txt
tc_manual ../manual/03-10.txt
tc_manual ../manual/03-11.txt
tc_manual ../manual/03-12.txt


group group4 30
limits maxN=25
tc_manual ../manual/04-01.txt
tc_manual ../manual/04-02.txt
tc_manual ../manual/04-03.txt
tc_manual ../manual/04-04.txt
tc_manual ../manual/04-05.txt
tc_manual ../manual/04-06.txt
tc_manual ../manual/04-07.txt
tc_manual ../manual/04-08.txt
tc_manual ../manual/04-09.txt
tc_manual ../manual/04-10.txt
tc_manual ../manual/04-11.txt
tc_manual ../manual/04-12.txt
tc_manual ../manual/04-13.txt
tc_manual ../manual/04-14.txt
tc_manual ../manual/04-15.txt
tc_manual ../manual/04-16.txt
tc_manual ../manual/04-17.txt
tc_manual ../manual/04-18.txt
tc_manual ../manual/04-19.txt
tc_manual ../manual/04-20.txt


group group5 20
limits maxN=100
include_group group4
tc_manual ../manual/05-01.txt
tc_manual ../manual/05-02.txt
tc_manual ../manual/05-03.txt
tc_manual ../manual/05-04.txt
tc_manual ../manual/05-05.txt
tc_manual ../manual/05-06.txt
tc_manual ../manual/05-07.txt
tc_manual ../manual/05-08.txt
tc_manual ../manual/05-09.txt
tc_manual ../manual/05-10.txt
tc_manual ../manual/05-11.txt
tc_manual ../manual/05-12.txt
tc_manual ../manual/05-13.txt
tc_manual ../manual/05-14.txt
tc_manual ../manual/05-15.txt
tc_manual ../manual/05-16.txt

group group6 20
include_group group3
include_group group5
tc_manual ../manual/06-01.txt
tc_manual ../manual/06-02.txt
tc_manual ../manual/06-03.txt
tc_manual ../manual/06-04.txt
tc_manual ../manual/06-05.txt
tc_manual ../manual/06-06.txt
tc_manual ../manual/06-07.txt
tc_manual ../manual/06-08.txt
tc_manual ../manual/06-09.txt
tc_manual ../manual/06-10.txt
tc_manual ../manual/06-11.txt
tc_manual ../manual/06-12.txt
tc_manual ../manual/06-13.txt
tc_manual ../manual/06-14.txt
tc_manual ../manual/06-15.txt
tc_manual ../manual/06-16.txt
tc_manual ../manual/06-17.txt
tc_manual ../manual/06-18.txt


