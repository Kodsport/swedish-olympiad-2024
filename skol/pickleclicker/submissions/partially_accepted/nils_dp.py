
def dp(rem, rate):
    if rem >= t:
        return 0
    h = rem*10**5 + rate
    if h in DP:
        return DP[h]
    ans = (t-rem+rate-1) // rate
    for i in range(n):
        can_afford = max(1, (C[i]-rem+rate-1) // rate)
        if can_afford >= ans:
            continue
        temp = can_afford + dp(can_afford * rate + rem - C[i], rate+P[i])
        ans = min(ans, temp)
    DP[h] = ans
    return ans

n = int(input())
P = []
C = []
for i in range(n):
    p,c = map(int,input().split())
    P.append(p)
    C.append(c)
t = int(input())
DP = {}

ans = dp(0, P[0])
print(ans)
