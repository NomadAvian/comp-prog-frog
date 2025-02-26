#include<bits/stdc++.h>
using namespace std;

/*
    Articulation Point : Tarjan's Algorithm
    Find out if the deleting of nodes create a new component in the graph
    time complexity : O(v + e)
*/

const int MAX_SIZE = 1e5; 

vector<int> adj[MAX_SIZE+1]; // Adjacency list (1-based index)
vector<int> disc(MAX_SIZE+1), low(MAX_SIZE+1);
vector<bool> ap(MAX_SIZE+1);
int Time;

int artPointDFS(int u, int parent) {
    int children = 0;
    
    low[u] = disc[u] = ++Time;

    for(int& v : adj[u]) {
        if(v == parent) continue;

        if(!disc[v]) {
            children++;
            artPointDFS(v, u);

            if(disc[u] <= low[v]) ap[u] = true;

            low[u] = min(low[u], low[v]); // low[v] might be an ancestor of u
        } else { // if v has been discovered = we found an ancestor
            low[u] = min(low[u], disc[v]);
        }
    }
    return children;
}

void AP(int sz) {
    Time = 0;
    for(int u = 1; u <= sz; u++) {
        if(!disc[u]) // check if root node has more than 1 disconnected child subgraphs
            ap[u] = artPointDFS(u, u) > 1;
    }
}

// driver code
int main() {

    // construct the graph
    int sz = 8;
    adj[1] = {2,3};
    adj[2] = {1,3,4};
    adj[3] = {1,2};
    adj[4] = {2,6,5};
    adj[5] = {4};
    adj[6] = {4,7,8};
    adj[7] = {6};
    adj[8] = {6};

    AP(sz);

    for(int i = 1; i <= sz; i++) {
        if(ap[i]) cout << i << " ";
    }

    return 0;
}

/*
    1
   / \
  2---3
  |  
  4
 / \
5   6---8
     \
      7

*/