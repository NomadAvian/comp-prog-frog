#include<bits/stdc++.h>
using namespace std;


int32_t main() {
    
    int n, w;
    cin >> n >> w;

    vector<int64_t> c(n), v(n);
    for(int i = 0; i < n; ++i) cin >> c[i] >> v[i];

    const int lim = 1e5;
    vector<int64_t> dp(lim+1, INT64_MAX);
    dp[0] = 0;

    for(int item = 0; item < n; ++item) {
        for(int val = lim; val >= v[item]; --val) {
            if(dp[val - v[item]] == INT64_MAX) continue;

            if(dp[val - v[item]] + c[item] <= w)
                dp[val] = min(dp[val], dp[val - v[item]] + c[item]);
        }
    }

    int res = lim;
    while(dp[res] == INT64_MAX) res--;

    cout << res;
    
    return 0;
}