#include<bits/stdc++.h>
using namespace std;


int32_t main() {
    
    int n, w;
    cin >> n >> w;

    vector<int64_t> c(n), v(n);
    for(int i = 0; i < n; ++i) cin >> c[i] >> v[i];

    vector<int64_t> dp(w + 1);

    for(int i = 0; i < n; ++i) {
        for(int j = w; j >= c[i]; --j) {
            dp[j] = max(dp[j], dp[j - c[i]] + v[i]);
        }
    }

    cout << dp[w];
    
    return 0;
}