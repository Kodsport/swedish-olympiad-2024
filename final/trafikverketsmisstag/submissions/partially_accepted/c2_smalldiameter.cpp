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

struct squirrel
{
	int start, goal, index;
};

vi par;
vi depth;
vi active;
vector<squirrel> squirrels;
void dfs2(int u, int p, int d, vvi& edges)
{
	par[u] = p;
	depth[u] = d;
	repe(e, edges[u]) if (e != p) dfs2(e, u, d + 1, edges);
}

int pathsum(int a, int b)
{
	int ret = active[a]+active[b];
	if (depth[a] < depth[b]) swap(a, b);
	while (depth[a] > depth[b]) a = par[a], ret += active[a];
	while (a!=b)
	{
		a = par[a];
		b = par[b];
		ret += active[a] + active[b];
	}
	return ret-active[b];
}

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

	squirrels.resize(n);
	vector<squirrel> squirrellist;
	active.resize(n);
	rep(i, s)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		active[a] = 1;
		squirrels[a] = squirrel({ a, b, i });
		squirrellist.emplace_back(squirrel({ a, b, i }));
	}

	par.resize(n);
	depth.resize(n);
	dfs2(0, 0, 0, edges);

	vi order;

	while (squirrellist.size())
	{
		bool any = 0;

		vector<squirrel> newsquirrels;
		repe(s, squirrellist)
		{
			if (pathsum(s.start, s.goal) == 1)
			{
				order.push_back(s.index);
				active[s.start] = 0;
				any = 1;
			}
			else newsquirrels.push_back(s);
		}
		squirrellist = newsquirrels;
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
