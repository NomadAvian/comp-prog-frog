#include<bits/stdc++.h>
using namespace std;

/*
    https://cses.fi/problemset/task/2064

    kth catalan number, where 2k = n
*/

const int64_t MOD = 1e9+7;
const int maxn = 2e6+7;
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
    int64_t num = fact[n], denom = (fact[n-r]*fact[r])%MOD;
    return (num * binexp(denom, MOD-2, MOD)) % MOD;
}

int32_t main() {

    precompute();

    int n;
    cin >> n;

    if(n % 2 == 1) {
        cout << 0;
        return 0;
    }

    n /= 2;

    int64_t res = nCr(2*n, n) - nCr(2*n, n - 1);
    if(res < 0) res += MOD;

    cout << res;

    return 0;
}