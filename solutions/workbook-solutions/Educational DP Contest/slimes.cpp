#include<bits/stdc++.h>
using namespace std;


int64_t a[405];
int64_t dp[405][405];


int64_t f(int l, int r) {
    if(l == r) 
        return 0;
    if(dp[l][r]) 
        return dp[l][r];
    dp[l][r] = 1e18;
    for(int k = l; k < r; ++k) {
        dp[l][r] = min(dp[l][r], f(l, k) + f(k+1, r) + (a[r] - a[l-1]));
    }
    return dp[l][r];
}


int32_t main() {

    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i-1];
    }

    cout << f(1, n);    

    return 0;
}