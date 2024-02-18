#include "validator.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
  int n;
  vector<int> p;
  UF(int n) :n(n) {
    p.resize(n);
    rep(i,0,n) p[i] = i;
  }
  int P(int x) {return (x == p[x]) ? x : p[x] = P(p[x]);}
  void join(int a, int b) {
    a = P(a); b = P(b);
    p[b] = a;
  }
  bool all_same() {
    rep(i,1,n) if (P(i) != P(0)) return false;
    return true;
  }
};

void run() {
  int maxn = Arg("maxn");
  
  int n = Int(1, maxn); Space();
  int k = Int(1, n); Endl();

  UF uf(n);
  rep(i,0,n-1) {
    int a = Int(1, n); Space();
    int b = Int(1, n); Endl();
    a--; b--;
    assert(a != b);
    uf.join(a, b);
  }

  assert(uf.all_same());

  set<int> rats;
  rep(i,0,k) {
    int r = Int(1,n);
    if (i < k-1) Space();
    else Endl();
    rats.insert(r);
  }
  assert(rats.size() == k);

  set<int> target;
  bool differs = false;
  rep(i,0,k) {
    int r = Int(1, n);
    if (i < k-1) Space();
    else Endl();
    target.insert(r);
    if (rats.find(r) == rats.end()) differs = true;
  }
  assert(differs);
  assert(target.size() == k);

  Eof();
}

