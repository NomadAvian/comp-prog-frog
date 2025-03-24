template<typename T> struct ST_PQRU
#define LEFT (v<<1)
#define RIGHT (v<<1|1)
#define MID ((tl+tr)>>1)
{
    int n; 
    vector<T> t;
    
    // ---
    T id = 0;
    T leaf(T node) {
        return ; 
    }
    T updateFn(T val, int v) {
        return ;
    }
    T mergeUpdate(T a, T b, int v) {
        return ;
    }
    T mergeQuery(T a, T b, int v) {
        return ;
    }
    // ---

    ST_PQRU (vector<T>& a) : n(a.size())
    { t.resize(4*n + 5, id); build(a, 1, 0, n-1); }
    void build(vector<T>& a, int v, int tl, int tr) {
        if(tl == tr) { t[v] = leaf(a[tl]); return; }
        build(a, LEFT, tl, MID), build(a, RIGHT, MID+1, tr);
        t[v] = mergeUpdate(t[LEFT],t[RIGHT], v); }
    void update(int v, int tl, int tr, int l, int r, T val) {
        if( l > r ) return;
        if(tl == l and tr == r) { t[v] = updateFn(val, v); return; } 
        update(LEFT, tl, MID, l, min(r, MID), val);
        update(RIGHT, MID+1, tr, max(l, MID+1), r, val);
        t[v] = mergeUpdate(t[LEFT], t[RIGHT], v);
    } void update(int l, int r, T val) { update(1,0,n-1,l,r,val); }
    T query(int v, int tl, int tr, int pos) {
        if(tl == tr) return t[v];
        if(pos <= MID) return mergeQuery(t[v], query(LEFT, tl, MID, pos), v);
        return mergeQuery(t[v], query(RIGHT, MID+1, tr, pos), v); 
    } T query(int pos) { return query(1,0,n-1,pos); }
};