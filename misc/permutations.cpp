#include<bits/stdc++.h>
using namespace std;

// linear time algorithm for counting parity of permutation cycles
// construct the permutation as a composition of 3-cycles
// credit : https://codeforces.com/blog/entry/97849
bool parity(const vector<int>& p) {
    int n = p.size();
    if(n == 1) return false;
    vector<int> cur(n), inv_cur(n);
    iota(cur.begin(), cur.end(), 0);
    iota(inv_cur.begin(), inv_cur.end(), 0);
    auto three_cycle = [&](int i, int j, int k) {
        swap(cur[i], cur[k]);
        swap(cur[j], cur[k]);

        inv_cur[cur[i]] = i;
        inv_cur[cur[j]] = j;
        inv_cur[cur[k]] = k;
    };
    for(int i = 0; i < n-2; ++i) {
        if(cur[i] == p[i])
            continue;
        int j = inv_cur[p[i]];
        if(j == n-1) {
            three_cycle(n-2, j, i);
        } else {
            three_cycle(n-1, j, i);
        }
    }
    return cur[n-1] != p[n-1];
}

// linear time decomposition into cycles (1-indexed)
vector<vector<int>> decompose(const vector<int>& p) {
    int n = p.size();
    vector<vector<int>> cycles;
    vector<bool> vis(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            vector<int> v;
            while(!vis[i]) {
                v.push_back(i);
                vis[i] = 1;
                i = p[i-1];
            }
            cycles.push_back(v);
        }
    }
    return cycles;
}

// restore the permuation from the cycles
vector<int> restore(int n, vector<vector<int>>& cycles) {
    vector<int> p(n);
    for(auto v : cycles) {
        int m = v.size();
        for(int i = 0; i < m; ++i)
            p[v[i]-1] = v[(i+1) % m];
    }
    return p;
}

// O(nlogn) time algorithm for counting inversions in a permutation
// using merge sort segment tree