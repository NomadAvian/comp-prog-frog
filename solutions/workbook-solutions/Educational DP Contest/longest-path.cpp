#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
vector<int> dist(MAXN);
vector<bool> vis(MAXN);

void dfs(int u, int p) {
    vis[u] = true;

    for(int v : adj[u]) {
        if(v == p) continue;

        int d = 1;
        if(vis[v]) {
            d = dist[v] + 1;
        } else {
            dfs(v, u);
            d = dist[v] + 1;
        }
        
        dist[u] = max(dist[u], d);
    }
}

int32_t main() {

    int n, m;
    cin >> n >> m;

    int u, v;
    while(m--) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i = 1; i <= n; ++i) {
        if(vis[i]) continue;

        dfs(i, i);
    }

    int res = 1;
    for(int i = 1; i <= n; ++i) res = max(res, dist[i]);

    cout << res;

    return 0;
}