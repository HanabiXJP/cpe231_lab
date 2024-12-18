//66070501038 Phanthach
#include <bits/stdc++.h>

using namespace std;

// Function to input a vector of size n
vector<int> Input(int n)
{
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    return input;
}

// Custom merge function to merge two sorted subarrays
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + j];

    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Bottom-up merge sort function
vector<int> BottomUpMergeSort(vector<int> &Numlist, int n)
{
    for (int width = 1; width < n; width *= 2) {
        for (int i = 0; i < n; i += 2 * width) {
            int mid = min(i + width, n);
            int right = min(i + 2 * width, n);
            if (mid < right) {
                merge(Numlist, i, mid, right);
            }
        }
    }
    return Numlist;
}

int main()
{
    int n;
    cin >> n;

    vector<int> Numlist = Input(n);

    vector<int> Result = BottomUpMergeSort(Numlist, n);

    for (int i : Numlist) {
        cout << i << " ";
    }

    return 0;
}
