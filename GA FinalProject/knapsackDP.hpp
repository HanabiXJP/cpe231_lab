#include <bits/stdc++.h>
using namespace std;

int DPKnapsack(int i, int j, vector<int> &value, vector<int> &weights)
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
    for (int m = 1; m <= i; m++)
    {
        for (int n = 1; n <= j; n++)
        {
            int val;
            if (n < weights[m - 1])
            {
                val = dp[m - 1][n];
            }
            else
            {
                val = max(dp[m - 1][n], value[m - 1] + dp[m - 1][n - weights[m - 1]]);
            }
            dp[m][n] = val;
        }
    }
    return dp[i][j];
}