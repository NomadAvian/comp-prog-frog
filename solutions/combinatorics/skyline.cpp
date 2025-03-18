#include<bits/stdc++.h>
using namespace std;

/*
    https://www.spoj.com/problems/SKYLINE/

    xth catalan number
*/

// tricky mod
const int MOD = 1e6;

vector<int> prime;
void sieve(int limit) {
    vector<bool> mark(limit+1, true);

    for(int p = 3; p*p <= limit; p+=2) {
        if(mark[p])
            for(int i = p*p; i <= limit; i+=p+p)
                mark[i] = false;
    }

    prime.push_back(2);
    for(int p = 3; p <= limit; p+=2)
        if(mark[p]) prime.push_back(p);
}

map<int64_t, int> factorialFactorize(int64_t n) {
    map<int64_t, int> res;
    for(int p : prime) {
        if(p > n) break;
        int64_t temp = n / p;
        while(temp) res[p] += temp, temp /= p;
    }
    return res;
}

map<int64_t,int> factorize(int64_t n) {
    map<int64_t,int> res;
    for(int p : prime) {
        if((int64_t)p*p > n) break;

        int exp = 0;
        while(n%p==0) n/=p,exp++;
        if(exp) res[p] = exp;
    }
    if(n>1) res[n]++;
    return res;
}

int64_t binexp(int64_t a, int64_t b, int64_t m) {
    int64_t res = 1;
    while(b > 0) {
        if(b & 1) res = (res*a)%m;
        a = (a*a)%m;
        b /= 2;
    }
    return res;
}


int32_t main() {

    sieve(1e6);

    int n;
    while(cin >> n) {

        if(n == 0) break;

        // calculate nth catalan number
        map<int64_t,int> num = factorialFactorize(2*n);
        map<int64_t,int> denom = factorialFactorize(n);
        map<int64_t,int> div = factorize(n+1);

        int64_t res = 1;
        for(auto [p, e] : num) {
            e -= (2*denom[p]+div[p]);
            res = (res * binexp(p, e, MOD)) % MOD;
        }

        cout << res << '\n';
    }

    return 0;
}