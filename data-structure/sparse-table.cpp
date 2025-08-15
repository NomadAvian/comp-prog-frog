#include<bits/stdc++.h>
using namespace std;

const int nax = 1e5 + 5;
const int k = 30;

struct st {
    int n;
    vector<vector<int>> t;
    st(vector<int>& a, int n) : n(n) {
        t.resize(k,vector<int>(n));
        for(int i = 0; i < n; ++i)
            t[0][i] = a[i];
        for(int i = 1; i <= k; ++i)
            for(int j = 0; j < n; ++j)
                t[i][j] = min(t[i-1][j], t[i-1][j + (1<<(i-1))]);
    }
    int query(int l, int r) {
        int i = log2(r-l+1);
        int res = min(t[i][l],t[i][r-(1<<i)+1]);
        return res;
    }
};
