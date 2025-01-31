#include<bits/stdc++.h>
using namespace std;

/*
    The following implementation of BFS calculates the minimum distance from node 'a' to node 'b' 
    in an adjacency list representation of a graph.
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

// driver code
int main() {

    int n = 6; // Number of nodes
    vector<int> adj[n + 1]; // Adjacency list (1-based index)

    // Constructing the graph
    adj[1] = {2, 3};
    adj[2] = {1, 4, 5};
    adj[3] = {1, 5};
    adj[4] = {2, 6};
    adj[5] = {2, 3, 6};
    adj[6] = {4, 5};

    int a = 1, b = 6;
    int min_distance = BFS(adj, n, a, b);

    if (min_distance == -1)
        cout << "No path exists from " << a << " to " << b << endl;
    else
        cout << "Minimum distance from " << a << " to " << b << " is " << min_distance << endl;

    return 0;
}