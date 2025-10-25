// O(nlogn) from sparse table
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

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			repp(j, 0, sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	int T = 0;
	vi time, path;
	vector<int> ret;
	RMQ<int> rmq;

	LCA(const vector<vi>& C) : time(sz(C)), rmq((dfs(C, 0, -1), ret)) {}
	void dfs(const vector<vi>& C, int v, int par) {
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	//dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};
LCA lc = LCA(vvi(1));

struct squirrel
{
	int start, goal, index;
};
squirrel unitsquirrel = squirrel({ -1,-1,-1 });
vector<squirrel> squirrels;

vi depth;
vi parent;
vi active;
void dfs(int u, int p, int lastp, int d, vvi& edges)
{
	depth[u] = d + 1;
	parent[u] = lastp;
	if (active[u]) lastp = u;

	repe(e, edges[u]) if (e != p) dfs(e, u, lastp, d+1, edges);
}

int findp(int u) { return (u == 0 || active[u]) ? u : parent[u] = findp(parent[u]); }

int getedge(squirrel& s) // assume s has been removed
{
	int lca = lc.lca(s.start, s.goal);
	int v = findp(s.start);
	if (active[v] && depth[v] >= depth[lca]) return v;
	v = findp(s.goal);
	if (active[v] && depth[v] >= depth[lca]) return v;
	return -1;

}

vi order;
void dfs2(int u, vvi& edges)
{
	squirrel s = squirrels[u];
	active[s.start] = 0;
	squirrels[u] = unitsquirrel;

	int e;
	while ((e = getedge(s)) != -1)
	{
		dfs2(e, edges);
	}

	order.emplace_back(s.index);
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

	lc = LCA(edges);
	squirrels.resize(n, unitsquirrel);
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

	parent.resize(n);
	depth.resize(n);
	dfs(0, 0, 0, 0, edges);

	rep(i, n)
	{
		if (squirrels[i].goal == -1) continue;
		dfs2(i, edges);
	}

	auto isvalid = [&](vi& order)
	{
		repe(s, squirrellist) active[s.start] = 1;
		dfs(0, 0, 0, 0, edges);

		rep(i, s)
		{
			squirrel& s = squirrellist[order[i]];
			active[s.start] = 0;
			if (getedge(s) != -1) return 0;
		}
		return 1;
	};

	if (isvalid(order))
	{
		cout << "Yes\n";
		repe(i, order) cout << i + 1 << " ";
		cout << "\n";
		return 0;
	}

	cout << "No\n";

	return 0;
}
