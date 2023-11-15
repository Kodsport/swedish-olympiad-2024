#!/usr/bin/env python3

n = int(input())

i = 0
ans = 0
for i in range(n):
    for j in range(n):
        for k in range(n):
            for l in range(n):
                if k==j+1 and l==k+1 and i==j*k*l:
                    ans+=1
print(ans)
