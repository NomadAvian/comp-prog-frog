#include<bits/stdc++.h>
using namespace std;


int32_t main() {

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(auto& x : a) cin >> x;

    vector<int> res(2*k + 2);

    for(int i = 0; i <= k; ++i) {
        if(res[i]) continue;

        for(int j = 0; j < n; ++j) {
            int from = i + a[j];

            res[from] = 1;
        }
    }

    if(res[k]) cout << "First";
    else cout << "Second";

    return 0;
}