#include<bits/stdc++.h>
using namespace std;


class DSU {
private:

    vector<int> parent;
    vector<int> treeSize;

public:

    DSU(int n) {
        parent.resize(n+1);
        treeSize.resize(n+1, 1);
        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find_set(int v) {
        if(parent[v] == v) return v;

        return parent[v] = find_set(parent[v]);
    }

    void union_set(int u, int v) {
        int a = find_set(u);
        int b = find_set(v);

        if(a != b) {
            if(treeSize[a] < treeSize[b])
                swap(a, b);
            parent[b] = a;
            treeSize[a] += treeSize[b];
        }
    }

    bool connected(int u, int v) {
        return find_set(u) == find_set(v);
    }
};


// driver code
int main() {
    
    int n = 10;  // Number of elements
    DSU dsu(n);

    // Example operations:
    dsu.union_set(1, 2);  // Union of 1 and 2
    dsu.union_set(2, 3);  // Union of 2 and 3
    dsu.union_set(4, 5);  // Union of 4 and 5
    dsu.union_set(6, 7);  // Union of 6 and 7

    // Check if two nodes are connected
    cout << (dsu.connected(1, 3) ? "Yes" : "No") << "\n";  // Should print "Yes"
    cout << (dsu.connected(1, 4) ? "Yes" : "No") << "\n";  // Should print "No"

    // Union of different sets
    dsu.union_set(3, 4);  // Union of sets containing 3 and 4
    cout << (dsu.connected(1, 5) ? "Yes" : "No") << "\n";  // Should print "Yes"

    return 0;
}
