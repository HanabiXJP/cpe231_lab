//66070501038 Phanthach
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxVal(int a, int b) { return a > b ? a : b; }

bool isZigZag(const vector<int>& arr) {
    if (arr.size() <= 1) return true;
    for (size_t i = 1; i < arr.size() - 1; i++) {
        if (!((arr[i-1] < arr[i] && arr[i] > arr[i+1]) || 
              (arr[i-1] > arr[i] && arr[i] < arr[i+1]))) {
            return false;
        }
    }
    return true;
}

// DP function to calculate the lengths of zigzag subsequences
vector<pair<int, int>> dpZigZag(const vector<int>& arr) {
    int total = arr.size();
    vector<pair<int, int>> dp(total, {1, 1});  // dp[i].first = up, dp[i].second = down

    // Process the dp array
    for (int i = 1; i < total; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i].first = maxVal(dp[i].first, dp[j].second + 1);
            }
            if (arr[j] > arr[i]) {
                dp[i].second = maxVal(dp[i].second, dp[j].first + 1);
            }
        }
    }
    
    return dp;
}

int main() {
    int total;
    cin >> total;
    vector<int> arr(total);

    for (int i = 0; i < total; i++) {
        cin >> arr[i];
    }

    // Call the DP function to compute zigzag lengths
    vector<pair<int, int>> dp = dpZigZag(arr);

    // Output the results for both "up" and "down" sequences
    for (int i = 0; i < total; i++) {
        cout << dp[i].first << " ";
    }
    cout << '\n';

    for (int i = 0; i < total; i++) {
        cout << dp[i].second << " ";
    }
    cout << '\n';

    // You can still check zigzag condition and other logic as needed
    for (int i = 0; i < total; i++) {
        vector<int> subarr;

        // Construct the zigzag subsequence (if needed)
        int up = dp[i].first;
        int down = dp[i].second;
    }

    return 0;
}
