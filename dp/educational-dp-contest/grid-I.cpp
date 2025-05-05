#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;


int32_t main() {

    int h, w;
    cin >> h >> w;

    char g[h][w];
    vector<vector<int>> dp(h, vector<int> (w));

    for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j)
            cin >> g[i][j];
    // init
    for(int i = 0; i < h and g[i][0] != '#'; ++i)
        dp[i][0] = 1;
    for(int i = 0; i < w and g[0][i] != '#'; ++i)   
        dp[0][i] = 1;
    // dp
    for(int i = 1; i < h; ++i) {
        for(int j = 1; j < w; ++j) {
            if(g[i][j] == '#') 
                dp[i][j] = 0;
            else 
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }

    cout << dp[h-1][w-1];

    return 0;
}