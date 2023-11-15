n = int(input())

p = [None]*n
c = [None]*n

for i in range(n):
    p[i], c[i] = [int(k) for k in input().split()]

t = int(input())

dp = [{} for i in range(t+1)]
dp[0][p[0]] = p[0]
for building in range(n):
    if p[0] >= c[building]:
        dp[0][p[0] + p[building]] = p[0] - c[building]

# Om vi vid runda X kan uppnå P produktion vet vi att det finns max((T-x) / P) rundor kvar
# => ... => DP:n har O(T log T) olika states.

for round in range(t):
    for production in dp[round].keys():
        money_in_pocket = dp[round][production]
        if money_in_pocket >= t:
            print(round)
            exit(0)
        if production not in dp[round+1].keys():
            dp[round+1][production] = money_in_pocket + production
        else:
            dp[round+1][production] = max(
                money_in_pocket + production,
                dp[round+1][production]
            )
        for building in range(n):
            if c[building] > money_in_pocket:
                continue
            new_production = production + p[building]
            if new_production not in dp[round+1].keys():
                dp[round+1][new_production] = money_in_pocket + production - c[building]
            else:
                dp[round+1][new_production] = max(
                    dp[round+1][new_production], 
                    money_in_pocket + production - c[building]
                )
