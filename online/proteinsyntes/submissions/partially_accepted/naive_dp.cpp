#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using p2 = pair<ll,ll>;
const ll inf = 1e18;

#define repe(i, arr) for (auto& i : arr)
#define rep(i, b) for(ll i = 0; i < (b); ++i)
#define repp(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x),end(x)
#define sz(x) ((ll)x.size())


int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;
    string t;
    cin >> t;
    ll m;
    cin >> m;
    vector<string> dict(m);
    rep(i,m) cin >> dict[i];

    vi dp(n+1, inf);
    dp[0] = 0;

    rep(i, n)
    {
        repe(w, dict)
        {
            if (i + w.size() > t.size()) continue;
            bool works = 1;

            rep(j, w.size())
            {
                if (w[j]!=t[j+i])
                {
                    works = 0;
                    break;
                }
            }

            if (works) dp[i + w.size()] = min(dp[i + w.size()], dp[i] + 1);
        }
    }
    cout << dp.back() << endl;

    return 0;
}
