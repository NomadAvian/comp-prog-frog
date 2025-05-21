#include<bits/stdc++.h>
using namespace std;

#define fastio {ios_base::sync_with_stdio(false); cin.tie(NULL);}
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vii = vector<int>;
using vll = vector<ll>;
const double PI = (2.0*acos(0.0));
const double ep = 1e-9;
const ll MOD = 1000000007;
const int MAXN = 1e6;
const ll INF = 1e18 + 5;
const int inf = 1e9 + 5;
bool Check(ll n, int i) { return (n>>(i-1))&1; }
int Set(ll n, int i, bool b) { return b ? n | (1LL<<(i-1)) : n & ~(1LL<<(i-1)); }
int Flip(ll n, int i) { return n^(1LL<<(i-1)); }
ll add(ll a, ll b) { return (a+b)<0 ? (a+b)%MOD+MOD : (a+b)%MOD; }
ll mul(ll a, ll b) { return (a*b)<0 ? (a*b)%MOD+MOD : (a*b)%MOD; }
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int dir8[2][8] = {{1,-1,0,0,1,-1,1,-1},{0,0,1,-1,1,-1,-1,1}};


void solve(int tc) {



}


int32_t main() {

    fastio
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    int T = 1;
    cin >> T;

    for(int tc = 1; tc <= T; ++tc) {
        solve(tc);
    }

    return 0;
}