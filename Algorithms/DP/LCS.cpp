#include<bits/stdc++.h>
using namespace std;

// time complexity : O(n^2)
// space complexity : O(n^2)
int LCS(string& a, string& b) {
    int sza = a.size(),  szb = b.size();
    vector<vector<int>> dp(sza+1, vector<int> (szb+1, 0));
    
    for(int i = 1; i <= sza; i++) {
        for(int j = 1; j <= szb; j++) {
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[sza][szb];
}
