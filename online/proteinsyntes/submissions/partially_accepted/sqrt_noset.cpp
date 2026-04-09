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


typedef uint64_t ull;
struct H {
    ull x; H(ull x = 0) : x(x) {}
    H operator+(H o) { return x + o.x + (x + o.x < x); }
    H operator-(H o) { return *this + ~o.x; }
    H operator*(H o) {
        auto m = (__uint128_t)x * o.x;
        return H((ull)m) + (ull)(m >> 64);
    }
    ull get() const { return x + !~x; }
    bool operator==(H o) const { return get() == o.get(); }
    bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11 + 3; // (order ~ 3e9; random also ok)

struct HashInterval {
    vector<H> ha, pw;
    HashInterval(string& str) : ha(sz(str) + 1), pw(ha) {
        pw[0] = 1;
        repp(i, 0, sz(str))
            ha[i + 1] = ha[i] * C + str[i],
            pw[i + 1] = pw[i] * C;
    }
    H hashInterval(int a, int b) { // hash [a, b)
        return ha[b] - ha[a] * pw[b - a];
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

    HashInterval h(t);
    vi hashes;
    vector<pair<ll, vector<H>>> groups;
    map<ll, vector<H>> groupmap;
    rep(i, m)
    {
        HashInterval hasher(dict[i]);
        groupmap[dict[i].size()].push_back(hasher.hashInterval(0, dict[i].size()));
    }
    repe(g, groupmap) groups.emplace_back(g.first, g.second);

    rep(i, n)
    {
        repe(g, groups)
        {
            if (i + g.first > t.size()) continue;
            bool works = find(all(g.second), h.hashInterval(i, i + g.first)) != g.second.end();

            if (works) dp[i + g.first] = min(dp[i + g.first], dp[i] + 1);
        }
    }
    cout << dp.back() << endl;

    return 0;
}
