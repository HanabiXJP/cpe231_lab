#include <bits/stdc++.h>
//greedy knapsack
using namespace std;

int GDKnapsack(int i, int j, vector<int>& value, vector<int>& weights) {
    vector<vector<int>> dp(i + 1, vector<int>(j + 1, 0));

    for (int item = 1; item <= i; item++) {
        for (int cap = 1; cap <= j; cap++) {
            if (weights[item - 1] <= cap) {
                // Include the item if it fits, or exclude it
                dp[item][cap] = max(dp[item - 1][cap],
                                    value[item - 1] + dp[item - 1][cap - weights[item - 1]]);
            } else {
                // Exclude the item
                dp[item][cap] = dp[item - 1][cap];
            }
        }
    }

    return dp[i][j];
}
