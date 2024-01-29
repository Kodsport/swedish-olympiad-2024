#include <bits/stdc++.h>
#include "validator.h"


using namespace std;

int MAXN = int(2e5);
int MAXQ = int(2e5);
int MAXC = int(1e9);
void run() {
	int n = Int(1, Arg("maxn", MAXN));
	Space();
	int q = Int(1, Arg("maxq", MAXQ));
	Space();
	int c = Int(1, Arg("maxc", MAXC));
	Endl();

	vector<int> profits = SpacedInts(n, 1, c);
	vector<int> costs = SpacedInts(n, 1, c);

	vector<int> queries = SpacedInts(q, 1, n);

	Eof();
}
