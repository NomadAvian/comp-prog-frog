#include<bits/stdc++.h>
using namespace std;

/*
    The following implementation of DFS checks if two nodes a and b are connected
    time complexity : O(v + e)
*/

const int MAX = 1e5; 

vector<int> adj[MAX+1]; // Adjacency list (1-based index)
vector<bool> visited(MAX, false);

void DFS(int u) {

    if(visited[u]) return;

    visited[u] = true;
    for(auto v : adj[u]) {
        DFS(v);
    }
}