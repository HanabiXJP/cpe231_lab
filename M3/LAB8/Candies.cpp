#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

void MaxImpossibleCandies(int maxstick, vector<int> D, int n) {
    vector<bool> dp(maxstick + 1, false);  // dp[i] will be true if i candies can be bought
    dp[0] = true;  // Base case: 0 candies is always possible with no bags

    // Fill dp array for all amounts from 1 to maxstick
    for (int i = 0; i <= maxstick; i++) {
        if (dp[i]) {  // If i candies can be bought
            for (int j = 0; j < n; j++) {
                if (i + D[j] <= maxstick) {
                    dp[i + D[j]] = true;  // Mark i + D[j] as reachable
                }
            }
        }
    }

    // Find the largest number <= maxstick that cannot be achieved
    int maxImpossible = -1;
    for (int i = maxstick; i >= 0; i--) {
        if (!dp[i]) {
            maxImpossible = i;
            break;
        }
    }

    // Output the result
    if (maxImpossible == -1) {
        cout << "All numbers up to " << maxstick << " can be bought." << endl;
    } else {
        cout << "Maximum number of candies that cannot be bought: " << maxImpossible << endl;
    }
}

int main() {
    int maxstick, n;

    // Take inputs
    cin >> maxstick >> n;

    vector<int> box(n);

    // Input the available bag sizes
    for (int i = 0; i < n; i++) {
        cin >> box[i];
    }

    // Call the function to find the maximum unreachable candies
    MaxImpossibleCandies(maxstick, box, n);

    return 0;
}
