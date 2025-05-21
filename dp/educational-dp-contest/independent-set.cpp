#include<bits/stdc++.h>
using namespace std;

using ll = long long int;

const int maxn = 1e5+7;
const int mod = 1e9+7;

vector<ll> adj[maxn];
vector<pair<ll,ll>> dp(maxn);

int32_t main() {

    /*
    
        leaf nodes node[0] = 1, node[1] = 1
        non leaf nodes node[0] = product(ways to color first node of each subtree 1)
                       node[1] = product(ways to color first node of each subtree any)

    */

    int n;
    cin >> n;

    int u, v;
    for(int i = 1; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    function<void(int,int)> dfs = [&](int node, int p) -> void {
        dp[node].first = dp[node].second = 1;

        for(int child : adj[node]) {
            if(child == p) continue;

            dfs(child, node);
            dp[node].first = (dp[node].first * (dp[child].first + dp[child].second)) % mod;
            dp[node].second = (dp[node].second * dp[child].first) % mod;
        }
    };

    dfs(1,1);

    cout << (dp[1].first + dp[1].second) % mod << endl;

    return 0;
}