#include<bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;
const int maxn = 1e6 + 3;
template<int MOD> struct modint {
    int32_t v;
    modint(int64_t val = 0) { v = int(val % MOD); if(v < 0) v += MOD; }
    modint operator+(modint b) const {return modint(v + b.v >= MOD ? v + b.v - MOD : v + b.v);}
    modint operator-(modint b) const {return modint(v - b.v < 0 ? v - b.v + MOD : v - b.v);}
    modint operator*(modint b) const {return modint(1LL*v*b.v);}
    modint& operator*=(modint b) { *this = *this * b; return *this; }
    modint expo(int64_t e) const
    { modint res(1), base(*this); while(e) { if(e&1) res*=base; base*=base, e>>=1; } return res; }
    modint inv() const { return expo(MOD - 2); } // MOD is prime
    modint operator/(modint b) const { return *this * b.inv(); }
    bool operator==(modint b) const { return v == b.v; }
    bool operator!=(modint b) const { return v != b.v; }
    bool operator<(modint b) const { return v < b.v; }
    bool operator>(modint b) const { return v > b.v; }
    bool operator<=(modint b) const { return v <= b.v; }
    bool operator>=(modint b) const { return v >= b.v; }
    friend ostream& operator<<(ostream& os, const modint& mi) { return os << mi.v; }
};
using mint = modint<mod>;

struct COMBI {
    int MAXN; vector<mint> facts, finvs, invs, subfacts;
    COMBI(int n): 
    MAXN(n), facts(n), finvs(n), invs(n), subfacts(n) {
        facts[0] = finvs[0] = 1, invs[1] = 1;
        subfacts[0] = 1, subfacts[1] = 0;
        for(int i = 2; i < MAXN; ++i)
        { invs[i] = invs[mod % i] * (-mod/i), subfacts[i] = (subfacts[i-1] + subfacts[i-2])*(i-1); }
        for(int i = 1; i < MAXN; ++i)
        { facts[i] = facts[i-1]*i, finvs[i] = finvs[i-1]*invs[i]; }
    }
    mint fact(int n) { return facts[n]; }
    mint finv(int n) { return finvs[n]; }
    mint inv(int n) { return invs[n]; }
    mint ncr(int n, int r) { return n < r or r < 0 ? 0 : facts[n] * finvs[n-r] * finvs[r]; }
    mint npr(int n, int r) { return n < r or r < 0 ? 0 : facts[n] * finvs[r]; }
    mint subfact(int n) { return subfacts[n]; }
} C(maxn);

mint lucas(int64_t n, int64_t r) {
    if( n < r ) return 0;
    if( n < mod ) return C.ncr(n,r);
    return lucas(n / mod, r / mod) * lucas(n % mod, r % mod);
}