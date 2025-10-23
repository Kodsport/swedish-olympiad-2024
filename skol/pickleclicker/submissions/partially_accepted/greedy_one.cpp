#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using p2 = pair<ll, ll>;
const ll inf = 1e18;

#define rep(i,n) for (ll i = 0; i < (n); i++)
#define repp(i,a,n) for (ll i = (a); i < (n); i++)
#define repe(i, arr) for (auto& i : arr)
#define all(x) begin(x),end(x)
#define sz(x) ((ll)(x).size())


int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n,t,p,c;
    cin >> n >> t >> p >> c;

    ll ans = inf;
    
    rep(numbuildings, 2000) // worst case ~sqrt(t)
    {
        int moneys = 0;
        int houses = 1;
        ll days = 0;
        int left = numbuildings;
        while (moneys<t)
        {
            days++;
            moneys += houses * p;
            if (moneys>=c&&left)
            {
                left--;
                moneys -= c;
                houses++;
            }
        }
        ans = min(ans, days);
    }

    cout << ans << endl;

    return 0;
}
