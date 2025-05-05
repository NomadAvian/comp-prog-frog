#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int add(int a, int b) {
    return (a + b) % MOD;
}

int32_t main() {

    int n;
    cin >> n;

    int match[n][n];
    vector<int> dp(1 << n);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> match[i][j];
        }
    }

    dp[0] = 1;

    for(int mask = 0; mask < (1 << n) - 1; ++mask) { // generate subset
        int a = __builtin_popcount(mask); // # paired men 
        for(int b = 0; b < n; ++b) { // pair woman 'b'
            if(match[a][b] && !(mask & (1 << b))) {
                int m2 = (mask) ^ (1 << b);
                dp[m2] = add(dp[m2], dp[mask]);
            }
        }
    }

    cout << dp[(1 << n) - 1] << '\n';

    return 0;
}