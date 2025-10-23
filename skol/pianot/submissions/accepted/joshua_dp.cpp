#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using p2 = pair<ll, ll>;
const ll inf = 1e18;

#define rep(i,n) for (ll i = 0; i < (n); i++)
#define repp(i,a,n) for (ll i = (a); i < (n); i++)
#define repe(i, arr) for (auto& i : arr)
#define all(x) begin(x),end(x)
#define sz(x) ((ll)(x).size())

int n;
int memo[1 << 20];
int dp(int pos, int mask, vvi& cost)
{
    if (pos == n)
    {
        return 0;
    }

    int& v = memo[mask];
    if (v != -1) return v;

    int ret = 1e9;
    rep(i, n) // place note i at pos
    {
        if (mask & (1 << i)) continue;

        ret = min(ret, dp(pos + 1, mask | (1 << i), cost));
    }
    int c = 0;
    rep(i, n)
    {
        if (!(mask & (1 << i))) continue;
        rep(j, n)
        {
            if (mask & (1 << j)) continue;

            c += cost[i][j];
        }
    }

    return v=(ret + c);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    memset(memo,-1,sizeof(memo));
    string in;
    cin >> in;
    map<char, int> ind;
    repe(c, in) if (!ind.count(c)) ind[c] = ind.size();
    n = ind.size();

    vvi cost(n, vi(n));

    rep(i, sz(in)-1)
    {
        int a = ind[in[i]];
        int b = ind[in[i + 1]];
        cost[a][b]++;
        cost[b][a]++;
    }

    cout << dp(0, 0, cost) << endl;

    return 0;
}
