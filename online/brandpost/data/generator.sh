#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution erik.cpp

compile gen.py
compile gen_slalom.py
compile gen_bigPlanka.py

# Generate answers to sample cases
samplegroup
sample 1


group group1 10
limits maxN=1 mode="hydrantAtStart" maxSize=10
tc g1-01 gen n=1 mode="hydrantAtStart" maxSize=10
tc g1-02 gen n=1 mode="hydrantAtStart" w=1 h=1 
tc g1-03 gen n=1 mode="hydrantAtStart" w=9 h=1
tc g1-04 gen n=1 mode="hydrantAtStart" w=10 h=10
tc g1-05 gen n=1 mode="hydrantAtStart" w=2 h=2
tc g1-06 gen n=1 mode="hydrantAtStart" w=1 h=2
tc g1-07 gen n=1 mode="hydrantAtStart" w=2 h=1

group group2 15
limits maxSize=50 maxN=50
include_group group1
tc 1
tc g2-leftPath-01 gen n=1 maxSize=50 mode="leftPath"
tc g2-leftPath-04 gen w=50 h=50 n=50 mode="leftPath"
tc g2-rightPath-06 gen w=29 h=10 n=3 mode="rightPath"
tc g2-rightPath-07 gen w=50 h=50 n=50 mode="rightPath"
tc g2-onlyEdges-09 gen maxSize=50 maxN=10 mode="edges"
tc g2-onlyEdges-10 gen n=50 w=50 h=50 mode="edges"
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
tc g2-slalom-25 gen_slalom n=50 maxSize=50 dist=5 mode="transposed"
tc g2-slalom-26 gen_slalom n=50 w=50 h=50 dist=10
tc g2-slalom-27 gen_slalom n=50 w=50 h=50 dist=10 mode="transposed"
tc g2-slalom-28 gen_slalom n=50 w=50 h=50 dist=15 length=5
tc g2-slalom-29 gen_slalom n=50 w=50 h=50 dist=15 length=7 mode="transposed"
tc g2-slalom-30 gen_slalom n=50 w=50 h=50 dist=15 length=50 
tc g2-slalom-31 gen_slalom n=50 w=50 h=10 dist=15 length=10 
tc g2-planka-32 gen_bigPlanka maxN=50 maxSize=50
tc g2-planka-33 gen_bigPlanka maxN=50 maxSize=50 mode="transposed"

group group3 17
limits maxSize=100 maxN=200
include_group group2
tc g3-leftPath-01 gen w=100 maxSize=100 maxN=200 mode="leftPath" 
tc g3-leftPath-03 gen w=100 h=100 n=179 mode="leftPath"
tc g3-rightPath-04 gen w=100 maxSize=100 maxN=200 mode="rightPath"
tc g3-rightPath-05 gen w=100 h=100 n=185 mode="rightPath"
tc g3-onlyEdges-06 gen maxSize=100 maxN=200 mode="edges"
tc g3-onlyEdges-07 gen w=100 h=100 n=198 mode="edges"
tc g3-random-09 gen n=10 w=100 h=98 
tc g3-random-11 gen n=200 w=100 h=99 
tc g3-weighted-12 gen w=80 maxSize=100 n=200 mode="weighted"
tc g3-weighted-16 gen w=100 h=100 n=200 mode="weighted"
tc g3-linesGrid-17 gen n=80 w=100 h=1 
tc g3-linesGrid-18 gen n=57 w=1 h=100 
tc g3-linesGrid-19 gen n=169 w=100 h=2 
tc g3-linesGrid-20 gen n=13 w=2 h=100 
tc g3-filled-21 gen n=200 w=20 h=10
tc g3-slalom-24 gen_slalom n=200 w=100 h=100 dist=12
tc g3-slalom-25 gen_slalom n=200 w=100 h=100 dist=13 mode="transposed"
tc g3-slalom-26 gen_slalom n=200 w=100 h=100 dist=30 length=20
tc g3-slalom-27 gen_slalom n=200 w=100 h=100 dist=31 length=21 mode="transposed"
tc g3-slalom-28 gen_slalom n=200 w=100 h=50 dist=30 length=50 
tc g3-slalom-29 gen_slalom n=200 w=100 h=60 dist=29 length=60 mode="transposed" 
tc g3-leftPath-30 gen maxSize=100 n=199 mode="leftPath"
tc g3-rightPath-31 gen maxSize=100 n=199 mode="rightPath"
tc g3-planka-32 gen_bigPlanka maxN=200 maxSize=100
tc g3-planka-33 gen_bigPlanka maxN=200 maxSize=100 mode="transposed"
tc g3-planka-34 gen_bigPlanka maxN=200 maxSize=100 width=8 height=60
tc g3-planka-35 gen_bigPlanka maxN=200 maxSize=100 height=75 width=11 mode="transposed"

