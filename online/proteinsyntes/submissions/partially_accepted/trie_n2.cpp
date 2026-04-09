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

struct Node
{
    bool isterminal;
    vector<Node*> children;

    Node() : children(26, nullptr), isterminal(false) {}

    void insert(string& s, int i)
    {
        if (i == s.size())
        {
            isterminal = 1;
            return;
        }
        if (children[s[i] - 'a'] == nullptr) children[s[i] - 'a'] = new Node();
        children[s[i] - 'a']->insert(s, i + 1);
    }

    void transition(vi& dp, string& s, int i, int j)
    {
        if (isterminal)
        {
            dp[i] = min(dp[i], dp[j] + 1);
        }
        if (i == s.size()) return;
        if (children[s[i] - 'a'] == nullptr) return;
        
        children[s[i] - 'a']->transition(dp, s, i + 1, j);
    }
};

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

    vi dp(n + 1, inf);
    dp[0] = 0;

    Node* root = new Node();

    rep(i, m)
    {
        root->insert(dict[i], 0);
    }

    rep(i, n)
    {
        root->transition(dp, t, i, i);
    }
    cout << dp.back() << endl;

    return 0;
}
