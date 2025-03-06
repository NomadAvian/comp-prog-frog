#include<bits/stdc++.h>
using namespace std;

/*
    process range sum queries and updates efficiently
    time complexity: O(logN)
    space complexity: O(N)
*/

struct BIT {
    vector<int64_t> bit;
    int n;

    BIT(vector<int64_t>const &a) { 
        n = a.size(); bit.assign(n, 0);
        for(size_t i=0; i<bit.size(); ++i) add(i, a[i]); 
    }
    int64_t sum(int r) {
        int64_t res = 0;
        for(; r>=0; r=(r&(r+1))-1) res += bit[r];
        return res;
    }
    int64_t sum(int l, int r) { return sum(r)-(l>0 ? sum(l-1):0); }
    void add(int idx, int64_t delta) { for(; idx<n; idx|=idx+1) bit[idx]+=delta; }
};