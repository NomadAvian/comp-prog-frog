#include<bits/stdc++.h>
using namespace std;

/*
    https://usaco.org/index.php?page=viewproblem2&cpid=1018

    greedily determine how many contiguous segments a given segments contributes to
    from left to right, in each subset it is present in
*/

const int MOD = 1e9 + 7;
const int maxn = 2e5 + 7;

int64_t tp[maxn];

void precompute() {
    tp[0] = 1;
    for(int i = 1; i < maxn; ++i)
        tp[i] = (tp[i-1] * 2) % MOD;
}

int32_t main() {

    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);

    precompute();

    int n;
    cin >> n;

    vector<pair<int,int>> S(n);
    vector<int> prefix(2*n+7);

    for(auto& x : S) { 
        cin >> x.first >> x.second;
        prefix[x.first]++, prefix[x.second+1]--;
    }

    for(int i = 1; i <= 2*n; ++i) prefix[i] += prefix[i-1];

    sort(S.begin(), S.end());

    int64_t res = 0;

    for(int i = 0; i < n;) {
        
        int start = S[i].first;
        int tot = prefix[ S[i].first ], rem = 0;

        while(S[i].first == start) { 
            ++rem, ++i;
            if( i == n ) break;
        }

        int counted = tot - rem;
        for(int p = counted; p < tot; ++p) {
            res += tp[ n - p - 1 ];
            res %= MOD;
        }
    }

    cout << res;

    return 0;
}