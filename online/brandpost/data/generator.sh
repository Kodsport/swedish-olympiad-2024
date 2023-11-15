#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution harry.py

compile gen.py
compile gen_slalom.py

# Generate answers to sample cases
samplegroup
sample 1


group group1 10
limits maxN=1 mode="hydrantAtStart" maxSize=10
tc g1-01 gen n=1 mode="hydrantAtStart" maxSize=10
tc g1-02 gen n=1 mode="hydrantAtStart" maxSize=10
tc g1-03 gen n=1 mode="hydrantAtStart" maxSize=10
tc g1-04 gen n=1 mode="hydrantAtStart" maxSize=10
tc g1-05 gen n=1 mode="hydrantAtStart" w=9 h=1
tc g1-06 gen n=1 mode="hydrantAtStart" w=1 h=9
tc g1-07 gen n=1 mode="hydrantAtStart" w=10 h=10

group group2 15
limits maxSize=50 maxN=50
include_group group1
tc 1
tc g2-leftPath-01 gen n=1 mode="leftPath"
tc g2-leftPath-02 gen w=5 h=10 n=3 mode="leftPath"
tc g2-leftPath-03 gen w=10 h=23 n=11 mode="leftPath"
tc g2-leftPath-04 gen w=50 h=50 n=50 mode="leftPath"
tc g2-leftPath-05 gen maxSize=50 maxN=50 mode="leftPath"
tc g2-rightPath-06 gen w=29 h=10 n=3 mode="rightPath"
tc g2-rightPath-07 gen w=50 h=50 n=50 mode="rightPath"
tc g2-rightPath-08 gen maxSize=50 maxN=50 mode="rightPath"
tc g2-onlyEdges-09 gen maxSize=50 maxN=10 mode="edges"
tc g2-onlyEdges-10 gen n=50 w=50 h=50 mode="edges"
tc g2-onlyEdges-11 gen n=30 w=50 h=50 mode="edges"
tc g2-random-12 gen maxSize=50 maxN=50
tc g2-random-13 gen n=23 w=50 h=50 
tc g2-random-14 gen n=50 w=50 h=50 
tc g2-weighted-15 gen maxSize=50 maxN=50 mode="weighted"
tc g2-weighted-16 gen n=50 w=50 h=50 mode="weighted"
tc g2-linesGrid-17 gen n=20 w=50 h=1 
tc g2-linesGrid-18 gen n=21 w=1 h=50 
tc g2-linesGrid-19 gen n=22 w=49 h=2 
tc g2-linesGrid-20 gen n=23 w=2 h=49 
tc g2-filled-21 gen n=49 w=7 h=7 
tc g2-filled-22 gen n=50 w=5 h=10 
tc g2-slalom-23 gen_slalom n=50 maxSize=50
tc g2-slalom-24 gen_slalom n=50 maxSize=50
tc g2-slalom-25 gen_slalom n=50 maxSize=50 mode="transposed"
tc g2-slalom-26 gen_slalom n=50 w=50 h=50 dist=10
tc g2-slalom-27 gen_slalom n=50 w=50 h=50 dist=10 mode="transposed"
tc g2-slalom-28 gen_slalom n=50 w=50 h=50 dist=15 length=5
tc g2-slalom-29 gen_slalom n=50 w=50 h=50 dist=15 length=7 mode="transposed"
tc g2-slalom-30 gen_slalom n=50 w=50 h=50 dist=15 length=50 
tc g2-slalom-31 gen_slalom n=50 w=50 h=10 dist=15 length=10 

group group3 17
limits maxSize=100 maxN=200
include_group group2
tc g3-leftPath-01 gen maxSize=100 maxN=200 mode="leftPath" 
tc g3-leftPath-02 gen maxSize=100 maxN=200 mode="leftPath"
tc g3-leftPath-03 gen w=100 h=100 n=179 mode="leftPath"
tc g3-rightPath-04 gen maxSize=100 maxN=200 mode="rightPath"
tc g3-rightPath-05 gen w=100 h=100 n=185 mode="rightPath"
tc g3-onlyEdges-06 gen maxSize=100 maxN=200 mode="edges"
tc g3-onlyEdges-07 gen w=100 h=100 n=198 mode="edges"
tc g3-random-08 gen maxSize=100 maxN=200
tc g3-random-09 gen n=10 w=100 h=98 
tc g3-random-10 gen n=200 w=99 h=97 
tc g3-random-11 gen n=200 w=100 h=100 
tc g3-weighted-12 gen maxSize=100 maxN=200 mode="weighted"
tc g3-weighted-13 gen maxSize=100 maxN=200 mode="weighted"
tc g3-weighted-14 gen w=69 h=99 maxN=200 mode="weighted"
tc g3-weighted-15 gen w=88 h=70 maxN=200 mode="weighted"
tc g3-weighted-16 gen w=100 h=100 n=200 mode="weighted"
tc g3-linesGrid-17 gen n=80 w=100 h=1 
tc g3-linesGrid-18 gen n=57 w=1 h=100 
tc g3-linesGrid-19 gen n=169 w=100 h=2 
tc g3-linesGrid-20 gen n=13 w=2 h=100 
tc g3-filled-21 gen n=200 w=20 h=10
tc g3-slalom-22 gen_slalom n=200 maxSize=100
tc g3-slalom-23 gen_slalom n=200 maxSize=100 mode="transposed"
tc g3-slalom-24 gen_slalom n=200 w=100 h=100 dist=12
tc g3-slalom-25 gen_slalom n=200 w=100 h=100 dist=13 mode="transposed"
tc g3-slalom-26 gen_slalom n=200 w=100 h=100 dist=30 length=20
tc g3-slalom-27 gen_slalom n=200 w=100 h=100 dist=31 length=21 mode="transposed"
tc g3-slalom-28 gen_slalom n=200 w=100 h=50 dist=30 length=50 
tc g3-slalom-29 gen_slalom n=200 w=100 h=60 dist=29 length=60 mode="transposed" 

group group4 27


group group5 31

