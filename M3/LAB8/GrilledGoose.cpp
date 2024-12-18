//66070501038 Phanthach
#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

void MaxImpossibleStick(int maxstick, vector<int> D, int n) {
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
    cout << maxImpossible << endl; //Maximum number of candies that cannot be bought
}

int main() {
    int maxstick, n;

    cin >> maxstick >> n;

    vector<int> box(n);

    for(int i = 0; i < n; i++)
    {
        cin >> box[i];
    }

    MaxImpossibleStick(maxstick, box, n);

    return 0;
}
