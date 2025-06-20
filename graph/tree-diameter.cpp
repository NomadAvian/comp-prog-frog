#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int nax = 1e5 + 5;

// Method 1:
// Basic tree diameter

vector<int> adj[nax];
vector<ll> dist(nax);

void dfs_basic(int a, int p) {
    for(int b : adj[a]) {
        if(b == p) continue;
        dist[b] = dist[a] + 1;
        dfs_basic(b, a);
    }
}

void tree_diameter() {
    dfs_basic(1, -1);
    int u = 0;
    for(int i = 0; i < nax; ++i) {
        if(dist[i] > dist[u]) u = i;
    }
    dfs_basic(u, -1);
}

// Method 2:
// Maximum height diameter: find diameter of subtrees

// Method 3:
// ---