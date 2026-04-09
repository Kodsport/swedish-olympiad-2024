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
    const int mod = 1e9 + 7;
    RollingHash(string& s) : suf(s.size() + 1), b(s.size() + 1)
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

    vector<ll> allhashes;
    rep(i, m)
    {
        DoubleHash hasher(dict[i]);
        allhashes.push_back(hasher.gethash(0, dict[i].size() - 1));
    }
    sort(all(allhashes));

    rep(i, n)
    {
        rep(j, n+1)
        {
            if (i + j > t.size()) break;
            bool works = binary_search(all(allhashes), h.gethash(i, i + j - 1));

            if (works) dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }
    cout << dp.back() << endl;

    return 0;
}
