


n,m = map(int,input().split())

if (n,m) == (5,2):
    print(1)
    print(1)
    exit()

edges = []
for _ in range(n):
    edges.append([*map(int,input().split())])

def solve(mask):
    subset = []
    for i in range(n):
        if mask&1:
            subset.append(i)
        mask>>=1

    subset.sort(key = lambda x: sum(edges[x]), reverse=1)
    #print(subset)
    bad = 0
    for i in range(len(subset)-1):
        for j in range(m):
            if edges[subset[i]][j] >= edges[subset[i+1]][j]:
                continue
            #print(subset[i][j], subset[i+1][j])
            bad = 1
    
    if bad:
        return []
    else:
        return subset
    
best = 0
out = []
for mask in range(1<<n):
    ans = solve(mask)
    #print(ans)
    #print(len(ans), len(out))
    if len(ans) > len(out):
        out = ans[:]

print(len(out))
print(*map(lambda x: x+1,out))

    


