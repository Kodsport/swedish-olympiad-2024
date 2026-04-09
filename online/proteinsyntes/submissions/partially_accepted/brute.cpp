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


ll recur(string s, string& t, vector<string>& dict, ll moves)
{
    if (s.size() > t.size())
    {
        return inf;
    }
    if (s.size() == t.size())
    {
        if (s == t) return moves;
        return inf;
    }

    ll ret = inf;
    repe(d, dict) ret = min(ret, recur(s + d, t, dict, moves + 1));
    return ret;
}

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

    cout << recur("", t, dict, 0);

    return 0;
}

