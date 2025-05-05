#include<bits/stdc++.h>
using namespace std;

int n;
double p[301][301][301];
double ev[301][301][301];


int32_t main() {

    cin >> n;

    int a[n];

    int cnt[4] = {0,0,0,0};

    for(int& x : a) { 
        cin >> x;
        cnt[x]++;
    }

    p[cnt[1]][cnt[2]][cnt[3]] = 1.0;

    for(int c = n; c >= 0; --c) {
        for(int b = n; b >= 0; --b) {
            for(int a = n; a >= 0; --a) {

                if(a == 0 && b == 0 && c == 0) 
                    continue;
                int tot = a + b + c;
                if(tot > n)
                    continue;

                double p_0 = (double) (n - tot) / n;
                double ev_0 = p_0 / (1.0 - p_0) + 1.0; // S_inf = a / (1 - r)

                ev[a][b][c] += ev_0 * p[a][b][c];

                if(a > 0) {
                    double p_1 = (double) a / tot;
                    p[a-1][b][c] += p[a][b][c] * p_1;
                    ev[a-1][b][c] += ev[a][b][c] * p_1;
                }

                if(b > 0) {
                    double p_2 = (double) b / tot;
                    p[a+1][b-1][c] += p[a][b][c] * p_2;
                    ev[a+1][b-1][c] += ev[a][b][c] * p_2;
                }

                if(c > 0) {
                    double p_3 = (double) c / tot;
                    p[a][b+1][c-1] += p[a][b][c] * p_3;
                    ev[a][b+1][c-1] += ev[a][b][c] * p_3;
                }
            }
        }
    }

    cout << fixed << setprecision(10) << ev[0][0][0];

    return 0;
}