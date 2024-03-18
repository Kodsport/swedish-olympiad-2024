#include <bits/stdc++.h>  // score: 100
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> a; copy_n(istream_iterator<int>(cin), n, back_inserter(a));

  vector<vector<int>> jumpbacks(n+1);
  struct state {
    vector<int> l, r;
    void add(int ll, int rr) { l.push_back(ll); r.push_back(rr); }
  };
  map<int, state> sums;
  for (size_t i=0; i < a.size(); ++i)
    sums[a[i]].add(i, i+1);
  while (!sums.empty()) {
    auto& [xsum, s] = *sums.begin();
    sort(s.l.begin(), s.l.end());
    sort(s.r.begin(), s.r.end());
    for (size_t i=0; i<s.l.size(); ++i)
      jumpbacks[s.r[i]].push_back(s.l[i]);

    for (size_t i=0, j=0; i<s.l.size() && j<s.r.size();) {
      if (s.l[i] < s.r[j])
        ++i;
      else if (s.l[i] > s.r[j])
        ++j;
      else
        sums[xsum+1].add(s.l[j++], s.r[i++]);
    }
    sums.erase(sums.begin());
  }

  vector<int> dp(n+1);
  for (size_t r = 1; r <= a.size(); ++r) {
    int ans = r;
    for (int m : jumpbacks[r])
      ans = min(ans, dp[m]+1);
    dp[r] = ans;
  }
  cout << dp.back() << '\n';
}
