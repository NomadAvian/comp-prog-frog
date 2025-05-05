#include<bits/stdc++.h>
using namespace std;

/*
    https://usaco.org/index.php?page=viewproblem2&cpid=1283

    each point must be crossed a certain number of times
    in order to keep the number of direction changes minimal,
    how many ways can we pair left jumps between two consecutive points?
    if the sequence from the left cannot be determined, how about right jumps?
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

    vector<int> a(n);
    for(auto& x : a) cin >> x;

    int64_t res = 1;

    // every pair implies e LR or RL over that point
    for(int i = 0; i < n; ++i) a[i] /= 2;

    for(int i = n-2; i >= 0; --i) {
        if((a[i] <= a[i+1])) // how many ways to go left
            res *= nCr(a[i+1] - 1, a[i] - 1);
        else // how many ways to go right
            res *= nCr(a[i], a[i+1]);
        res %= MOD;
    }

    cout << res;

    return 0;
}