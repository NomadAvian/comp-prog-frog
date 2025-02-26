#include<bits/stdc++.h>
using namespace std;

// time complexity : O(n + log(MOD))
// space complexity : O(n)
const long long MOD = 1e9+7;
const int maxn = 1e5;
long long fact[maxn+1];
void precompute() {
    fact[0] = fact[1] = 1;
    for(int i = 2; i <= maxn; i++) fact[i] = (fact[i-1]*i) % MOD;
}
long long binexp(long long a, long long b, long long m) {
    long long res = 1;
    while(b) {
        if(b & 1) res = (res*a)%m;
        a = (a*a)%m, b/=2;
    }
    return res;
}
long long nCr(int n, int r) { // nCr = (n!) / {(n-r)! * r!}
    long long num = fact[n], denom = (fact[n-r]*fact[r])%MOD;
    return (num * binexp(denom, MOD-2, MOD)) % MOD;
}


// time complexity : O(r * log(MIN(N,D)))
// space complexity : O(1)
long long nCr_compact(int n, int r) {
    long long N = 1, D = 1;
    r = min(r,n-r);
    while(r > 0) {
        N *= n, D *= r;
        long long g = __gcd(N,D);
        N/=g,D/=g;
        --n,--r;
    }
}