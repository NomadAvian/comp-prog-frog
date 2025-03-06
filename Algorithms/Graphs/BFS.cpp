#include<bits/stdc++.h>
using namespace std;

/*
    The following implementation of BFS calculates the minimum distance from node 'a' to node 'b' 
    in an adjacency list representation of a graph.
    time complexity : O(v + e)
*/

int BFS(vector<int>* adj, int n, int a, int b) {
    
    vector<bool> visited(n+1, 0); visited[a] = true;
    vector<int> distance(n+1, INT32_MAX); distance[a] = 0;
    queue<int> Q; Q.push(a);
    
    while(!Q.empty()) {
        int s = Q.front(); Q.pop();

        for(auto v : adj[s]) {
            if(visited[v]) continue;

            visited[v] = true;
            distance[v] = distance[s] + 1;
            Q.push(v);
        }
    }

    return (distance[b] == INT32_MAX) ? -1 : distance[b];
}