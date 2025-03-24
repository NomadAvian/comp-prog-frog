#include<bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;
const int maxn = 1e6 + 3;

struct modint {
    int32_t v; static int MOD;
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
int modint::MOD = 1e9 + 7;

struct COMBI 
#define mint modint
{
    int MAXN, mod; vector<modint> facts, finvs, invs, subfacts;
    COMBI(int n, int M): 
    MAXN(n), facts(n), finvs(n), invs(n), subfacts(n), mod(M) {
        modint::MOD = mod;
        facts[0] = finvs[0] = 1, invs[1] = 1, subfacts[0] = 1, subfacts[1] = 0;
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

    mint lucas(int64_t n, int64_t k) {
        if( n < k ) return 0;
        if( n < mod ) return ncr(n, k);
        return lucas(n / mod, k / mod) * lucas(n % mod, k % mod);
    }
};

int32_t main() {

    int t;
    cin >> t;

    while(t--) {
        int64_t N, K;
        int P;

        cin >> N >> K >> P;

        COMBI C(P+3, P);

        cout << C.lucas(N,K) << '\n';
    }

    return 0;
}