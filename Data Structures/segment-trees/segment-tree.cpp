#include<bits/stdc++.h>
using namespace std;
 
template <typename T, typename F> struct ST 
#define LEFT (v<<1)
#define RIGHT (v<<1|1)
#define MID ((tl+tr)>>1)
{
    int n;
    vector <T> t;
    T identity; 
    F merge;
 
    ST(vector<T>& a, T id, F func) : identity(id), merge(func) {
        n = a.size();
        t.resize(4*n, identity);
        build(a, 1, 0, n-1);
    }
 
    void build(vector<T>& a, int v, int tl, int tr) {
        if(tl == tr) {
            t[v] = a[tl];
        } else {
            build(a, LEFT, tl, MID);
            build(a, RIGHT, MID+1, tr);
            t[v] = merge(t[LEFT],t[RIGHT]);
        }
    }
 
    T query(int l, int r, int v = 1, int tl = 0, int tr = -1) {
        if(tr == -1) tr = n-1;
        if(l > r) 
            return identity;
        if(l == tl and r == tr) 
            return t[v];
        return merge(query(l, min(r, MID), LEFT, tl, MID),
                     query(max(l,MID+1), r, RIGHT, MID+1, tr));
    }
 
    void update(int pos, T new_val, int v = 1, int tl = 0, int tr = -1) {
        if(tr == -1) tr = n-1;
        if(tl == tr) {
            t[v] = new_val;
        } else {
            if(pos <= MID)
                update(pos, new_val, LEFT, tl, MID);
            else 
                update(pos, new_val, RIGHT, MID+1, tr);
            t[v] = merge(t[LEFT],t[RIGHT]);
        }
    }
};

int32_t main() {
 
    // init
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(auto& x : a) cin >> x;
 
    // def segment tree
    ST <int, function<int(int,int)>> st(
        a,  
        0,
        [](int x, int y) {
            return (x^y);
        } 
    );
 
    // queries
    int l, r;
    while(q--) {
        cin >> l >> r;
        cout << st.query(l-1,r-1) << '\n';
    }
 
    return 0;
}