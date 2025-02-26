#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;

/*
    Fermat's Little Theorem : 
        a^p = a mod p 
    =>  a^(p-1) = 1 mod p
*/

long long binexp(long long a, long long b, long long m) {
    long long res = 1;
    while(b > 0) {
        if(b & 1) res = (res*a)%m;
        a = (a*a)%m;
        b /= 2;
    }
    return res;
}