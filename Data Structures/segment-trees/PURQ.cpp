template<typename T> struct ST_PURQ
#define LEFT (v<<1)
#define RIGHT (v<<1|1)
#define MID ((tl+tr)>>1)
{
    int n; 
    vector<T> t;


    // ---
    T id = 0;
    T leaf(T node) {
        return node;
    }
    T updateFn(T val, int v) {
        return val;
    }
    T mergeUpdate(T a, T b) {
        return a + b;
    }
    T mergeQuery(T a, T b) {
        return mergeUpdate(a,b);
    }
    // ---

    ST_PURQ (vector<T>& a) : n(a.size())
    { t.resize(4*n + 5, id); build(a, 1, 0, n-1); }
    void build(vector<T>& a, int v, int tl, int tr) {
        if(tl == tr) { t[v] = leaf(a[tl]); return; }
        build(a, LEFT, tl, MID), build(a, RIGHT, MID+1, tr);
        t[v] = mergeUpdate(t[LEFT],t[RIGHT]); }
    void update(int v, int tl, int tr, int pos, T val) {
        if(tl == tr) { t[v] = updateFn(val, v); return; }
        if(pos <= MID) update(LEFT, tl, MID, pos, val);
        else update(RIGHT, MID+1, tr, pos, val);
        t[v] = mergeQuery(t[LEFT], t[RIGHT]); 
    } void update(int pos, T val) { update(1,0,n-1,pos,val); }
    T query(int v, int l, int r, int tl, int tr) {
        if( l > r ) return id;
        if(tl == l and tr == r) return t[v];
        return mergeQuery( query(LEFT, l, min(r, MID), tl, MID),
                           query(RIGHT, max(l, MID+1), r, MID+1, tr)); 
    } T query(int l, int r) { return query(1,l,r,0,n-1); }
};