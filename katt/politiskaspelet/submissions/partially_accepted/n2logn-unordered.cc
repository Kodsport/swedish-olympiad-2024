#include <bits/stdc++.h>  // score: 30
using namespace std;

typedef long long ll;
#define int ll

vector<int> a, pa;
unordered_map<uint64_t, bool> can_memo;
unordered_map<uint64_t, int> memo;

uint64_t key(uint32_t l, uint32_t r) {
    return ((static_cast<uint64_t>(l) << 32) | r);
}

long long sum(int l, int r) {
    return pa[r] - pa[l];
}

bool can(int l, int r) {
    if (l + 1 == r)
        return true;
    if (auto it = can_memo.find(key(l, r)); it != can_memo.end())
        return it->second;
    int midsum = pa[l] + sum(l, r) / 2;
    int m = prev(upper_bound(pa.begin() + l + 1, pa.begin() + r + 1, midsum)) - pa.begin();
    assert(2 * sum(l, m) <= sum(l, r));
    assert(2 * sum(l, m + 1) > sum(l, r));
    bool ans = sum(l, m) == sum(m, r) && can(l, m) && can(m, r);
    return can_memo[key(l, r)] = ans;
}

int rec(int l, int r) {
    if (r + 1 == r) return 1;
    auto& best = memo[key(l, r)];
    if (!best) {
        best = r - l;
        if (can(l, r))
            best = 1;
        else
            for (int m = l; m < r; ++m)
                if (can(m, r))
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
    cout << rec(0, n) << '\n';
}
