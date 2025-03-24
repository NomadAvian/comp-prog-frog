#include<bits/stdc++.h>
using namespace std;


int32_t main() {
    
    string s, t;
    cin >> s >> t;

    int a = s.size(), b = t.size();

    vector<vector<int>> dp(a + 1, vector<int> (b + 1));

    for(int i = 1; i <= a; ++i) {
        for(int j = 1; j <= b; ++j) {
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string res;

    // backtrack
    int i = a, j = b;
    while(i > 0 and j > 0) {
        if(s[i-1] == t[j-1]) {
            res += s[i-1];
            --i, --j;
        } else {
            if(dp[i-1][j] > dp[i][j-1])
                --i;
            else
                --j;
        }
    }

    reverse(res.begin(),res.end());

    cout << res;

    return 0;
}