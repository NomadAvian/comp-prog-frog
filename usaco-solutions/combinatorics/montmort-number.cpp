#include<bits/stdc++.h>
using namespace std;

/*
    https://judge.yosupo.jp/problem/montmort_number_mod
*/

int32_t main() {
    
    int n, m;
    cin >> n >> m;

    // calculate derangements
    vector<int64_t> subfactorial(n+1);
    subfactorial[0] = 1, subfactorial[1] = 0;

    cout << subfactorial[1];
    for(int i = 2; i <= n; ++i) {
        // derangement recursive formula
        subfactorial[i] = ((i-1) * ((subfactorial[i-1] + subfactorial[i-2]) % m)) % m;
        cout << ' ' << subfactorial[i];
    }

    return 0;
}