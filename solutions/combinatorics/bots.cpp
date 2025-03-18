#include<bits/stdc++.h>
using namespace std;

/*
    https://dmoj.ca/problem/bbc08h

    first half of the tree is a binary tree of depth n

    in the second half, the number of nodes in each layers i is
        n = 2*(nodes in layer i-1) - 2*(length of n-i sequences with n 1's)
*/

const int64_t MOD = 1e9+7;
const int maxn = 2e6;
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

    int64_t v = binexp(2,n,MOD);

    int64_t res = (binexp(2,n+1,MOD) - 1) % MOD;

    for(int i = 0; i < n; ++i) {
        v = (2*v - 2*nCr(n+i,n)) % MOD;
        if(v < 0) v += MOD;
        res += v;
        res %= MOD;
    }

    cout << res;

    return 0;
}
