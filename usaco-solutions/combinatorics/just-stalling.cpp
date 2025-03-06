#include<bits/stdc++.h>
using namespace std;

/*
    https://usaco.org/index.php?page=viewproblem2&cpid=1085#
*/

int32_t main() {
    
    int n;
    cin >> n;

    vector<int32_t> a(n),b(n);
    for(auto& x : a) cin >> x;
    for(auto& x : b) cin >> x;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int64_t res = 1;
    int32_t placed = 0;

    for(int i = n-1; i >= 0; --i) {
        if(a[i] > b[i]) { // has no spot
            res = 0;
            break;
        }

        int itr = lower_bound(b.begin(),b.end(),a[i]) - b.begin();

        res *= (n - itr - placed);
        placed++;
    }

    cout << res;

    return 0;
}