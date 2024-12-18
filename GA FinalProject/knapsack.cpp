#include "knapsackDP.hpp"
#include "knapsackGA.hpp"
#include "knapsackMF.hpp"
#include "knapsackGD.hpp"
#include "knapsackBF.hpp"
#include <chrono>

using namespace chrono;

int main()
{
    // Start recording time
    auto start = high_resolution_clock::now();

    int i, j;
    cin >> i;
    vector<int> value(i);
    vector<int> weights(i);

    for (int k = 0; k < i; k++)
    {
        cin >> weights[k] >> value[k];
    }
    cin >> j;
    cout << GAKnapsack(i, j, value, weights);
    // cout << MFKnapsack(i, j, value, weights);
    // cout << DPKnapsack(i, j, value, weights);
    // cout << GDKnapsack(i, j, value, weights);
    // cout << BFKnapsack(i, j, value, weights);

    // End recording time
    auto end = high_resolution_clock::now();

    // Calculate the elapsed time
    auto duration = duration_cast<milliseconds>(end - start);

    cout << endl;

    // Output the elapsed time in milliseconds
    cout << "Elapsed time: " << duration.count() << " milliseconds" << endl;
}