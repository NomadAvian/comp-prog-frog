#include<bits/stdc++.h>
using namespace std;

int32_t main() {

    int n, k;
    cin >> n >> k;

    vector<int64_t> h(n);
    for(auto& x : h) cin >> x;

    int64_t memo[n];

    memo[0] = 0, memo[1] = abs(h[0] - h[1]);

    for(int i = 2; i < n; ++i) {

        memo[i] = memo[i-1] + abs(h[i-1] - h[i]);

        for(int j = 2; j <= k and i-j >= 0; ++j) {
            memo[i] = min(memo[i-j] + abs(h[i-j] - h[i]), memo[i]);
        }

    }

    cout << memo[n-1];

    return 0;

}