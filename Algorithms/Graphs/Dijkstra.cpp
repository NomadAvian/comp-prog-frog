#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5;

/*
    The following implementation of Dijkstra finds the minimum distance from one node, u
    in a weighted graph to all other nodes in the graph given there are no negative edges
    time complexity : O((v + e)log v)
*/

priority_queue<pair<long long, int>> Q;
vector<pair<int, long long>> adj[MAX+1];
bool visited[MAX+1] = {false};
long long dist[MAX+1] = {LLONG_MAX};

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

// driver code
int main() {
    int n, m, source;
    cin >> n >> m >> source;  // Number of nodes, edges, and source node

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w; // Read edge (u, v) with weight w
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(source);

    // Print shortest distances
    for (int i = 1; i <= n; i++) {
        if (dist[i] == LLONG_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}