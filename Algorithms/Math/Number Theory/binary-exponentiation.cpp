#include<bits/stdc++.h>
using namespace std;


int64_t binexp(int64_t a, int64_t b, int64_t m) {
    int64_t res = 1;
    while(b > 0) {
        if(b & 1) res = (res*a)%m;
        a = (a*a)%m;
        b /= 2;
    }
    return res;
}

// fermats little theorem
int64_t modPrimeInv(int64_t a, int64_t m) {
    return binexp(a, m-2, m);
}