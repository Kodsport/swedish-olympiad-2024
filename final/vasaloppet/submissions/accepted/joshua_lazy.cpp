// slow, but obviously correct. I don't want to deal with off-by-one errors
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


struct Node
{
	Node* lchild;
	Node* rchild;
	int l, r;
	int sum;
	int lazy;

	Node(int l, int r) : lchild(nullptr), rchild(nullptr), l(l), r(r), sum(0), lazy(0) {}

	void push()
	{
		int mid = (l + r) / 2;
		if (!lchild)
		{
			lchild = new Node(l, mid);
			rchild = new Node(mid + 1, r);
		}
		lchild->sum = lchild->sum + lazy * (mid - l + 1);
		lchild->lazy = lchild->lazy + lazy;

		rchild->sum = rchild->sum + lazy * (r - (mid + 1) + 1);
		rchild->lazy = rchild->lazy + lazy;
		lazy = 0;
	}

	void add(int ql, int qr, int v)
	{
		if (l > qr || r < ql) return;
		if (l >= ql && r <= qr)
		{
			sum = sum + v * (r - l + 1);
			lazy = lazy + v;
		}
		else
		{
			push();
			lchild->add(ql, qr, v);
			rchild->add(ql, qr, v);
			sum = rchild->sum + lchild->sum;
		}
	}

	int query(int ql, int qr)
	{
		if (l > qr || r < ql) return 0;
		if (l >= ql && r <= qr) return sum;
		else
		{
			push();
			return lchild->query(ql, qr) + rchild->query(ql, qr);
		}
	}
};

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	Node* root = new Node(0, int(1e9 + 10));

	int n, t, s;
	cin >> n >> t >> s;

	vi leftp;
	rep(i, n)
	{
		int l, r;
		cin >> l >> r;
		leftp.push_back(l);
		root->add(l, r-1, 1); // add 1 to [l,r]
	}

	int ans = 0;
	rep(i, n)
	{
		int u = leftp[i];
		if (u > t) continue;
		ans = max(ans, root->query(u, u + s - 1)); // query [u,u+s-1]
	}
	cout << s-ans << endl;
	_Exit(0); // leaky leaky

	//return 0;
}
