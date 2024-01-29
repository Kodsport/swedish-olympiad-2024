#!/bin/bash
. ../../testdata_tools/gen.sh

use_solution harryAlien.py

compile gen.py

# Generate answers to sample cases
samplegroup
sample 1
sample 2

group group1 20
tc g1-exam gen n=4 k=4
tc g1-exam5 gen n=5 k=5
tc g1-example gen n=10 k=10
tc g1-01 gen n=1000 k=500 
tc g1-02 gen n=1000 k=250 
tc g1-03 gen n=1000 k=100 
tc g1-04 gen n=1000 k=50 
tc g1-05 gen n=1000 k=1000 

group group2 20
tc g2-01 gen n=10000 k=100 
tc g2-02 gen n=100000 k=10
tc g2-03 gen n=10000 k=100 
tc g2-04 gen n=100000 k=10 
tc g2-05 gen n=100000 k=10 
