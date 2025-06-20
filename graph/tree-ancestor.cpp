#include<bits/stdc++.h>
using namespace std;

const int nax = 2e5 + 5;

vector<int> tree[nax];
vector<int> depth(nax);
int anc[nax][20];

// O(nlog n)
void build(int u, int p) {
    for(int i = 0; i < 20; ++i)
        anc[u][i] = -1;
    if(p != -1) {
        anc[u][0] = p;
        for(int i = 1; i < 20; ++i) {
            int v = anc[u][i-1];
            if(v == -1) break;
            anc[u][i] = anc[v][i-1];
        }
    }
    for(auto v : tree[u]){
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        build(v, u);
    }
}
// O(log n)
int kth_ancestor(int u, int k) {
    for(int i = 0; i < 20; ++i) {
        if((k & (1<<i)) != 0) {
            u = anc[u][i];
            if(u == -1) return -1;
        }
    }
    return u;
}

// O(log n)
int LCA(int u, int v) {
    if(depth[u] > depth[v]) {
        u = kth_ancestor(u, depth[u] - depth[v]);
    } else if(depth[u] < depth[v]) {
        v = kth_ancestor(v, depth[v] - depth[u]);
    }
    if(u == v) return u;

    for(int i = 19; i >= 0; --i) {
        if(anc[u][i] == anc[v][i]) continue;
        u = anc[u][i];
        v = anc[v][i];
    }
    return anc[u][0];
}

int32_t main() {

    int n, q;
    cin >> n >> q;

    int boss;
    for(int i = 2; i <= n; ++i) {
        cin >> boss;
        tree[boss].push_back(i);
    }

    build(1, -1);

    int u, v;
    while(q--) {
        cin >> u >> v;
        cout << LCA(u, v) << endl;
    }

    return 0;
}