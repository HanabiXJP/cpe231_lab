//66070501038 Phanthach
#include <bits/stdc++.h>

using namespace std;

int maxSubArraySum(int arr[], int l, int h) {
    if (l > h)
        return INT_MIN;
    if (l == h)
        return arr[l];

    int mid = (l + h) / 2;

    // Find maximum subarray sum on left side of the midpoint
    int left_sum = INT_MIN, sum = 0;
    for (int i = mid; i >= l; i--) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    // Find maximum subarray sum on right side of the midpoint
    int right_sum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= h; i++) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    // Return the maximum of the left, right, and crossing subarray sums
    return max({maxSubArraySum(arr, l, mid - 1), maxSubArraySum(arr, mid + 1, h), left_sum + right_sum});
}

int main() {
    int n;
    cin >> n;

    int Number[n];
    for (int i = 0; i < n; i++) {
        cin >> Number[i];
    }

    int result = maxSubArraySum(Number, 0, n - 1);
    cout << result;

    return 0;
}
