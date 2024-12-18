#include <bits/stdc++.h>
using namespace std;

int MFKnapsack(int i, int j, vector<int> &value, vector<int> &weights, vector<vector<int>> &dp)
{
    int val;
    if (dp[i][j] == -1)
    {
        if (j < weights[i - 1])
        {
            val = MFKnapsack(i - 1, j, value, weights, dp);
        }
        else
        {
            val = max(MFKnapsack(i - 1, j, value, weights, dp), value[i - 1] + MFKnapsack(i - 1, j - weights[i - 1], value, weights, dp));
        }
        dp[i][j] = val;
    }
    return dp[i][j];
}

int MFKnapsack(int i, int j, vector<int> &value, vector<int> &weights)
{
    vector<vector<int>> dp(i + 1, vector<int>(j + 1, -1));
    for (int k = 0; k <= i; k++)
    {
        dp[k][0] = 0;
    }
    for (int k = 0; k <= j; k++)
    {
        dp[0][k] = 0;
    }

    return MFKnapsack(i, j, value, weights, dp);
}