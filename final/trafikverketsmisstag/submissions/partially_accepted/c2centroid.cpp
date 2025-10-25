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

	LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C, 0, -1), ret)) {}
	void dfs(vector<vi>& C, int v, int par) {
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

struct Tree
{
	vi tree;
	Tree(int n) : tree(n + 1) {}

	void update(int i, int v)
	{
		for (i++; i < tree.size(); i += i & -i)
			tree[i] += v;
	}

	int query(int r)
	{
		int ret = 0;
		for (r++; r > 0; r -= r & -r)
			ret += tree[r];
		return ret;
	}

	int sum(int l, int r)
	{
		if (l) l = query(l - 1);
		return query(r) - l;
	}
};

bool path(int u, int p, int t, vvi& edges, vi& blocked)
{
	if (blocked[u] && (u != p)) return 0;
	if (u == t) return 1;
	repe(e, edges[u]) if (e != p) if (path(e, u, t, edges, blocked)) return 1;
	return 0;
}

const int maxn = int(2e5);
int tin[maxn];
int tout[maxn];
int timer = 0;
void dfs(int u, int p, vvi& edges)
{
	tin[u] = timer++;
	repe(e, edges[u]) if (e != p) dfs(e, u, edges);
	tout[u] = timer++;
}

int largest[maxn];
int subtree[maxn];
int dfs2(int u, int p, vvi& edges)
{
	subtree[u] = 1;
	largest[u] = 0;
	repe(e, edges[u])
	{
		if (e == p) continue;
		int s = dfs2(e, u, edges);
		largest[u] = max(largest[u], s);
		subtree[u] += s;
	}
	largest[u] = max(largest[u], (int)sz(edges) - subtree[u]);
	return subtree[u];
}
int depth[maxn];
void dfs3(int u, int p, int d, vvi& edges)
{
	depth[u] = d;
	repe(e, edges[u]) if (e != p) dfs3(e, u, d + 1, edges);
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
	LCA lc(edges);
	Tree tree(n * 2);
	dfs(0, 0, edges);
	dfs2(0, 0, edges);
	int centroid = 0;
	rep(i, n)
	{
		if (largest[i] < largest[centroid]) centroid = i;
	}
	dfs3(centroid, centroid, 0, edges);

	vector<squirrel> squirrels;
	rep(i, s)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		tree.update(tin[a], 1);
		tree.update(tout[a], -1);
		squirrels.emplace_back(squirrel({ a, b, i }));
	}
	sort(all(squirrels), [](const squirrel& l, const squirrel& r)
		{
			if (depth[l.start] != depth[r.start]) return depth[l.start] < depth[r.start];
			return l.start > r.start;
		});

	auto pathfast = [&](int a, int b)
	{
		int lca = lc.lca(a, b);
		int nums = tree.query(tin[a]) + tree.query(tin[b]) - 2 * tree.query(tin[lca]) + tree.sum(tin[lca], tin[lca]);
		assert(nums >= 1);
		return nums == 1;
	};

	vi order;
	auto print = [&]()
	{
		rep(i, tree.tree.size() - 1) cout << tree.sum(i, i) << " ";
		cout << "\n";
	};
	//print();
	int k = 0;
	int its = 0;
	while (squirrels.size())
	{
		bool any = 0;
		its++;
		vector<squirrel> newsquirrels;
		repe(s, squirrels)
		{
			k++;
			if (pathfast(s.start, s.goal))
			{
				order.push_back(s.index);
				tree.update(tin[s.start], -1);
				//print();
				tree.update(tout[s.start], 1);
				//print();
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
		cerr << "k:" << k << ", its:" << its << "\n";
		return 0;
	}

	cout << "No\n";

	return 0;
}
