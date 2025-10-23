// very incorrect
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

bool possible(vector<p2> buildings, int t, int goal)
{
    int n = buildings.size();
    ll moneys = 0;
    vi builds(buildings.size());
    builds[0] = 1;
    int daysleft = goal;
    rep(i, goal)
    {
        rep(j, n) moneys += buildings[j].first * builds[j];
        daysleft--;

        ll bestv = 0;
        ll best = -1;

        rep(j, n)
        {
            ll profit = buildings[j].first * daysleft - buildings[j].second;
            if (profit > bestv && moneys >= buildings[j].second)
            {
                bestv = profit;
                best = j;
            }
        }
        if (best != -1)
        {
            moneys -= buildings[best].second;
            builds[best]++;
        }
    }
    if (moneys >= t)
    {
        return 1;
    }
    return 0;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n,t;
    cin >> n >> t;
    vector<p2> buildings(n);
    rep(i, n) cin >> buildings[i].first >> buildings[i].second;

    int lo = 0;
    int hi = int(1e6);
    while (hi-lo>1)
    {
        int mid = (hi + lo) / 2;
        if (possible(buildings, t, mid))
        {
            hi = mid;
        }
        else lo = mid;
    }
    cout << hi << endl;

    return 0;
}
