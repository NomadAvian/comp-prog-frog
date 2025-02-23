#include<bits/stdc++.h>
using namespace std;

/*
    Generate an ordering from a Directed Acyclic Graph (DAG)
*/

const int N = 1e5+1;
vector<int> adj[N];
bool vis[N];
vector<int> seq;

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


// driver code
int main() {
    


    return 0;
}