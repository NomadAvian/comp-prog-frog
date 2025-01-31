#include<bits/stdc++.h>
using namespace std;

/*
    The following implementation of DFS checks if two nodes a and b are connected
*/

const int MAX_SIZE = 1e5; 

vector<int> adj[MAX_SIZE+1]; // Adjacency list (1-based index)
vector<bool> visited(MAX_SIZE, false);

void DFS(int u) {

    if(visited[u]) return;

    visited[u] = true;
    for(auto v : adj[u]) {
        DFS(v);
    }
}

// driver code
int main() {

    // Constructing the graph
    adj[1] = {2, 3};
    adj[2] = {1, 3};
    adj[3] = {1, 2, 6};
    adj[4] = {5};
    adj[5] = {4};
    adj[6] = {3, 7};
    adj[7] = {6};

    int a = 1, b = 6;
    DFS(a);

    if(visited[b]) cout << b <<  " is connected to " << a << "\n";
    else cout << b << " is not connected to " << a << "\n";

    return 0;
}