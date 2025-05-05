#include<bits/stdc++.h>
using namespace std;

/*
    https://codeforces.com/gym/104520/problem/K

    calculate:
        1. viable contiguous subset
            for n -> {1,2,...,n-1,n+1, (2n-1) numbers greater than n}
        2. permutation of viable subsets
        3. permutations of remaining elements
        4. slots to insert target set
    and put them all together
*/

const int64_t MOD = 998244353;
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
int64_t nCr(int n, int r) { // nCr = (n!) / {(n-r)! * r!}
    int64_t num = fact[n], denom = (fact[n-r]*fact[r])%MOD;
    return (num * binexp(denom, MOD-2, MOD)) % MOD;
}

int32_t main() {

    precompute();

    int tc;
    cin >> tc;

    while(tc--) {
        int n;
        cin >> n;

        int lim = (n % 2 == 0) ? n/2 : n/2 + 1;

        vector<int64_t> res(n+1);
        for(int i = 2; i <= lim; ++i) {

            res[i] = nCr(n-i-1, i - 2); // 1

            res[i] = (res[i] * fact[2*(i-1)]) % MOD; // 2

            int rem = n - 2*(i-1);

            res[i] = (res[i] * fact[rem]) % MOD; // 3

            res[i] = (res[i] * (rem + 1)) % MOD; // 4
        }

        for(int i = 1; i <= n; ++i) {
            cout << res[i] << ' ';
        }

        cout << '\n';
    }

    return 0;
}