#include<bits/stdc++.h>
using namespace std;


int32_t main() {
    
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i];

    vector<int> dp1(n),dp2(n),dp3(n);

    dp1[0] = a[0], dp2[0] = b[0], dp3[0] = c[0];
    for(int i = 1; i < n; i++) {
        dp1[i] = a[i] + max(dp2[i-1],dp3[i-1]);
        dp2[i] = b[i] + max(dp1[i-1],dp3[i-1]);
        dp3[i] = c[i] + max(dp1[i-1],dp2[i-1]);
    }

    int res = max(max(dp1[n-1],dp2[n-1]), dp3[n-1]);

    cout << res;
    
    return 0;
}