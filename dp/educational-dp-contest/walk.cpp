#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

struct M {
    int n;
    vector<vector<int64_t>> m;
    M(int sz) : n(sz) {
        vector<vector<int64_t>> id(n, vector<int64_t>(n));
        for(int i = 0; i < n; ++i) id[i][i] = 1;
        m = id;
    }
    void set(vector<vector<int64_t>>& matrix) { m = matrix; }
    M operator*(const M& other) {
        M t(n);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) { // entry i,j in resultant
                t.m[i][j] = 0;
                for(int en = 0; en < n; ++en) {
                    t.m[i][j] += m[i][en] * other.m[en][j];
                    t.m[i][j] %= mod;
                }
            }
        }
        return t;
    }
};

M exp(M base, int64_t e) {
    M res(base.n);
    while(e) {
        if(e & 1) res = res * base;
        base = base * base;
        e>>=1;
    }
    return res;
}


int32_t main() {

    int n;
    int64_t k;

    cin >> n >> k;

    vector<vector<int64_t>> a(n, vector<int64_t>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    M m(n);
    m.set(a);

    M res = exp(m, k);

    int tot = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            tot = (tot + res.m[i][j]) % mod;
        }
    }

    cout << tot << endl;

    return 0;
}