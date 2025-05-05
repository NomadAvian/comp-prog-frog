#include<bits/stdc++.h>
using namespace std;


int32_t main() {

    int n;
    cin >> n;

    vector<double> p(n+1);
    for(int i = 1; i <= n; ++i) cin >> p[i]; 

    double dp[n+1][n+1];

    dp[1][0] = 1.0 - p[1], dp[1][1] = p[1];

    for(int i = 2; i <= n; ++i) {
        dp[i][0] = dp[i-1][0] * (1.0 - p[i]);
        dp[i][i] = dp[i-1][i-1] * p[i];

        for(int j = 1; j < i; ++j)
            dp[i][j] = dp[i-1][j-1]*p[i] + dp[i-1][j]*(1.0 - p[i]);
    }

    double res = 0;
    for(int i = n/2 + 1; i <= n; ++i) res += dp[n][i];

    cout << fixed << setprecision(10) << res;

    return 0;
}