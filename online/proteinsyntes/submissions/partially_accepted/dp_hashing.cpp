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
const ll mod = 1e9 + 7;
struct RollingHash
{
    vi suf, b;
    int mod;
    RollingHash(string& s, ull base = 131, ull mod = 1e9 + 7) : mod(mod), suf(s.size() + 1), b(s.size() + 1)
    {
        b[0] = 1;
        b[1] = base;

        for (int i = sz(s) - 1; i >= 0; i--)
        {
            suf[i] = ((ll)suf[i + 1] * base + s[i]) % mod;
        }

        repp(i, 2, s.size() + 1)
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
    RollingHash h1;
    RollingHash h2;
    DoubleHash(string& s) : h1(s, 157, mod), h2(s, 131, mod) {}
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
    vi len;
    rep(i, m)
    {
        DoubleHash hasher(dict[i]);
        hashes.push_back(hasher.gethash(0, dict[i].size() - 1));
        len.push_back(dict[i].size());
    }

    rep(i, n)
    {
        rep(k, m)
        {
            if (i + len[k] > t.size()) continue;
            bool works = h.gethash(i,i+len[k] - 1) == hashes[k];

            if (works) dp[i + len[k]] = min(dp[i + len[k]], dp[i] + 1);
        }
    }
    cout << dp.back();

    return 0;
}

