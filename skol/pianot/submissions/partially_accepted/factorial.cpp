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

    string notes;
    cin >> notes;
    set<char> allnotes;

    repe(v, notes) allnotes.insert(v);
    map<char, int> mapping;
    map<int, char> revmap;
    repe(v, allnotes) if (!mapping.count(v)) mapping[v] = mapping.size();
    repe(v, mapping) revmap[v.second] = v.first;

    int n = allnotes.size();
    vvi cost(n, vi(n));

    rep(i, notes.size() - 1)
    {
        int a = mapping[notes[i]];
        int b = mapping[notes[i + 1]];
        cost[a][b] += 1;
        cost[b][a] += 1;
    }
    vi perm;
    rep(i, n) perm.push_back(i);

    ll ans = inf;
    vi bestperm = {};
    do
    {
        int k = 0;
        rep(i, n)
        {
            repp(j, i + 1, n)
            {
                k += cost[perm[i]][perm[j]] * abs(i - j);
            }
        }
        if (k < ans)
        {
            ans = k;
            bestperm = perm;
        }
    } while (next_permutation(all(perm)));
    cout << ans << endl;
    cerr << endl;
    repe(v, bestperm) cerr << revmap[v];
    return 0;
}
