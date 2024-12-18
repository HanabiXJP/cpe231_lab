//66070501038 Phanthach
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int MFKnapsack(int index,int maxp, vector<int> weight, vector<int> value, vector<vector<int>> &F)
{
    if (index == 0) 
    {
        if(maxp >= weight[index])
        {
            return value[index];
        }

        else {
            return 0;
        }
    }
    if (F[index][maxp] != -1) {
        return F[index][maxp];
    }
    int choose = INT_MIN;
    if (maxp >= weight[index]) 
    {
        choose = value[index] + MFKnapsack(index - 1, maxp - weight[index], weight, value, F);
    }
    
    int notchoose = MFKnapsack(index - 1, maxp, weight, value,  F);
    return F[index][maxp] = max(choose, notchoose);
}

int main() 
{
    int n,p;

    cin >> n;

    vector<int> weight(n);
    vector<int> value(n);
    

    for (int i = 0; i < n; i++)
    {
        cin >> value[i] >> weight[i];
    }

    cin >> p; //maxrungrang

    vector<vector<int>> F(n, vector<int>(p + 1, -1));

    cout << MFKnapsack(n - 1, p , value, weight, F);

    return 0;
}