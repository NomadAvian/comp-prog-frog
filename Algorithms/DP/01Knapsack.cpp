#include<bits/stdc++.h>
using namespace std;

/*
    Given a bag that can hold a maximum weight of W and an array of items with 
    their respective weights and values, this function calculates the maximum value 
    that can be obtained by selecting items such that their total weight does not exceed W.
*/

int knapsack(vector<int>& weight, vector<int>& value, int cap, int n) {

    vector<int> memo(cap+1, 0);
    for(int item = 0; item < n; item++) { // iterate over items
        for(int i = cap; i >= weight[item]; i--) { // iterate over the weights backwards
            memo[i] = max(memo[i], memo[i - weight[item]] + value[item]);
        }
    }

    return memo[cap];
}
