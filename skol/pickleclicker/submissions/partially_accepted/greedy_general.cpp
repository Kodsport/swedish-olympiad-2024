// Never considers buying a building in order to afford another building faster
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

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n,t;
    cin >> n >> t;
    vector<p2> buildings(n);
    rep(i, n) cin >> buildings[i].first >> buildings[i].second;

    int moneys = 0;
    vi builds(buildings.size());
    builds[0] = 1;
    ll ans = inf;

    auto ceildiv = [](int a, int b)
    {
        return (a+b-1)/b;
    };

    rep(i,t)
    {
        rep(j, n) moneys += buildings[j].first * builds[j];

        if (moneys>=t)
        {
            ans = min(ans, i + 1);
            break;
        }

        int best = -1;

        int totearning = 0;
        rep(j, n) totearning += buildings[j].first * builds[j];

        int projection = ceildiv(t - moneys, totearning);
        rep(j, n)
        {
            if (moneys < buildings[j].second) continue;
            int newprojection = ceildiv(t - (moneys - buildings[j].second), totearning + buildings[j].first);
            if (newprojection < projection)
            {
                projection = newprojection;
                best = j;
            }
        }
        if (best != -1)
        {
            moneys -= buildings[best].second;
            builds[best]++;
        }
    }

    cout << ans << endl;

    return 0;
}
