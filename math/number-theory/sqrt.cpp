#include<bits/stdc++.h>
using namespace std;


double sqrt(double n) {
    double ep = 1e-9;

    double lb = 0, ub = max(1.0, n), res = 0;
    while((ub - lb) > ep) {
        double mid = lb + (ub - lb) / 2.0;
        double res = mid*mid;

        if(abs(n - res) <= ep) return mid;

        if(mid*mid < n) lb = mid;
        else ub = mid; 
    }

    return 0;
}


int32_t main() {
    
    cout << sqrt(2.0) << '\n';

    return 0;
}