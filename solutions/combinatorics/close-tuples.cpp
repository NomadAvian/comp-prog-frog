#include<bits/stdc++.h>
using namespace std;

/*
    https://codeforces.com/contest/1462/problem/E2

    sort and greedily determine for each element the number of sequences of length k 
    that satisfy the given conditions 
*/

const int64_t MOD = 1e9+7;
const int maxn = 2e5+7;
int64_t fact[maxn+1];
void precompute() {
    fact[0] = fact[1] = 1;
    for(int i = 2; i <= maxn; i++) fact[i] = (fact[i-1]*i) % MOD;
}
int64_t binexp(int64_t a, int64_t b, int64_t m) {
    int64_t res = 1;
    while(b) {
        if(b & 1) res = (res*a)%m;
        a = (a*a)%m, b/=2;
    }
    return res;
}
int64_t nCr(int n, int r) { // nCr = (n!) / {(n-r)! * r!}
    if(r > n) return 0;
    int64_t num = fact[n], denom = (fact[n-r]*fact[r])%MOD;
    return (num * binexp(denom, MOD-2, MOD)) % MOD;
}


int32_t main() {

    precompute();

    int tc;
    cin >> tc;

    while(tc--) {
        
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<int> a(n);
        for(auto& x : a) cin >> x;

        sort(a.begin(),a.end());

        int64_t res = 0;
        
        for(int i = 0; i < n; ++i) {

            int ub = upper_bound(a.begin(),a.end(),a[i]+k) - a.begin() - 1;

            res += nCr(ub - i, m - 1);
            res %= MOD;
        }

        cout << res << '\n';
    }

    return 0;
}