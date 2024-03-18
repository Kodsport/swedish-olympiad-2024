#include <bits/stdc++.h>  // score: 100
using namespace std;

vector<int> a;
vector<vector<int>> jumpbacks;
map<pair<int, int>, int> memo;

void precompute_can() {
  jumpbacks.resize(a.size()+1);
  struct state {
    vector<int> l, r;
    void add(int ll, int rr) { l.push_back(ll); r.push_back(rr); }
    void precompute() { sort(l.begin(), l.end()); sort(r.begin(), r.end()); }
  };
  map<int, state> sums;
  for (size_t i=0; i < a.size(); ++i) {
    sums[a[i]].add(i, i+1);
  }
  while (!sums.empty()) {
    auto& [xsum, s] = *sums.begin();
    s.precompute();
    for (size_t i=0; i<s.l.size(); ++i) {
      jumpbacks[s.r[i]].push_back(s.l[i]);
    }

    for (size_t i=0, j=0; i<s.l.size() && j<s.r.size(); ) {
      if (s.l[i] < s.r[j]) {
        ++i;
      } else if (s.l[i] > s.r[j]) {
        ++j;
      } else {
        assert(i > j);
        assert(s.l[i] == s.r[j]);
        int l = s.l[j];
        int m = s.l[i];
        int r = s.r[i];
        sums[xsum+1].add(l, r);
        ++i;
        ++j;
      }
    }
    sums.erase(sums.begin());
  }
}


int rec(int l, int r) {
  if (l == r) return 0;
  if (l+1 == r) return 1;
  auto& best = memo[{l, r}];
  if (!best) {
    best = r-l;
    for (int m : jumpbacks[r])
      best = min(best, rec(l, m)+1);
  }
  return best;
}

int main() {
  int n; cin >> n;
  copy_n(istream_iterator<int>(cin), n, back_inserter(a));
  precompute_can();
  cout << rec(0, n) << '\n';
}
