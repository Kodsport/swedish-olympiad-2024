#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution sol.cc


samplegroup
limits maxn=15 maxk=15
sample 1
sample 2
sample 3

BILLION=1000000000
MILLION=1000000

group group1 7
limits maxn=10 maxk=30
tc 1
tc 2
tc_manual ../manual/01.02.01.in
tc_manual ../manual/01.09.01.in
tc_manual ../manual/01.07.01.in
tc_manual ../manual/01.02.02.in
tc_manual ../manual/01.04.03.in
tc_manual ../manual/01.04.02.in
tc_manual ../manual/01.08.02.in
tc_manual ../manual/01.07.03.in
tc_manual ../manual/01.02.04.in
tc_manual ../manual/01.05.03.in
tc_manual ../manual/01.01.03.in
tc_manual ../manual/01.05.01.in
tc_manual ../manual/01.06.01.in
tc_manual ../manual/01.09.03.in
tc_manual ../manual/01.08.03.in
tc_manual ../manual/01.03.03.in
tc_manual ../manual/01.03.01.in
tc_manual ../manual/01.08.04.in
tc_manual ../manual/01.02.03.in
tc_manual ../manual/01.08.05.in
tc_manual ../manual/01.08.01.in
tc_manual ../manual/01.05.02.in
tc_manual ../manual/01.03.02.in
tc_manual ../manual/01.06.02.in
tc_manual ../manual/01.06.03.in
tc_manual ../manual/01.09.02.in
tc_manual ../manual/01.01.01.in
tc_manual ../manual/01.04.01.in
tc_manual ../manual/01.07.02.in
tc_manual ../manual/01.01.02.in

group group2 14
limits maxn=200 maxk=30
include_group group1
tc 3
tc_manual ../manual/02.07.03.in
tc_manual ../manual/02.03.01.in
tc_manual ../manual/02.06.03.in
tc_manual ../manual/02.06.01.in
tc_manual ../manual/02.04.03.in
tc_manual ../manual/02.01.02.in
tc_manual ../manual/02.05.01.in
tc_manual ../manual/02.02.02.in
tc_manual ../manual/02.02.01.in
tc_manual ../manual/02.09.02.in
tc_manual ../manual/02.01.01.in
tc_manual ../manual/02.08.05.in
tc_manual ../manual/02.03.02.in
tc_manual ../manual/02.09.01.in
tc_manual ../manual/02.05.03.in
tc_manual ../manual/02.05.02.in
tc_manual ../manual/02.07.01.in
tc_manual ../manual/02.03.03.in
tc_manual ../manual/02.01.03.in
tc_manual ../manual/02.04.01.in
tc_manual ../manual/02.08.04.in
tc_manual ../manual/02.08.02.in
tc_manual ../manual/02.08.03.in
tc_manual ../manual/02.02.03.in
tc_manual ../manual/02.06.02.in
tc_manual ../manual/02.09.03.in
tc_manual ../manual/02.04.02.in
tc_manual ../manual/02.08.01.in
tc_manual ../manual/02.07.02.in
tc_manual ../manual/02.02.04.in

group group3 15
limits maxn=2000 maxk=30
include_group group2
tc_manual ../manual/03.09.03.in
tc_manual ../manual/03.08.03.in
tc_manual ../manual/03.06.01.in
tc_manual ../manual/03.08.04.in
tc_manual ../manual/03.04.03.in
tc_manual ../manual/03.09.01.in
tc_manual ../manual/03.01.01.in
tc_manual ../manual/03.09.02.in
tc_manual ../manual/03.05.02.in
tc_manual ../manual/03.02.03.in
tc_manual ../manual/03.01.02.in
tc_manual ../manual/03.03.01.in
tc_manual ../manual/03.03.03.in
tc_manual ../manual/03.02.02.in
tc_manual ../manual/03.07.01.in
tc_manual ../manual/03.03.02.in
tc_manual ../manual/03.06.03.in
tc_manual ../manual/03.08.01.in
tc_manual ../manual/03.05.01.in
tc_manual ../manual/03.05.03.in
tc_manual ../manual/03.08.02.in
tc_manual ../manual/03.02.04.in
tc_manual ../manual/03.07.02.in
tc_manual ../manual/03.04.02.in
tc_manual ../manual/03.07.03.in
tc_manual ../manual/03.06.02.in
tc_manual ../manual/03.02.01.in
tc_manual ../manual/03.08.05.in
tc_manual ../manual/03.01.03.in
tc_manual ../manual/03.04.01.in

