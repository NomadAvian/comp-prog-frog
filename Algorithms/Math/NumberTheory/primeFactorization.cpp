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

map<long long,int> factorize(long long n) {
    map<long long,int> res;
    for(int p : prime) {
        if((long long)p*p > n) break;

        int exp = 0;
        while(n%p==0) n/=p,exp++;
        if(exp) res[p] = exp;
    }
    if(n>1) res[n]++;
    return res;
}

// driver code
int main() {

    sieve(100);

    for(auto p : prime) cout << p << " ";
  
    return 0;
}
