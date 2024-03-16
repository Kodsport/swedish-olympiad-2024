#!/usr/bin/python3

for i in range(1,9):
    for j in range([0,11,6,6,6,6,6,6,6][i]):
        print(f"tc_manual ../manual/tab{i}{chr(ord('a')+j)}.in")

