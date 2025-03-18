#include<bits/stdc++.h>
using namespace std;

/*
    https://cses.fi/problemset/task/2187

    kth convolution of Catalan numbers Ck[n], 
    where k = unpaired '(' in the given prefix and
          n = total pairs of ( and )
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
    if(r > n) return 0;
    int64_t num = fact[n], denom = (fact[n-r]*fact[r])%MOD;
    return (num * binexp(denom, MOD-2, MOD)) % MOD;
}

int32_t main() {

    precompute();

    int n;
    string s;

    cin >> n >> s;

    bool invalid = false;

    int x = 0, y = 0;
    for(char c : s) {
        if(c == '(') x++;
        else y++;

        if(y > x) invalid = true;
    }

    if(invalid or (x > n/2) or (n%2)) {
        cout << 0;
        return 0;
    }

    n/=2;
    n -= x;
    int k = (x-y);

    // kth convolution of Catalan numbers
    // C^{k}_{i} = {k+1/n+k+1} * (2n+k)C(n)
    int64_t res = (nCr(2*n + k, n) * (k+1)) % MOD;
    res = (res * binexp(n+k+1,MOD-2,MOD)) % MOD;

    cout << res;

    return 0;
}