#include<bits/stdc++.h>
using namespace std;

/*
    https://codeforces.com/contest/1775/problem/D
*/

const int MAX = 3e5;

vector<int> prime;
void sieve(int limit) {
    vector<bool> mark(limit+1, true);

    for(int p = 3; p*p <= limit; p+=2) {
        if(mark[p])
            for(int i = p*p; i <= limit; i+=p+p)
                mark[i] = false;
    }

    prime.push_back(2);
    for(int p = 3; p <= limit; p+=2)
        if(mark[p]) prime.push_back(p);
}

int32_t main() {

    sieve(MAX);

    int n;
    cin >> n;

    vector<int> a(n);
    int mx = 0;

    for(auto& x : a) { 
        cin >> x;
        mx = max(mx, x);
    }

    int s, t;
    cin >> s >> t;
    --s, --t;

    vector<vector<int>> group(MAX+1), arr(n+1);
    for(int i = 0; i < n; ++i) {

        for(int p : prime) {
            if((int64_t)p*p > a[i]) break;

            if(a[i] % p == 0) {
                group[p].push_back(i);
                arr[i].push_back(p);
            }

            while(a[i] % p == 0) a[i]/=p;
        }

        if(a[i] > 1) {
            group[a[i]].push_back(i);
            arr[i].push_back(a[i]);
        }
    }

    vector<vector<int>> path(n);
    vector<bool> visNode(n), visGroup(MAX+1);
    queue<int> nodeQ, groupQ;

    nodeQ.push(s);
    visNode[s] = true;
    path[s].push_back(s);

    while(!nodeQ.empty()) {
        int u = nodeQ.front();
        nodeQ.pop();

        if( u == t ) break;

        for(int g : arr[u]) {
            if(visGroup[g]) continue;

            visGroup[g] = true;
            groupQ.push(g);
        }

        while(!groupQ.empty()) {
            int g = groupQ.front();
            groupQ.pop();

            for(int member : group[g]) {
                if(visNode[member]) continue;

                visNode[member] = true;
                path[member] = path[u];
                path[member].push_back(member);
                nodeQ.push(member);
            }
        }
    }

    if(path[t].size()) {
        cout << path[t].size() << '\n';
        for(int step : path[t]) cout << step+1 << ' ';
    } else {
        cout << -1;
    }

    return 0;
}