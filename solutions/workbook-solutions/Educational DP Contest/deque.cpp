#include<bits/stdc++.h>
using namespace std;


int64_t a[3001];
int64_t memo[3001][3001];
bool vis[3001][3001];

int64_t dp(int lb, int ub, int turn) {
    if(lb == ub)
        return a[lb];
    if(vis[lb][ub])
        return memo[lb][ub];
    vis[lb][ub] = true;

    return memo[lb][ub] =
        max(a[lb] - dp(lb+1,ub,0), a[ub] - dp(lb,ub-1,0));
}


int32_t main() {

    int n;
    cin >> n;

    memset(vis, false, sizeof(vis));

    for(int i = 1; i <= n; ++i) cin >> a[i];

    cout << dp(1, n, 1);

    return 0;
}