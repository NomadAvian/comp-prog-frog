#include<bits/stdc++.h>
using namespace std;

/*
    https://usaco.org/index.php?page=viewproblem2&cpid=832
*/

int32_t main() {

    freopen("milkorder.in","r",stdin);
    freopen("milkorder.out","w",stdout);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int32_t> Q(N+1), track(N+1), H(M+1);

    for(size_t i = 1; i <= M; ++i) {
        cin >> H[i];
        track[H[i]] = -1;
    }

    int c, p;
    while(K--) {
        cin >> c >> p;
        Q[p] = c, track[c] = p;
    }

    int res = 1;

    if(track[1] == -1) { // cow 1 is in the hierarchy with no fixed position
        int itrH = 1, itrQ = 1;
        for(; itrH <= M; ++itrH) {
            int record = track[ H[itrH] ];

            if(record > 0) { 
                itrQ = record+1;
            } else {
                while(Q[itrQ]) itrQ++;

                Q[itrQ] = H[itrH];
                track[H[itrH]] = itrQ;
            }  
        }
        res = track[1];

    } else if(track[1] == 0) { // cow 1 is not in the hierarchy with no fixed position
        int itrH = M, itrQ = N;
        for(; itrH >= 1; --itrH) {
            int record = track[ H[itrH] ];

            if(record > 0) { 
                itrQ = record-1;
            } else {
                while(Q[itrQ]) itrQ--;

                Q[itrQ] = H[itrH];
            }  
        }
        while(Q[res]) res++;

    } else { // cow 1 is chilling
        res = track[1];
    }

    cout << res;

    return 0;
}