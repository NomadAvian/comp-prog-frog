#include<bits/stdc++.h>
using namespace std;

vector<int> prime;
void sieve(int limit) {
    vector<bool> mark(limit+1, true);

    prime.push_back(2);
    for(int p = 3; p*p <= limit; p+=2) {
        if(mark[p])
            for(int i = p*p; i <= limit; i+=p+p)
                mark[i] = false;
    }

    for(int p = 3; p <= limit; p+=2)
        if(mark[p]) prime.push_back(p);
}

// driver code
int main() {
    sieve(20);

    for(auto p : prime) cout << p << " ";
  
    return 0;
}
