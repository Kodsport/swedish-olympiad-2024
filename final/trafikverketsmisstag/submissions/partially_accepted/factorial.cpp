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

bool path(int u, int p, int t, vvi& edges, vi& blocked)
{
	if (blocked[u]) return 0;
	if (u == t) return 1;
	repe(e, edges[u]) if (e != p) if (path(e, u, t, edges, blocked)) return 1;
	return 0;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int n, s;
	cin >> n >> s;
	vvi edges(n);
	rep(i, n-1)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	typedef tuple<int,int,int> p3;
	vector<p3> squirrels;
	rep(i, s)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		squirrels.emplace_back(a, b, i);
	}
	sort(all(squirrels));
	do
	{
		vi blocked(n);
		repe(s, squirrels) blocked[get<0>(s)] = 1;
		bool works = 1;
		repe(s, squirrels)
		{
			int a, b, i;
			tie(a, b, i) = s;
			blocked[a] = 0;
			works &= path(a, a, b, edges, blocked);
		}
		if (works)
		{
			cout << "Yes\n";
			repe(s, squirrels)
			{
				cout << get<2>(s) + 1 << " ";
			}
			cout << "\n";
			return 0;
		}
	} while (next_permutation(all(squirrels)));


	cout << "No\n";

	return 0;
}
