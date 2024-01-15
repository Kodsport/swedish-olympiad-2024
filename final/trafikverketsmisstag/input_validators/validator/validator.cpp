#include "validator.h"

struct UF {
	vector<int> v;
	UF(int n) : v(n, -1) {}
	int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
	bool join(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return false;
		if (-v[a] < -v[b]) swap(a, b);
		v[a] += v[b];
		v[b] = a;
		return true;
	}
};


void run() {
	int maxn = Arg("maxn", int(1e5));
	string mode = Arg("mode","");
	int setk = Arg("k", 0);

	int n = Int(1, Arg("maxn", int(1e5)));
	Space();
	int s = Int(1, Arg("maxs", int(1e5)));
	Endl();
	
	UF uf(n);
	for (int i = 0; i < n-1; i++)
	{
		int a = Int(1,n);
		Space();
		int b = Int(1,n);
		Endl();
		a--; b--;
		assert(uf.join(a,b));
	}
	vector<int> used(n);
	for (int i = 0; i < s; i++)
	{
		int a = Int(1,n);
		Space();
		int b = Int(1,n);
		Endl();
		a--; b--;
		assert(!used[a]);
		used[a]=1;
	}
	
	Eof();
}
