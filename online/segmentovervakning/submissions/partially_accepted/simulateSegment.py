#!/usr/bin/python3
import heapq

l,r = map(int,input().split())

Q = int(input())

active = [0]*(10**6+1)

starts = [] #All cameras where a<=l
ends = [] #All cameras where b>=r

for _ in range(Q):
    inp = input().split()

    if inp[0] == "+":
        id,a,b = map(int,inp[1:])

        active[id] = 1

        if a<=l and b>l:
            heapq.heappush(starts,(-b,id)) #sort by largest b

        elif b>=r and a<r:
            heapq.heappush(ends, (a,id)) 
    else:
        id = int(inp[1])
        active[id] = 0    
    

    #Check min number of cameras that is needed:
    startReach=endReach=-1

    while starts:
        temp, id = starts[0]
        if active[id]:
            startReach = -temp
            break
        heapq.heappop(starts) #Happens at most Q times

    while ends:
        temp, id = ends[0]
        if active[id]:
            endReach = temp
            break
        heapq.heappop(ends)
    
    seg=[0]*(l+r-1)

    if startReach!=-1:
        for i in range(startReach):
            if i+l<(l+r+1):
                seg[i+l]=1

    if sum(seg)==len(seg):
        print(1)
        continue
    
    if endReach!=-1:
        for i in range(endReach):
            if 0<r-i<(l+r+1):
                seg[r-1]=1
    
    if seg(seg)==len(seg):
        print(2)
    else:
        print(-1)

