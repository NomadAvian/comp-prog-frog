#include<bits/stdc++.h>
using namespace std;

/*
    https://cses.fi/problemset/task/1716

    stars and bars technique
*/

const int MOD = 1e9 + 7;
const int maxn = 2e6+5;

long long fact[maxn+2];
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

int32_t main() {

    precompute();

    int n, m;
    cin >> n >> m;

    cout << nCr(n + m - 1, m);
    
    return 0;
}