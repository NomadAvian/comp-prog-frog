#include<bits/stdc++.h>
using namespace std;

// time complexity : O(n + log(MOD))
// space complexity : O(n)
const int64_t MOD = 1e9+7;
const int maxn = 1e5;
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

// ncr
int64_t nCr(int n, int r) { // nCr = (n!) / {(n-r)! * r!}
    int64_t num = fact[n], denom = (fact[n-r]*fact[r])%MOD;
    return (num * binexp(denom, MOD-2, MOD)) % MOD;
}

// npr
int64_t nPr(int n, int r) { // nCr = (n!) / {(n-r)! * r!}
    int64_t num = fact[n], denom = fact[n-r];
    return (num * binexp(denom, MOD-2, MOD)) % MOD;
}

// derangements
vector<int64_t> subfactorial;
void subfact(int n) {
    subfactorial.reserve(n+1);
    subfactorial[0] = 1, subfactorial[1] = 0;

    for(int i = 2; i <= n; ++i) {
        subfactorial[i] = (i-1) * ((subfactorial[i-1] + subfactorial[i-2]));
    }
}