#include <bits/stdc++.h>  // score: 20
using namespace std;

vector<int> a;
map<pair<int, int>, int> memo;

long long sum(int l, int r) {
  return accumulate(a.begin()+l, a.begin()+r, 0LL);
}

int rec(int l, int r) {
  auto& best = memo[{l, r}];
  if (!best) {
    best = r-l;
    for (int m=l+1; m<r; ++m) {
      int a = rec(l, m);
      int b = rec(m, r);
      if (sum(l, m) == sum(m, r) && a==1 && b==1)
        best = 1;
      else
        best = min(best, a+b);
    }
  }
  return best;
}

int main() {
  int n; cin >> n;
  copy_n(istream_iterator<int>(cin), n, back_inserter(a));
  for (int& x : a) x = 1 << x;
  cout << rec(0, n) << '\n';
  return 0;
}
