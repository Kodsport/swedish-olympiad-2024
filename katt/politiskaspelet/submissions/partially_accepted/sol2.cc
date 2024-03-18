// score: 100
#ifndef LOCAL
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#endif

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
#include <queue>
#include <random>
#include <ctime>
#include <chrono>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif


typedef long long int int64;
typedef long long int ll;
typedef long long unsigned ull;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
    return (ull)rng() % B;
}

#define int long long

const int N = (int)1e6 + 100;
long long a[N];

const int LOG = 33;
int _dp[N][LOG];
int n;

int goTo(int pos, int x)
{
    if (pos == -1 || pos == n)
        return -1;
    int ca = a[pos];
    //eprintf("pos = %d, x = %lld\n", pos, x);
    if (x < ca || x >= ca + LOG)
        return -1;
    if (x == ca)
        return pos + 1;

    if (_dp[pos][x - ca])
        return _dp[pos][x - ca];

    return _dp[pos][x - ca] = goTo(goTo(pos, x - 1), x - 1);
}

int dp[N];

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //	freopen("output.txt", "w", stdout);
#endif


    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        a[i] += 1;
    }

    for (int i = 1; i <= n; i++)
        dp[i] = n + 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < LOG; j++)
        {
            long long x = (a[i] + j);
            int ni = goTo(i, x);
            if (ni != -1)
                dp[ni] = min(dp[ni], dp[i] + 1);
        }
    printf("%lld\n", dp[n]);

    return 0;
}
