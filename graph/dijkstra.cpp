#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5;
const int64_t INF = 1e18;

priority_queue<pair<int64_t, int>> Q;
vector<pair<int, int64_t>> adj[MAX+1];
bool visited[MAX+1] = {false};
int64_t dist[MAX+1] = {INF};

void dijkstra(int source) {
    dist[source] = 0;
    Q.push({0,source});
    while(!Q.empty()) {
        int a = Q.top().second; Q.pop();
        if(visited[a]) continue;
        visited[a] = true;
        for(auto node : adj[a]) {
            auto [b, w] = node;
            if(dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                Q.push({-dist[b], b});
            }
        }
    }
}