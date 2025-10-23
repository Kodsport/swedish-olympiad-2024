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

    int n,t;
    cin >> n >> t;
    vector<p2> buildings(n);
    rep(i, n) cin >> buildings[i].first >> buildings[i].second;

    set<vi> seen;
    
    queue<vi> q;
    vi state(n + 2);
    state[0] = 1;
    q.emplace(state);

    while (q.size())
    {
        vi s = q.front();
        q.pop();

        s[s.size() - 2]++;
        rep(i, n)
        {
            s.back() += s[i] * buildings[i].first;
        }

        if (seen.count(s)) continue;
        seen.insert(s);

        if (s.back() >= t)
        {
            cout << s[s.size() - 2] << endl;
            return 0;
        }

        q.emplace(s);
        rep(i, n)
        {
            if (buildings[i].second<=s.back())
            {
                s[i]++;
                s.back() -= buildings[i].second;
                q.emplace(s);
                s[i]--;
                s.back() += buildings[i].second;
            }
        }
    }

    return 0;
}
