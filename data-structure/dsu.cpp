#include<bits/stdc++.h>
using namespace std;


struct dsu {
    vector<int> p;
    int component;
    dsu(int n) : p(n,-1), component(n) {}
    void add() { p.push_back(-1), component++; }
    int size(int v) { return -p[find(v)]; }
    int find(int v) { return (p[v]<0) ? v : p[v]=find(p[v]); }
    bool join(int u, int v) {
        u = find(u), v = find(v);
        if(u == v) return false;
        if(p[u]>p[v]) swap(u,v);
        p[u]+=p[v],p[v]=u,--component;
        return true;
    } 
};