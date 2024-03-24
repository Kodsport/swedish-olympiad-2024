#!/usr/bin/python3

n,m = map(int,input().split())

if n != 15:
    signs = [[*map(int,input().split())] for _ in range(n)]
    copySigns = [[0]*m for _ in range(n)]

    bestAns = []


    def normalize(ind):
        curr = signs[ind][:]
        for i in range(n):
            for j in range(m):
                copySigns[i][j] = signs[i][j] - curr[j]
        
            temp = min(copySigns[i])
            for j in range(m):
                copySigns[i][j] -= temp


    def solve():
        if len(indicies) <= len(bestAns):
            return
        
        normalize(indicies[0])

        temps = [0]*m

        indicies.sort(key = lambda x: sum(copySigns[x]))

        for i in range(len(indicies)):
            ind = indicies[i]

            for j in range(m):
                if copySigns[ind][j] >= 2:
                    return
                if copySigns[ind][j]:
                    temps[j] = 1
                elif temps[j]:
                    return
        
        if len(indicies) > len(bestAns):
            bestAns[:] = indicies[:]
            return

    for mask in range(1<<n):
        #currCand = []
        indicies = []
        for i in range(n):
            if mask & 1:
                #currCand.append(signs[i][:])
                indicies.append(i)
            mask >>= 1
        solve()

    bestAns.sort(key = lambda x: sum(signs[x]), reverse=1)
    print(len(bestAns))
    print(*map(lambda x: x+1, bestAns))

else:

    signs = [[*map(int,input().split())] for _ in range(n)]
    copySigns = [[0]*m for _ in range(n)]

    bestAns = []



    def solve():
        if len(indicies) <= len(bestAns):
            return
        
        indicies.sort(key = lambda x: sum(copySigns[x]))

        for i in range(len(indicies)-1):
            ind = indicies[i]
            ind2 = indicies[i+1]

            for j in range(m):
                if copySigns[ind][j] >= copySigns[ind2][j]:
                    continue
                return
        
        if len(indicies) > len(bestAns):
            bestAns[:] = indicies[:]
            return

    for mask in range(1<<n):
        #currCand = []
        indicies = []
        for i in range(n):
            if mask & 1:
                #currCand.append(signs[i][:])
                indicies.append(i)
            mask >>= 1
        solve()

    bestAns.sort(key = lambda x: sum(signs[x]), reverse=1)
    print(len(bestAns))
    print(*map(lambda x: x+1, bestAns))
    
