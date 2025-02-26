#include<bits/stdc++.h>
using namespace std;

const int MAX = 2e5;

vector<int> adj[MAX+1];
vector<int> start(MAX+1), stop(MAX+1);
int timer = 0;

void euler_tour(int u, int parent) {
    start[u] = timer++;
    for(int v : adj[u]) {
        if(v != parent) euler_tour(v,u);
    }
    stop[u] = timer;
}

int main() {
    
}