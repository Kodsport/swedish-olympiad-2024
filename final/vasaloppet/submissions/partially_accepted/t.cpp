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

	int n, t, s;
	cin >> n >> t >> s;

	vi time(t + 1);

	rep(i, n)
	{
		int l, r;
		cin >> l >> r;
		repp(i, l, r) time[i]++;
	}

	int profit = 0;
	rep(i, s) profit += time[i];
	int ans = profit;
	int p = 0;
	while (p+s<time.size())
	{
		profit += time[p + s];
		profit -= time[p];
		ans = max(ans, profit);
		p++;
	}
	
	cout << s-ans << endl;

	return 0;
}
