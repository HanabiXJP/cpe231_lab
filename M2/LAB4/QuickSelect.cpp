//66070501038 Phanthach
#include <iostream>
#include <vector>

using namespace std;

vector<int> InputList(int n)
{
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    return input;
}

int LomutoPartition(vector<int> &NumList, int l, int r)
{
    int p = NumList[l];  // Choosing the pivot
    int s = l;
    for (int i = l + 1; i <= r; i++)
    {
        if (NumList[i] < p)
        {
            s++;
            swap(NumList[s], NumList[i]);
        }
    }
    swap(NumList[l], NumList[s]);  // Place pivot in its correct position
    return s;
}

int QuickSelect(vector<int> &NumList, int l, int r, int k)
{
    if (l == r)
        return NumList[l];  // If only one element, return it

    int s = LomutoPartition(NumList, l, r);  // Partition the list
    if (s == k - 1)  // Found the k-th smallest element
    {
        return NumList[s];
    }
    else if (s > k - 1)  // Look on the left part
    {
        return QuickSelect(NumList, l, s - 1, k);
    }
    else  // Look on the right part
    {
        return QuickSelect(NumList, s + 1, r, k);
    }
}

int main() 
{
    int n, k;
    cin >> n;
    vector<int> NumList = InputList(n);
    cin >> k;

    int Result = QuickSelect(NumList, 0, n - 1, k);
    cout << Result << endl;

    return 0;
}