group group4 9
limits maxn=2000 maxk=$BILLION
include_group group3
tc_manual ../manual/04.04.02.in
tc_manual ../manual/04.08.04.in
tc_manual ../manual/04.07.03.in
tc_manual ../manual/04.01.02.in
tc_manual ../manual/04.06.01.in
tc_manual ../manual/04.03.02.in
tc_manual ../manual/04.02.01.in
tc_manual ../manual/04.02.03.in
tc_manual ../manual/04.03.01.in
tc_manual ../manual/04.06.03.in
tc_manual ../manual/04.05.03.in
tc_manual ../manual/04.09.01.in
tc_manual ../manual/04.09.02.in
tc_manual ../manual/04.08.03.in
tc_manual ../manual/04.08.01.in
tc_manual ../manual/04.02.02.in
tc_manual ../manual/04.02.04.in
tc_manual ../manual/04.06.02.in
tc_manual ../manual/04.01.03.in
tc_manual ../manual/04.08.02.in
tc_manual ../manual/04.07.02.in
tc_manual ../manual/04.03.03.in
tc_manual ../manual/04.09.03.in
tc_manual ../manual/04.08.05.in
tc_manual ../manual/04.07.01.in
tc_manual ../manual/04.01.01.in
tc_manual ../manual/04.05.01.in
tc_manual ../manual/04.05.02.in
tc_manual ../manual/04.04.03.in
tc_manual ../manual/04.04.01.in

group group5 37
limits maxn=$MILLION maxk=30
include_group group3
tc_manual ../manual/05.09.03.in
tc_manual ../manual/05.07.02.in
tc_manual ../manual/05.04.03.in
tc_manual ../manual/05.01.03.in
tc_manual ../manual/05.09.01.in
tc_manual ../manual/05.07.01.in
tc_manual ../manual/05.08.03.in
tc_manual ../manual/05.07.03.in
tc_manual ../manual/05.01.02.in
tc_manual ../manual/05.05.03.in
tc_manual ../manual/05.06.03.in
tc_manual ../manual/05.08.02.in
tc_manual ../manual/05.05.01.in
tc_manual ../manual/05.08.05.in
tc_manual ../manual/05.08.04.in
tc_manual ../manual/05.04.01.in
tc_manual ../manual/05.04.02.in
tc_manual ../manual/05.03.02.in
tc_manual ../manual/05.01.01.in
tc_manual ../manual/05.06.02.in
tc_manual ../manual/05.06.01.in
tc_manual ../manual/05.05.02.in
tc_manual ../manual/05.03.01.in
tc_manual ../manual/05.09.02.in
tc_manual ../manual/05.02.01.in
tc_manual ../manual/05.02.02.in
tc_manual ../manual/05.03.03.in
tc_manual ../manual/05.08.01.in
tc_manual ../manual/05.02.03.in
tc_manual ../manual/05.02.04.in

group group6 18
include_group group4
include_group group5
limits maxn=$MILLION maxk=$BILLION
tc_manual ../manual/06.03.03.in
tc_manual ../manual/06.09.03.in
tc_manual ../manual/06.08.05.in
tc_manual ../manual/06.06.01.in
tc_manual ../manual/06.02.04.in
tc_manual ../manual/06.04.02.in
tc_manual ../manual/06.01.01.in
tc_manual ../manual/06.04.01.in
tc_manual ../manual/06.03.01.in
tc_manual ../manual/06.08.03.in
tc_manual ../manual/06.09.01.in
tc_manual ../manual/06.03.02.in
tc_manual ../manual/06.02.01.in
tc_manual ../manual/06.02.03.in
tc_manual ../manual/06.05.02.in
tc_manual ../manual/06.08.04.in
tc_manual ../manual/06.06.03.in
tc_manual ../manual/06.05.03.in
tc_manual ../manual/06.02.02.in
tc_manual ../manual/06.04.03.in
tc_manual ../manual/06.07.02.in
tc_manual ../manual/06.08.01.in
tc_manual ../manual/06.01.03.in
tc_manual ../manual/06.07.01.in
tc_manual ../manual/06.07.03.in
tc_manual ../manual/06.05.01.in
tc_manual ../manual/06.08.02.in
tc_manual ../manual/06.06.02.in
tc_manual ../manual/06.09.02.in
tc_manual ../manual/06.01.02.in
