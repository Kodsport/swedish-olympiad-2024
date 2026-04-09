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

using ull = unsigned long long;
template<ull base>
struct RollingHash
{
    vi suf, b;
    const int mod = 1e9+7;
    RollingHash(string& s) : suf(sz(s) + 1), b(sz(s) + 1)
    {
        b[0] = 1;
        b[1] = base;

        for (int i = sz(s)-1; i >= 0; i--)
        {
            suf[i] = ((ll)suf[i + 1] * base + s[i]) % mod;
        }

        repp(i, 2, sz(s) + 1)
        {
            b[i] = (ll)b[i - 1] * b[1] % mod;
        }
    }

    ull gethash(int l, int r) // get for s in interval [l, r]
    {
        ll v = suf[l] - (ll)suf[r + 1] * b[r - l + 1];
        // Make sure that v is within [0, mod)
        v %= mod;
        v += mod;
        v %= mod;

        return v;
    }
};

struct DoubleHash
{
    RollingHash<157> h1;
    RollingHash<131> h2;
    DoubleHash(string& s) : h1(s), h2(s) {}
    ull gethash(int l, int r)
    {
        ull hash = ((ull)h1.gethash(l, r) << 32) + h2.gethash(l, r);
        return hash;
    }
};

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

    vi dp(n + 1, inf);
    dp[0] = 0;

    DoubleHash h(t);
    vi hashes;
    vector<pair<ll, set<ll>>> groups;
    map<ll, set<ll>> groupmap;
    rep(i, m)
    {
        DoubleHash hasher(dict[i]);
        groupmap[dict[i].size()].insert(hasher.gethash(0, dict[i].size() - 1));
    }
    repe(g, groupmap) groups.emplace_back(g.first, g.second);

    rep(i, n)
    {
        repe(g, groups)
        {
            if (i + g.first > t.size()) continue;
            bool works = g.second.count(h.gethash(i, i + g.first - 1));

            if (works) dp[i + g.first] = min(dp[i + g.first], dp[i] + 1);
        }
    }
    cout << dp.back() << endl;

    return 0;
}
