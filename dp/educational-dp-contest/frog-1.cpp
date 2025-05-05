#include<bits/stdc++.h>
using namespace std;

int32_t main() {

    int n;
    cin >> n;

    vector<int64_t> h(n);
    for(auto& x : h) cin >> x;

    int64_t memo[n];

    memo[0] = 0, memo[1] = abs(h[0] - h[1]);

    for(int i = 2; i < n; ++i) {
        memo[i] = min(memo[i-1] + abs(h[i-1] - h[i]), memo[i-2] + abs(h[i-2] - h[i]));
    }

    cout << memo[n-1];

    return 0;

}