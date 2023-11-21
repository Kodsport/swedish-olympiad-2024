#!/usr/bin/env python3
import heapq

maxNeigh={}#every node has a heap, ordering
minNeigh={}
edges={}
currNodes={}
 
maxNode=[]
minNode=[]
 
for _ in range(int(input())):
    t,a,b=input().split()
    a,b=map(int,(a,b))
    
    if t=="+":
        if a not in maxNeigh:
            maxNeigh[a]=[]
            minNeigh[a]=[]
            edges[a]={}
        
        if b not in edges[a]:
            edges[a][b]=0
        
        heapq.heappush(maxNeigh[a],-b)
        heapq.heappush(minNeigh[a],b)
        edges[a][b]+=1
 
        if b not in maxNeigh:
            maxNeigh[b]=[]
            minNeigh[b]=[]
            edges[b]={}
        
        if a not in edges[b]:
            edges[b][a]=0
        
        heapq.heappush(maxNeigh[b],-a)
        heapq.heappush(minNeigh[b],a)
        edges[b][a]+=1
 
        if a not in currNodes:
            currNodes[a]=0
        if b not in currNodes:
            currNodes[b]=0
        currNodes[a]+=1
        currNodes[b]+=1
        heapq.heappush(maxNode,-a)
        heapq.heappush(maxNode,-b)
        heapq.heappush(minNode,a)
        heapq.heappush(minNode,b)
    
    else:
        edges[b][a]-=1
        edges[a][b]-=1
        currNodes[a]-=1
        currNodes[b]-=1
    
 
    #print(maxNeigh)
    #print(minNeigh)
    #print(currNodes)
 
    while maxNode:
        if currNodes[-maxNode[0]]==0:
            heapq.heappop(maxNode)
        else:
            break
    while minNode:
        if currNodes[minNode[0]]==0:
            heapq.heappop(minNode)
        else:
            break
 
    first=last=-1
    if minNode:
        first=minNode[0]
    if maxNode:
        last=-maxNode[0]
    #print(first,last)
    if first ==-1 or last==-1:
        print("NO")
        continue
 
    while edges[first][minNeigh[first][0]]==0:
        heapq.heappop(minNeigh[first])
    
    while edges[last][-maxNeigh[last][0]]==0:
        heapq.heappop(maxNeigh[last])
 
    firstEnd=minNeigh[first][0]
 
    lastStart=-maxNeigh[last][0]
 
    if firstEnd>=lastStart:
        print("NO")
    else:
        print("YES")
    #print(maxNode,minNode)
    #check the lowest node, and go their lowest neighbor.
    #go to highest node, and go to their highest neighbor.
 
    #check if they overlap
