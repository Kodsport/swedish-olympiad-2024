#!/bin/bash
. ../../testdata_tools/gen.sh

ulimit -s unlimited
use_solution bussresa.cpp

# Generate answers to sample cases
samplegroup
sample 1
sample 2
sample 3

group group1 16
limits maxN=8 maxM=8
tc 1
tc 2
tc 3
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
tc_manual ../manual/01-17.txt
tc_manual ../manual/01-18.txt
tc_manual ../manual/01-19.txt
tc_manual ../manual/01-20.txt
tc_manual ../manual/01-21.txt
tc_manual ../manual/01-22.txt

group group2 30
limits maxN=100 maxM=100
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

group group3 24
limits maxN=2000 maxM=2000
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
tc_manual ../manual/03-13.txt
tc_manual ../manual/03-14.txt


group group4 30
include_group group3
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
tc_manual ../manual/04-21.txt
tc_manual ../manual/04-22.txt
tc_manual ../manual/04-23.txt
tc_manual ../manual/04-24.txt
tc_manual ../manual/04-25.txt
tc_manual ../manual/04-26.txt
tc_manual ../manual/04-27.txt
tc_manual ../manual/04-28.txt
tc_manual ../manual/04-29.txt