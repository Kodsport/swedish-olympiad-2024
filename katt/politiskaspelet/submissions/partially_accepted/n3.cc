#include <bits/stdc++.h>  // score: 20
using namespace std;

typedef long long ll;
#define int ll

vector<int> a, pa;
map<pair<int, int>, int> memo;

long long sum(int l, int r) {
    return pa[r] - pa[l];
}

int rec(int l, int r) {
    auto& best = memo[{l, r}];
    if (!best) {
        best = r - l;
        for (int m = l + 1; m < r; ++m) {
            int a = rec(l, m);
            int b = rec(m, r);
            if (sum(l, m) == sum(m, r) && a == 1 && b == 1)
                best = 1;
            else
                best = min(best, a + b);
        }
    }
    return best;
}

signed main() {
    int n; cin >> n;
    copy_n(istream_iterator<int>(cin), n, back_inserter(a));
    for (int& x : a) x = 1 << x;
    pa.resize(n + 1);
    partial_sum(a.begin(), a.end(), pa.begin() + 1);
    cout << rec(0, n) << '\n';
    return 0;
}
