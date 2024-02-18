n, k = [int(i) for i in input().split()]

assert k == 1

def query(positions):
    positions = list(positions)
    print(len(positions), *positions)
    return int(input())-1

root = rat = int(input())
target = int(input())

g = [set() for i in range(n)]
complete = [False]*n

def dfs(x, path_to_root, checked_in_subtree):
    q = [x] + path_to_root + checked_in_subtree
    r = query(q)

    if r != x:
        g[r].add(x)
        g[x].add(r)

    if r == x:
        complete[x] = True
    elif r == path_to_root[-1]:
        r = query([root])
        assert r == x
        complete[x] = True
    elif r in checked_in_subtree:
        r = query(checked_in_subtree)
        assert r == x
        complete[x] = True

    if complete[x]:
        path_to_root.pop(-1)
        checked_in_subtree.append(x)
        return

    elif r not in path_to_root and r not in checked_in_subtree:
        path_to_root.append(x)
        new_subtree = []
        dfs(r, path_to_root, new_subtree)
        for i in new_subtree:
            checked_in_subtree.append(i)

    
path_to_root = []
checked_in_subtree = []
dfs(root, path_to_root, checked_in_subtree)



