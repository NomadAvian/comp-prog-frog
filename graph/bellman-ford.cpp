#include<bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, cost;
};

const int nax = 1e5 + 5;
const int inf = 1e9 + 5;

vector<edge> edges;

vector<int> bellman_ford(int origin, int dest, int n) {
    vector<int> dist(n+1, inf);
    vector<int> parent(n+1, -1);
    dist[origin] = 0;
    // int x;
    // bellman-ford
    for(int i = 0; i < nax; ++i) {
        bool any = false;
        // x = -1;
        for(edge e : edges) {
            if(dist[e.u] < inf) {
                if(dist[e.v] > dist[e.u] + e.cost) {
                    dist[e.v] = dist[e.u] + e.cost;
                    parent[e.v] = e.u;
                    any = true;
                    // x = e.v;
                }
            }
            if(!any) break;
        }
    }
    // path extraction
    if(dist[dest] == inf) {
        return vector<int>();
    } else {
        vector<int> path;
        for(int cur = dest; cur != -1; cur = parent[cur]) {
            path.push_back(cur);
        }
        reverse(path.begin(),path.end());
        return path;
    }
}