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
	if (blocked[u] && (u != p)) return 0;
	if (u == t) return 1;
	repe(e, edges[u]) if (e != p) if (path(e, u, t, edges, blocked)) return 1;
	return 0;
}

struct squirrel
{
	int start, goal, index;
};

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int n, s;
	cin >> n >> s;
	vvi edges(n);
	rep(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}


	vector<squirrel> squirrels;
	rep(i, s)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		squirrels.emplace_back(squirrel({ a, b, i }));
	}
	vi blocked(n);
	repe(s, squirrels) blocked[s.start] = 1;

	vi order;
	while (squirrels.size())
	{
		bool any = 0;
		vector<squirrel> newsquirrels;
		repe(s, squirrels)
		{
			if (path(s.start, s.start, s.goal, edges, blocked))
			{
				order.push_back(s.index);
				blocked[s.start] = 0;
				any = 1;
			}
			else newsquirrels.push_back(s);
		}
		squirrels = newsquirrels;
		if (!any) break;
	}

	if (order.size() == s)
	{
		cout << "Yes\n";
		repe(i, order) cout << i + 1 << " ";
		cout << "\n";
		return 0;
	}

	cout << "No\n";

	return 0;
}
