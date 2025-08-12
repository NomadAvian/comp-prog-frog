#include<bits/stdc++.h>
using namespace std;

const int nax = 1e5 + 5;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> roots;

void dfs(int v, vector<vector<int>>& adj, vector<int>& output) {
    vis[v] = true;
    for(int u : adj[v])
        if(!vis[u])
            dfs(u, adj, output);
    output.push_back(v);
}

void scc(vector<vector<int>>& components, vector<vector<int>>& adj_cond) {
    int n = adj.size();
    components.clear(), adj_cond.clear();

    vector<int> order;
    vis.assign(n, false);
    for(int u = 0; u < n; ++u)
        if(!vis[u]) dfs(u, adj, order);
    
    vector<vector<int>> adj_T(n, vector<int>());
    for(int u = 0; u < n; ++u)
        for(int v : adj[u]) adj_T[v].push_back(u);
    
    vis.assign(n, false);
    reverse(order.begin(), order.end());

    for(auto v : order) {
        if(!vis[v]) {
            vector<int> component;
            dfs(v, adj_T, component);
            components.push_back(component);
            int root = *min_element(component.begin(), component.end());
            for(auto u : component)
                roots[u] = root;
        }
    }

    adj_cond.assign(n, {});
    for(int v = 0 ; v < n; ++v) {
        for(auto u : adj[v])
            if(roots[v] != roots[u])
                adj_cond[roots[v]].push_back(roots[u]);
    }
}

int32_t main() {

    int n, m;
    cin >> n >> m;

    adj.assign(n, {});
    roots.assign(n, 0);

    int u, v;
    while(m--) {
        cin >> u >> v;
        adj[--u].push_back(--v);
    }

    vector<vector<int>> components, adj_cond;

    scc(components, adj_cond);

    if(components.size() == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
        
        int a = roots[components[0][0]];
        int b = roots[components[1][0]];

        vector<bool> visited(n, false);
        function<void(int)> check = [&](int u) {
            vis[u] = true;
            for(int v : adj_cond[u]) {
                check(v);
            }
        };

        check(a);

        if(!visited[b]) {
            cout << ++b << ' ' << ++a;
        } else {
            cout << ++a << ' ' << ++b;
        }
    }

    cout << endl;

    return 0;
}