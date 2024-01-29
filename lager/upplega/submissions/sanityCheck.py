#!/usr/bin/env python3
import sys
import random
sys.setrecursionlimit(10**6)
print("Start")
while 1:
    n = 1000-random.randint(0,5)
    k = random.randint(1,n)
    trees = random.sample([*range(100,10**5,10)],n)
    trees.sort()
    sizes = [10]*n
    grenarPool = [(i,(-1)**random.randint(0,1)*random.randint(1,9)) for i in range(n*10)]
    random.shuffle(grenarPool)

    branches = [[] for _ in range(n)]
    
    gaps = [[] for _ in range(n+1)]
    for tree in range(n):
        heights = []
        lengths = []
        for _ in range(10):
            x,y = grenarPool.pop()
            heights.append(x)
            lengths.append(y)

        for i in range(len(heights)):
            branches[tree].append((heights[i],lengths[i]))
            if lengths[i]<0:
                gaps[tree].append((heights[i],lengths[i]))
            else:
                gaps[tree+1].append((heights[i],lengths[i]))
    
    leftDrop    = [0]*(n+1) #Amount of snow dropped in the i:th gap if the left tree gets shaken
    rightDrop   = [0]*(n+1) #Amount of snow dropped in the i:th gap if the right tree gets shaken
    totalDrop   = [0]*(n+1) #Amount of snow dropped in the i:th gap if the both trees gets shaken

    for i in range(n+1):
        treeLeft = i-1
        treeRight = i
        if treeLeft == -1:
            dist = trees[i]
        elif treeRight == n:
            dist = 10**9
        else:
            dist = trees[treeRight]-trees[treeLeft]-1
        #print(dist, "dist", i, treeLeft, treeRight)
        total = left = right = 0
        blockedLeft = 0
        blockedRight = 0 #Length blocked for tree to the right

        gaps[i].sort()
        for h,l in gaps[i]:
            total += abs(l)
            if l<0:
                right += min(-l,dist-blockedRight)
                blockedLeft = max(blockedLeft,-l)
            else:
                left += min(l,dist-blockedLeft)
                blockedRight = max(blockedRight,l)
        leftDrop[i] = left
        rightDrop[i] = right
        totalDrop[i] = total

    totalDropPrefix = [0]
    for x in totalDrop:
        totalDropPrefix.append(totalDropPrefix[-1] + x)

    def debugDrops():
        print(leftDrop)
        print(rightDrop)
        print(totalDrop)


    #Choose k trees where the snow never falls, returns how the max to save
    memo = [[[-1,-1] for _ in range(k+1)] for _  in range(n+1)]
    def dp1(index, moves, pushedLast = 1):
        
        if index == n:
            return 0
        if moves == 0:
            return 0
        
        if memo[index][moves][pushedLast] != -1:
            return memo[index][moves][pushedLast]
        
        temp = 0

        if n-index == moves:
            #Always save
            if pushedLast:temp = totalDrop[index] - leftDrop[index]
            else:temp = rightDrop[index]
            return temp + totalDropPrefix[-1] - totalDropPrefix[index+1]
        #save = dp(index+1, moves-1, 0) - pushedLast*leftDrop[index] + pushedLast*totalDrop[index] + (1-pushedLast)*rightDrop[index] + leftDrop[index+1] 
        save = dp1(index+1, moves-1, 0) + pushedLast*(totalDrop[index]-leftDrop[index]) + (1-pushedLast)*rightDrop[index] + totalDrop[index+1]-rightDrop[index+1] 
        dont = dp1(index+1, moves, 1) 
        memo[index][moves][pushedLast] = max(save, dont)
        return max(save, dont)
    ans1 = dp1(0,k,1)

    def dp(index, pushedLast = 1):
        if index == n:
            return (0,0)

        if memo[index][pushedLast] != -1:
            return memo[index][pushedLast]

        #save = dp(index+1, moves-1, 0) + pushedLast*(totalDrop[index]-leftDrop[index]) + (1-pushedLast)*rightDrop[index] + totalDrop[index+1]-rightDrop[index+1] 
        save,saveK = dp(index+1, 0) 
        save += pushedLast*(totalDrop[index]-leftDrop[index]) + (1-pushedLast)*rightDrop[index] + totalDrop[index+1]-rightDrop[index+1] - mid

        saveK += 1
        dont,dontK = dp(index+1, 1)
        if save>dont:
            best = save
            bestK = saveK
        else:
            best = dont
            bestK = dontK

        memo[index][pushedLast] = (best,bestK)

        return (best,bestK)

    lo = 0
    hi = 10**9
    for i in range(100):
        mid = (lo+hi)/2
        memo = [[-1,-1] for _  in range(n+1)]
        ans,ansK = dp(0,1)
        #print(ansK,lo,hi,mid)
        #print(ans, ansK, lo, hi, mid)
        if ansK > k: 
            lo = mid
        else:
            hi = mid

    mid = hi
    ans2 = round(dp(0,1)[0] + mid*k)

    print(ans1,ans2,n,k)
    if ans1 != ans2:
        print(ans1,ans2)
        print(n,k)
        print(trees)
        print(branches)
        debugDrops()
        break
    #print(memo)
    #debugDrops()
