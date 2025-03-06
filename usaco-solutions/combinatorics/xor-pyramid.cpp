#include<bits/stdc++.h>
using namespace std;

/*
    https://cses.fi/problemset/task/2419
*/

const int32_t MAX = 1e6+7;

vector<int> power_of_2(MAX);
void precompute() {
    for(int i = 1; i <= MAX; ++i) {
        int temp = i;
        while(temp % 2 == 0) temp/=2, power_of_2[i]++;
    }
}


int32_t main() {

    precompute();

    int n;
    cin >> n;
    vector<int32_t> base(n);
    for(auto& x : base) cin >> x;

    if(n == 1) {
        cout << base[0];
        return 0;
    }

    // parity of nth row of pascals triangle
    vector<int> C(n);
    C[1] = power_of_2[n-1]; 
    for(int r = 1; r < n; ++r) {
        C[r] = C[r-1] + power_of_2[n-r] - power_of_2[r];
    }

    int res = 0, p = 1;

    vector<bool> bit(n);
    for(size_t b = 0; b < 30; ++b) {
        
        for(size_t i = 0; i < n; ++i) {
            bit[i] = base[i]%2;
            base[i]/=2;
        }

        /*
            the ith bit of the result will 1 if,
            the parity of the sum (nCj)*( bit[i] of the jth number ) over all j's is odd
        */
       
        bool on = false;
        for(int i = 0; i < n; i++) {
            if(bit[i]) on ^= (C[i] == 0);
        }

        if(on) res += p;
        p *= 2;
    }

    cout << res;

    return 0;
}