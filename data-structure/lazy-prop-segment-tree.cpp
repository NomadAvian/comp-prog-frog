#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define LEFT (v<<1)
#define RIGHT (v<<1|1)
#define MID ((tr+tl)>>1)

const int nax = 1e5 + 10;

ll arr[nax], t[4*nax], lazy[4*nax];

void build(int v, int tl, int tr) {
    lazy[v] = 0;
    if(tl == tr) {
        t[v] = 0;
    } else {
        build(LEFT, tl, MID);
        build(RIGHT, MID+1, tr);
        t[v] = t[LEFT] + t[RIGHT];
    }
}

void propagate(int v, int tl, int tr) {
    t[v] += (tr - tl + 1) * lazy[v];
    if(tl != tr) {
        lazy[LEFT] += lazy[v];
        lazy[RIGHT] += lazy[v];
    }
    lazy[v] = 0;
}

ll query(int v, int tl, int tr, int l, int r) {
    propagate(v, tl, tr);
    if(l > tr or r < tl) return 0;
    if(l <= tl and tr <= r) return t[v];
    ll p = query(LEFT, tl, MID, l, r);
    ll q = query(RIGHT, MID+1, tr, l, r);
    return p + q;
}

void update(int v, int tl, int tr, int l, int r, ll val) {
    propagate(v, tl, tr);
    if(l > tr or r < tl) return;
    if(l <= tl and tr <= r) {
        lazy[v] += val;
        propagate(v, tl, tr);
        return;
    }
    update(LEFT, tl, MID, l, r, val);
    update(RIGHT, MID+1, tr, l, r, val);
    t[v] = t[LEFT] + t[RIGHT];
}

// driver
int32_t main() {

    int n, m;
    cin >> n >> m;

    build(1, 0, n-1);
    
    int type, l, r, val;
    while(m--) {
        cin >> type;

        if(type == 1) {
            cin >> l >> r >> val;
            --r;
            update(1,0,n-1,l,r,val);
        } else {
            cin >> l >> r;
            --r;
            cout << query(1,0,n-1,l,r) << endl;
        }
    }

    return 0;
}