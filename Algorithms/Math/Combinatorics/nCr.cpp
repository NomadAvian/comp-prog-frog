#include<bits/stdc++.h>
using namespace std;

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

// driver code
int main() {

    precompute();

    cout << "6C4 = " << nCr(6,4) << '\n';
    cout << "12C4 = " << nCr(12,4) << '\n';
    cout << "122C54 = " << nCr(122,54) << '\n';

    return 0;
}