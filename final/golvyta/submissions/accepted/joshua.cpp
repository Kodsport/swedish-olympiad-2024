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

	int k;
	cin >> k;
	string s;
	cin >> s;
	int r, c;
	cin >> r >> c;

	vi deltax;
	vi deltay;
	repe(c, s)
	{
		if (c == '>') deltax.push_back(1);
		if (c == '<') deltax.push_back(-1);
		if (c == 'v') deltay.push_back(1);
		if (c == '^') deltay.push_back(-1);
	}

	auto eval = [](vi delta, int size)
	{
		int p = 0;
		repe(v, delta)
		{
			p += v;
			p = max(0, p);
			p = min(size, p);
		}
		return p;
	};

	auto solve = [&](vi delta, int t)
	{
		int lo = -1;
		int hi = int(5e5);
		while (lo+1<hi)
		{
			int mid = (lo + hi) / 2;
			int p = eval(delta, mid);
			if (p >= t) hi = mid;
			else lo = mid;
		}
		if (eval(delta, hi) == t) return hi;
		return -1;
	};
	int x = solve(deltax, c);
	int y = solve(deltay, r);
	if (x == -1 || y == -1) cout << "-1";
	else cout << (x+1)*(y+1);
	cout << "\n";

	return 0;
}
