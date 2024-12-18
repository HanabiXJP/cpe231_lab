//66070501038 Phanthach
#include <iostream>
#include <vector>

using namespace std;

vector<int> InputPancake(int n)
{
    vector<int> input(n);

    for (int i = 0; i < n; i++) {

        cin >> input[i];

    }

    return input;
}

int findMaxIndex(vector<int> Pancake, int i)
{
    int max = 0;
    for (int k = 0 ; k <= i; k++) {
        if (Pancake[k] > Pancake[max])
        {
            max = k;
        }
    }

    return max;
}

void flip(vector<int> &Pancake, int i)
{
    int index = (i-1)/2;
    for (int k = 0; k <= index; k++)
    {
        swap(Pancake[k], Pancake[i-k]);
    }
}

void PancakeSort(vector<int> &Pancake)
{
    for(int i = Pancake.size() - 1 ; i > 0; i--)
    {
        int maxIndex = findMaxIndex(Pancake, i);
        if (maxIndex != i)
        {
            if (maxIndex != 0)
            {
                flip(Pancake, maxIndex);
            }
            flip(Pancake, i);
        }
    }

    for (auto i : Pancake) 
    {
        cout << i << " ";
    } 

    cout << endl;
}

int main() 
{

    int n; //Pancake Numbers

    cin >> n;

    vector<int> Pancake = InputPancake(n);

    PancakeSort(Pancake);

    return 0;

}