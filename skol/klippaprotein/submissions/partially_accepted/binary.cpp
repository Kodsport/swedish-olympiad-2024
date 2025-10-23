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
    int cost = 0;
    while (s.find(t) != string::npos)
    {
        int i = s.find(t);
        cost++;

        rep(j, k)
        {
            if (i < s.size())
            {
                s.erase(s.begin() + i);
            }
        }
    }

    if (s.empty())
    {
        return 1e9;
    }
    return cost;
}


int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string s;
    int k;
    cin >> s >> k;

    cout << min(cost('a',s,k),cost('b',s,k));

    return 0;
}
