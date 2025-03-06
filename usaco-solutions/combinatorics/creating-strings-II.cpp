#include<bits/stdc++.h>
using namespace std;

/*
    https://cses.fi/problemset/task/1715
*/

const long long MOD = 1e9+7;
const int maxn = 2e6+7;
long long fact[maxn+1];
void precompute() {
    fact[0] = fact[1] = 1;
    for(int i = 2; i <= maxn; i++) fact[i] = (fact[i-1]*i) % MOD;
}
long long binexp(long long a, long long b, long long m) {
    long long res = 1;
    while(b) {
        if(b & 1) res = (res*a)%m;
        a = (a*a)%m, b/=2;
    }
    return res;
}

int32_t main() {

    precompute();

    string s;
    cin >> s;

    vector<int> repetition(26);
    for(char c : s) {
        repetition[c-'a']++;
    }

    int n = s.size();

    // nPr
    int64_t res = fact[n];

    // adjust for repetitions
    for(size_t i = 0; i < 26; ++i) {
        if(repetition[i] > 1) {
            res *= binexp(fact[repetition[i]], MOD-2, MOD);
            res %= MOD;
        } 
    }

    cout << res;
    
    return 0;
}