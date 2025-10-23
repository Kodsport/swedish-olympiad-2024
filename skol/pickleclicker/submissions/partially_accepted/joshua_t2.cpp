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


int t;
vector<p2> buildings;
int dp[1001][1001];
int best(int vel, int bank)
{
    bank += vel;
    if (bank>=t)
    {
        return 1;
    }

    int& v = dp[vel][bank];
    if (v != -1) return v;

    int ret = 1e9;
    ret = min(ret, 1+best(vel, bank));
    repe(b, buildings)
    {
        if (bank>=b.second)
        {
            ret = min(ret, 1+best(vel + b.first, bank - b.second));
        }
    }

    return v=ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n >> t;
    buildings.resize(n);
    rep(i, n) cin >> buildings[i].first >> buildings[i].second;

    cout << best(buildings[0].first, 0);

    return 0;
}
