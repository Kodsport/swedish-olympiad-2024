#include <bits/stdc++.h>  // score: 60
using namespace std;

typedef long long ll;
#define int ll

vector<int> a, pa;
vector<vector<int>> jumpbacks;
map<pair<int, int>, int> memo;

long long sum(int l, int r) {
    return pa[r] - pa[l];
}

void precompute_can() {
    jumpbacks.resize(pa.size());
    struct state {
        vector<int> l, r;
        void add(int le, int rr) { l.push_back(le); r.push_back(rr); }
        void precompute() { sort(l.begin(), l.end()); sort(r.begin(), r.end()); }
    };
    map<int, state> sums;
    for (size_t i = 0; i < a.size(); ++i) {
        sums[a[i]].add(i, i + 1);
    }
    while (!sums.empty()) {
        auto& [xsum, s] = *sums.begin();
        s.precompute();
        for (size_t i = 0; i < s.l.size(); ++i) {
            assert(sum(s.l[i], s.r[i]) == xsum);
            jumpbacks[s.r[i]].push_back(s.l[i]);
        }

        for (size_t i = 0, j = 0; i < s.l.size() && j < s.r.size(); ) {
            if (s.l[i] < s.r[j]) {
                ++i;
            }
            else if (s.l[i] > s.r[j]) {
                ++j;
            }
            else {
                assert(i > j);
                assert(s.l[i] == s.r[j]);
                int l = s.l[j];
                int m = s.l[i];
                int r = s.r[i];
                assert(sum(l, m) == xsum);
                assert(sum(m, r) == xsum);
                sums[2 * xsum].add(l, r);
                ++i;
                ++j;
            }
        }
        sums.erase(sums.begin());
    }
}


int rec(int l, int r) {
    if (l == r) return 0;
    if (l + 1 == r) return 1;
    auto& best = memo[{l, r}];
    if (!best) {
        best = r - l;
        for (int m : jumpbacks[r])
            best = min(best, rec(l, m) + 1);
    }
    return best;
}

signed main() {
    int n; cin >> n;
    copy_n(istream_iterator<int>(cin), n, back_inserter(a));
    for (int& x : a) x = 1 << x;
    pa.resize(n + 1);
    partial_sum(a.begin(), a.end(), pa.begin() + 1);
    precompute_can();
    cout << rec(0, n) << '\n';
    return 0;
}
