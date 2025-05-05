#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int dp[101][100005];
int a[101], temp[100005];

int32_t main() {

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; ++i) cin >> a[i];

    dp[0][0] = 1;
    for(int i = 1; i <= k; ++i) dp[0][i] = 0;
    
    for(int i = 1; i <= n; ++i) {
        temp[0] = dp[i-1][0];
        for(int t = 1; t <= k; ++t) temp[t] = (temp[t-1] + dp[i-1][t]) % MOD;

        for(int j = 0; j <= k; ++j) {
            int tot = temp[j], lb = j - a[i] - 1;
            if(lb >= 0) {
                tot = (tot - temp[lb] + MOD) % MOD;
            }
            dp[i][j] = tot;
        }
    }

    cout << dp[n][k];

    return 0;
}