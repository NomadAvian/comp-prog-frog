#include<bits/stdc++.h>
using namespace std;

/*

    Find the maximum length palindrome in a string
    Time complexity: O(n)

*/

int manacher(string& s) {
    // preprocess
    string newS = "#";
    newS.reserve(2* s.size()+1);
    for(char c : s) newS += c, newS += "#";

    int n = newS.size();
    // memo
    vector<int> palin(n, 0);
    int center = 0, right = 0, max_len = 0;

    for(int i = 1; i < n-1; i++) {
        int mirror = 2*center - i;

        if(i < right) { // memo
            palin[i] = min(right - i, palin[mirror]);
        }

        // expand
        while(i - palin[i] - 1 >= 0 && i + palin[i] + 1 < n &&
              newS[i - palin[i] - 1] == newS[i + palin[i] + 1]    
            ) palin[i]++;

        // update center, right
        if(i + palin[i] > right) center = i, right = i + palin[i];

        max_len = max(max_len, palin[i]);

    }

    return max_len;
}