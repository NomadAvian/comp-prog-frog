#include<bits/stdc++.h>
using namespace std;

using DATA = int;
class MST {
    struct Edge {
        int u, v; DATA w;
        bool operator<(Edge const& other) 
        { return w < other.w; }
    }; set<Edge> edges;
    struct dsu {
        vector<int> p; int component;
        dsu(int n) : p(n,-1), component(n) {}
        void add() { p.push_back(-1), component++; }
        int size(int v) { return -p[find(v)]; }
        int find(int v) { return (p[v]<0) ? v : p[v]=find(p[v]); }
        bool connected(int u, int v) { return find(u) == find(v); }
        bool join(int u, int v) {
            u = find(u), v = find(v);
            if(u == v) return false;
            if(p[u]>p[v]) swap(u,v);
            p[u]+=p[v],p[v]=u,--component;
            return true;
        } 
    };
public:
    void add_edge(int u, int v, DATA w) { edges.insert({u,v,w}); }
    void clear() { edges.clear(); }
    DATA mst(int n) {
        dsu g(n);
        DATA cost = 0;
        for(Edge e : edges) {
            if(!g.join(e.u,e.v)) {
                cost += e.w;
            }
        }
        return cost;
    }
};