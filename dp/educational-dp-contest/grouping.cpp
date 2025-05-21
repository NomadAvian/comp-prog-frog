#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll mat[16][16];

int32_t main() {

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }

    int tot = (1<<n);
    ll res = -1e18;

    for(int subset = 0; subset < tot; ++subset) {
        
    }

    cout << res << endl;

    return 0;
}