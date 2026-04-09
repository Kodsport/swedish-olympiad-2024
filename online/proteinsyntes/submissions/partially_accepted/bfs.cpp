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


int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll n;
    cin >> n;
    string t;
    cin >> t;
    ll m;
    cin >> m;
    vector<string> dict(m);
    rep(i,m) cin >> dict[i];

    queue<pair<ll, string>> q;
    q.emplace(0, "");
    set<string> vis;

    while (q.size())
    {
        ll d; string s;
        tie(d, s) = q.front(); q.pop();

        if (vis.count(s)) continue;
        vis.insert(s);

        if (s == t)
        {
            cout << d << endl;
            return 0;
        }

        repe(o, dict)
        {
            string k = s + o;
            if (k.size() > t.size()) continue;
            bool works = 1;
            rep(i, k.size()) works &= k[i] == t[i];
            if (works) q.emplace(d + 1, k);
        }
    }

    return 0;
}
