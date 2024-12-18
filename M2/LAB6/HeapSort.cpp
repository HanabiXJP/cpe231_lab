//66070501038 Phanthach
#include <bits/stdc++.h>

using namespace std;

vector<int> Input(int n)
{
    vector<int> input(n + 1);

    for (int i = 1; i <= n; i++) {

        cin >> input[i];

    }

    return input;
}

void heapify(vector<int> &Numlist, int n, int i)
{

    int k = i;
    int v = Numlist[k];
    bool heap = false;
    while (!heap && 2 * k <= n)
    {
        int j = 2 * k;
        if (j < n && Numlist[j] >= Numlist[j + 1])
        {
            j++;
        }

        if (v < Numlist[j])
        {
            heap = true;
        }
        else
        {
            Numlist[k] = Numlist[j];
            k = j;
        }
    }
    Numlist[k] = v;
}

void heapSort(vector<int> &Numlist, int n)
{
    for (int i=n/2;i >= 1;i--){
        heapify(Numlist, n, i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << Numlist[i] << " ";
    }

    cout << '\n';

    for (int i = n; i >= 2; i--) {
        // Swap the root (Numlist[1]) with the last element (Numlist[i])
        swap(Numlist[1], Numlist[i]);

        // Reduce the heap size and restore the heap property
        heapify(Numlist, i - 1, 1);
    }
}


int main ()
{   
    int n;

    cin >> n;

    vector<int> Numlist = Input(n);

    heapSort(Numlist, n);
    
    for (int i = 1; i <= n; i++)
    {
        cout << Numlist[i] << " ";
    }



    return 0;
}

