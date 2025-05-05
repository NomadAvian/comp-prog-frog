#include<bits/stdc++.h>
using namespace std;

/*
    https://codeforces.com/gym/103886/problem/E

    partition technique to determine how many sequences have sum <= n
    number of sequences here that are palindrome must have symmetric placements of partitions

    determine jeopardized projects for [0, l-1] and [0, r] to determine answer for [l, r]
*/

const int MOD = 1e9+7;
const int MAX = 1e5+7;

vector<int64_t> dp(MAX);
void precompute() {

    vector<int64_t> po2(MAX);
    po2[1] = 1;
    dp[1] = 0;

    for(int i = 2; i < MAX; ++i) {
        po2[i] = (po2[i-1]*2) % MOD;
    }

    for(int n = 2; n < MAX; ++n) {
        // total sequences that add up to n
        int64_t tot = po2[n-1];
        // subtract all palindromic sequences of n
        dp[n] = (po2[n-1] - po2[n/2]) % MOD;

        if(dp[n] < 0) dp[n] += MOD;
    }

    // prefix sum
    for(int i = 2; i < MAX; ++i) dp[i] = (dp[i] + dp[i-1]) % MOD;
}

int32_t main() {

    precompute();

    int t;
    cin >> t;

    while(t--) {
        int l, r;
        cin >> l >> r;

        int64_t res = ((dp[r] - dp[l-1])*2) % MOD;
        
        if(res < 0) res += MOD;

        cout << res << '\n';
    }

    return 0;
}