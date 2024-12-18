#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX

using namespace std;

void ChangeMaking(int n, vector<int> D, int m)
{
    vector<int> F(n + 1, INT_MAX);  // Initialize F with size n+1 and all values as INT_MAX
    F[0] = 0;  // Base case: 0 coins needed to make 0 amount
    cout << F[0] << endl; 
    for (int i = 1; i <= n; i++)
    {
        int j = 0;
            while (j < m &&i >= D[j])
            {
                F[i] = min(F[i], F[i - D[j]] + 1);
                j++;
            }
        cout << F[i] << endl; 
    }
}

int main()
{
    int n = 6;
    vector<int> D = {1, 3, 4};
    int m = D.size();

    ChangeMaking(n, D, m);
    return 0;
}
