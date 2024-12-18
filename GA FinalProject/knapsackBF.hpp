#include <bits/stdc++.h>
//brute force
using namespace std;
int BFKnapsack(int i, int j, vector<int>& value, vector<int>& weights) {
    if (i == 0 || j == 0) {
        return 0;
    }

    // If the current item's weight exceeds the remaining capacity, skip it
    if (weights[i - 1] > j) {
        return BFKnapsack(i - 1, j, value, weights);
    }

    int exclude = BFKnapsack(i - 1, j, value, weights); // Exclude current item
    int include = value[i - 1] + BFKnapsack(i - 1, j - weights[i - 1], value, weights);

    return max(exclude, include);
}

