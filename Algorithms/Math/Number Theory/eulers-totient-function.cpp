#include<bits/stdc++.h>
using namespace std;

/*
    phi(n) = |A|, where A is the set of numbers in range [1,n] that are coprime to n
*/

// time complexity: O(sqrt(n))
int PHI(int n) {
    int res = n;
    for(int i = 2; i*i <= n; ++i) {
        if(n % i == 0) {
            while(n % i == 0) n /= i;
            res -= res / i;
        }
    }
    if(n > 1) res -= res / n;
    return res;
}

// precompute
// time complexity: O(n log log (n))
vector<int> phi;
void totient(int n) {
    phi.resize(n + 1);
    iota(phi.begin(),phi.end(),0);

    for(int i = 2; i <= n; ++i) {
        if(phi[i] == i) {
            for(int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

/*
    formulas

    phi(p) = p-1
    phi(p^k) = p^(k) - p^(k-1)
    phi(ab) = phi(a) * phi(b) iff, gcd(a,b) = 1
    phi(ab) = phi(a) * phi(b) * d / phi(d), where d = gcd(a,b)
    a^(phi(m)) = 1 mod m if gcd(a,m) = 1
    a^n = a^(n mod phi(m)) mod m
*/