#include<bits/stdc++.h>
using namespace std;

/*
    https://codeforces.com/problemset/problem/888/D

    determine ways to:
        1. place k = 1, 2, 3, ... numbers in ways such that p[i] != i, and
        2. place n-k numbers in a way such that p[i] = i
*/

int32_t main() {

    int n, k;
    cin >> n >> k;

    vector<int64_t> subfactorial(k+1);
    subfactorial[0] = 1, subfactorial[1] = 0;

    for(int i = 2; i <= k; ++i) {
        subfactorial[i] = (i-1) * ((subfactorial[i-1] + subfactorial[i-2]));
    }

    function<int64_t(int,int)> nCr = [&](int n, int r) -> int64_t {
        vector<int64_t> ncr(n+1);
        ncr[0] = 1, ncr[1] = n;
        r = min(r, n-r);
        for(int i = 2; i <= r; ++i) {
            ncr[i] = (ncr[i-1] * (n-i+1))/i;
        }
        return ncr[r];
    };

    int64_t res = 0;
    for(int i = 0; i <= k; ++i) {
        res += nCr(n,n-i)*subfactorial[i];
    }

    cout << res;

    return 0;
}