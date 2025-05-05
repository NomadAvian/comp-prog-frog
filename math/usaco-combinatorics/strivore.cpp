#include<bits/stdc++.h>
using namespace std;

/*
    https://atcoder.jp/contests/abc171/tasks/abc171_f

    the exact letters in the given string are irrelevant
    calculate number of string where there are
    i = 0,1,2,...,k repetitions of the letters in the given string
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

// ncr
int64_t nCr(int n, int r) { // nCr = (n!) / {(n-r)! * r!}
    int64_t num = fact[n], denom = (fact[n-r]*fact[r])%MOD;
    return (num * binexp(denom, MOD-2, MOD)) % MOD;
}

int32_t main() {

    precompute();

    int k;
    string s;

    cin >> k >> s;

    int n = s.size();

    int64_t res = 0;

    // calculate number of string where there are
    // i = 0,1,2,...,k repetitions of the letters in the given string
    for(int i = n; i <= k+n; ++i) {
        res += (nCr(n + k, i) * binexp(25, n + k - i, MOD));
        res %= MOD;
    }

    cout << res;

    return 0;
}