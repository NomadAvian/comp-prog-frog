#include<bits/stdc++.h>
using namespace std;

/*
    Generate an ordering from a Directed Acyclic Graph (DAG)
*/

const int nax = 1e5+1;
vector<int> adj[nax];
bool vis[nax];
vector<int> seq;

vector<int> toposort(int n) {
    vector<int> inDeg(n, 0);
    for(int u = 1; u <= n; ++u) {
        for(auto v : adj[u]) {
            inDeg[v]++;
        }
    }
    queue<int> Q;
    for(int i = 1; i <= n; ++i) {
        if(inDeg[i] == 0) {
            Q.push(i);
        }
    }
    vector<int> order;
    while(!Q.empty()) {
        int u = Q.top();
        Q.pop();

        order.push_back(u);

        for(int v : adj[u]) {
            inDeg[v]--;
            if(inDeg[v] == 0) {
                Q.push(v);
            }
        }
    }
    if(order.size() < n) return vector<int>();
    reverse(order.begin(), order.end());
    else return order;
}

void dfs(int u) {
    vis[u] = true;
    for(int v : adj[u]) {
        if(vis[v]) continue;
        dfs(v);
    }
    seq.push_back(u);
}

void topological_sort(int nodes) {
    for(int i = 1; i <= nodes; i++) {
        if(!vis[i]) dfs(i);
    }
    reverse(seq.begin(),seq.end());
}
