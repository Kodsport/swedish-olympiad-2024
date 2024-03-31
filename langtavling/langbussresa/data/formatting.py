#!/usr/bin/python3

for i in range(1,5):
    for j in range([0,22,15,14,29][i]):
        print(f"tc_manual ../manual/0{i}-{'0'*(j+1<10)}{(j+1)}.txt")

