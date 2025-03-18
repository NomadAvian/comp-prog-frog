#include<bits/stdc++.h>
using namespace std;

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
