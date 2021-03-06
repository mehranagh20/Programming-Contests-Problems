//In The Name Of God
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, double> dd;
typedef pair<dd, double> ddd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<dd> vdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;
typedef vector<vector<viii> > vvviii;
typedef vector<vector<iii> > vviii;
typedef set<int> si;
typedef vector<si> vsi;

#define forn(i, n) for (int i = 0; i < n; i++)
#define forr(i, n) for (int i = n; i >= 0; i--)
#define all(a) (a).begin(), (a).end()
#define inf 1000000000
#define eps 1e-9
#define pi acos(-1.0)
#define F first
#define S second

int const MX = 1100, MOD = 1e9 + 7;
ll dp[MX][MX];
ll k, pa, pb;

ll pw(ll a, ll b=MOD - 2) {
    if (b == 0) {
        return 1;
    }
    ll v = pw(a, b / 2);
    v = (v * v) % MOD;
    if (b & 1) {
        v = (v * a) % MOD;
    }
    return v;
}

ll get_dp(int i, int j) {
    if(j >= k) return j;
    return dp[i][j];
}

int main() {
    ios::sync_with_stdio(0);
    cin >> k >> pa >> pb;
    ll s = pa + pb;
    ll x = (s * pw(pb)) % MOD;
    pa = (pa * pw(s)) % MOD;
    pb = (pb * pw(s)) % MOD;

    forr(i, k)
        forr(j, k) {
            if(i + j >= k) dp[i][j] = (i + j - 1 + x) % MOD;
            else dp[i][j] = (pa * get_dp(i + 1, j) + pb * get_dp(i, i + j)) % MOD;
        }

    cout << dp[1][0] << endl;

    return 0;
}
