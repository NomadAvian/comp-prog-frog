#include<bits/stdc++.h>
using namespace std;

vector<int64_t> tp;

void precompute() {
    int64_t e = 1;
    while(e * 2 <= 1e15) {
        tp.push_back(e);
        e <<= 1;
    }
}

int32_t main() {

    precompute();

    int t;
    cin >> t;

    while(t--) {

        int64_t n, temp;
        cin >> n;
        temp = n;

        vector<int> binrep;
        int on = 0, off = 0;
        while(temp) {
            if(temp & 1) on++; else off++;
            binrep.push_back(temp & 1), temp>>=1;
        }

        int64_t res = 0;
        for(int i = binrep.size() - 1; i >= 0; --i) {

            if(binrep[i] == 0) 
                --off;
            else {
                --on;
                res += (tp[off] - 1) * tp[on];
            }

        }

        cout << res << ' ' << n-res+1 << '\n';

    }

    return 0;
}