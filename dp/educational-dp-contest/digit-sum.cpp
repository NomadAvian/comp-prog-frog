#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e4 + 7;

int dp[maxn][100][2];

int d;

int add_self(int& a, int b) {
    a += b;
    if(a >= mod) a -= mod;
    return a;
}

int f(vector<int>& a, int pos, int rem, int tight) {
    if(pos == a.size())
        return (rem == 0) ? 1 : 0;
    if(dp[pos][rem][tight] != -1)
        return dp[pos][rem][tight];
    
    int lim = tight ? a[pos] : 9;

    int res = 0;
    for(int digit = 0; digit <= lim; ++digit) {
        int new_tight = tight && (digit == lim);
        int new_rem = (rem + digit) % d;
        add_self(res, f(a,pos+1,new_rem,new_tight));
    }

    if(!tight)
        dp[pos][rem][tight] = res;
    return res;
}

int32_t main() {

    memset(dp, -1, sizeof(dp));

    string k;
    cin >> k >> d;
    vector<int> a(k.size());
    for(int i = 0; i < k.size(); ++i) a[i] = k[i]-'0';

    int res = f(a,0,0,1) - 1;
    if(res < 0) res += mod;

    cout << res << endl;

    return 0;
}