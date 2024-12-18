//66070501038 Phanthach
#include <bits/stdc++.h>

using namespace std;

vector<int> Input(int n)
{
    vector<int> input(n);

    for (int i = 0; i < n; i++) {

        cin >> input[i];

    }

    return input;
}

int HoarePartition(vector<int> &Numlist, int l, int r)
{
    int p = Numlist[l];
    int i = l;
    int j = r + 1;
    while (i < j)
    {
        do
        {
            i++;
        } while(Numlist[i] < p);

        do
        {
            j--;
        } while(Numlist[j] > p);
        
        swap(Numlist[i], Numlist[j]);
    }

    swap(Numlist[i], Numlist[j]);
    swap(Numlist[l],Numlist[j]);
    return j;
}

vector<int> Quicksort(vector<int> &Numlist, int l, int r) {

    int s;
    if (l < r)
    {
        s = HoarePartition(Numlist, l, r);
        Quicksort(Numlist, l, s - 1);
        Quicksort(Numlist, s + 1, r);
    }

    return Numlist;
}

vector<int> PresortElementUniqueness(vector<int> &arr)
{
    int n = arr.size();

    vector<int> sortarray;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            sortarray.push_back(arr[i]);
        }
    }

    return sortarray;
}   

int main ()
{   
    int n;

    cin >> n;

    vector<int> Numlist = Input(n);

    Quicksort(Numlist, 0, n - 1);

    vector<int> Result = PresortElementUniqueness(Numlist);

    for (int i : Result)
    {
        cout << i << " "; 
    }

    return 0;
}