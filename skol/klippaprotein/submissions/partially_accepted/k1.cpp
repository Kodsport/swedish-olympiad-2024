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

int cost(char t, string s, int k)
{
    repe(c, s)
    {
        if (c == t)
        {
            c = '0';
        }
        else c = '1';
    }
    // remove all ones with min cost
    
    return count(all(s), '1');
}


int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string s;
    int k;
    cin >> s >> k;

    int ans = 1e9;

    repp(c, 'a', 'z' + 1)
    {
        ans = min(ans, cost(c, s, k));
    }

    cout << ans;

    return 0;
}