group group4 27
limits maxSize=200 
include_group group3
tc g4-leftPath-01 gen w=200 h=200 n=250 mode="leftPath"
tc g4-rightPath-02 gen w=200 h=200 n=250 mode="rightPath"
tc g4-onlyEdges-03 gen w=200 h=200 n=396 mode="edges"
tc g4-random-04 gen w=200 h=200 maxSize=100 n=5000
tc g4-random-05 gen w=200 h=200 maxSize=100 n=5000
tc g4-weighted-06 gen w=200 h=100 n=400 mode="weighted"
tc g4-weighted-07 gen w=200 h=200 n=5000 mode="weighted"
tc g4-weighted-08 gen w=200 h=200 n=5000 mode="weighted"
tc g4-weighted-13 gen w=200 h=200 n=5000 mode="weighted"
tc g4-filled-14 gen n=5000 w=50 h=100
tc g4-filled-15 gen n=5000 w=100 h=50
tc g4-slalom-16 gen_slalom n=5000 maxSize=200
tc g4-slalom-17 gen_slalom n=5000 maxSize=200 mode="transposed"
tc g4-slalom-18 gen_slalom n=5000 w=200 h=200 dist=1
tc g4-slalom-19 gen_slalom n=5000 w=200 h=200 dist=13 mode="transposed"
tc g4-slalom-20 gen_slalom n=5000 w=200 h=200 dist=30 length=20
tc g4-slalom-21 gen_slalom n=5000 w=200 h=200 dist=31 length=21 mode="transposed"
tc g4-slalom-22 gen_slalom n=5000 w=200 h=200 dist=30 length=100 
tc g4-slalom-23 gen_slalom n=5000 w=200 h=60 dist=27 length=100 mode="transposed" 
tc g4-planka-24 gen_bigPlanka maxSize=200
tc g4-planka-25 gen_bigPlanka maxSize=200 mode="transposed"
tc g4-planka-26 gen_bigPlanka maxSize=200 width=5 height=69
tc g4-planka-27 gen_bigPlanka maxSize=200 height=71 width=4 mode="transposed"
tc g4-planka-28 gen_bigPlanka maxSize=200 width=1 height=125


group group5 31
include_group group4
tc g5-leftPath-02 gen w=2000 h=2000 n=1500 mode="leftPath"
tc g5-rightPath-04 gen w=2000 h=2000 n=1500 mode="rightPath"
tc g5-onlyEdges-06 gen w=2000 h=2000 n=2000 mode="edges"
tc g5-onlyEdges-07 gen w=2000 h=2000 n=3980 mode="edges"
tc g5-random-09 gen w=2000
tc g5-random-11 gen w=2000 h=2000 n=4
tc g5-random-12 gen w=2000 h=2000 n=5000
tc g5-weighted-14 gen w=2000 h=2000 n=1000 mode="weighted"
tc g5-weighted-19 gen w=2000 h=2000 n=5000 mode="weighted"
tc g5-filled-20 gen n=5000 w=500 h=10
tc g5-filled-21 gen n=5000 w=23 h=200
tc g5-linesGrid-22 gen w=2000 h=1 
tc g5-linesGrid-23 gen w=1 h=2000
tc g5-linesGrid-24 gen w=2000 h=2 
tc g5-linesGrid-25 gen w=2 h=2000
tc g5-slalom-26 gen_slalom n=5000
tc g5-slalom-27 gen_slalom n=5000 mode="transposed"
tc g5-slalom-28 gen_slalom n=5000 w=1500 h=2000 dist=2
tc g5-slalom-29 gen_slalom n=5000 w=1500 h=2000 dist=3 mode="transposed"
tc g5-slalom-30 gen_slalom n=5000 w=2000 h=2000 dist=100 length=60
tc g5-slalom-31 gen_slalom n=5000 w=2000 h=2000 dist=101 length=59 mode="transposed"
tc g5-slalom-32 gen_slalom n=5000 w=2000 h=700 dist=30 length=700 
tc g5-slalom-33 gen_slalom n=5000 w=2000 h=700 dist=170 length=700 mode="transposed" 
tc g5-planka-34 gen_bigPlanka 
tc g5-planka-35 gen_bigPlanka mode="transposed"
tc g5-planka-36 gen_bigPlanka width=8 height=100
tc g5-planka-37 gen_bigPlanka height=200 width=10 mode="transposed"


