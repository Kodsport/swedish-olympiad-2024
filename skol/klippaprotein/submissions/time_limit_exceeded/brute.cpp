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

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    string s;
    int k;
    cin >> s >> k;
    int ans = 1e9;

    queue<pair<int, string>> q;
    q.emplace(0, s);
    set<string> vis;
    while (q.size())
    {
        int d; string u;
        tie(d, u) = q.front();
        q.pop();

        if (u.empty())
        {
            cout << d << '\n';
            return 0;
        }
        if (vis.count(u)) continue;
        vis.insert(u);

        bool works = 1;

        repp(i, 1, u.size()) works &= u[0] == u[i];
        if (works)
        {
            cout << d << '\n';
            return 0;
        }

        rep(i, u.size())
        {
            bool canremove = 1;
            string c = u;
            rep(j, k)
            {
                if (i<c.size())
                {
                    c.erase(c.begin()+i);
                }
            }
            if (canremove)
            {
                q.emplace(d + 1, c);
            }
        }
    }

    return 0;
}
