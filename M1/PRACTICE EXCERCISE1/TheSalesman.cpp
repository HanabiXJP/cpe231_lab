#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p; // Number of countries and number of flights
    cin >> n >> p;
    
    string country1, country2; // Variables to store the names of the countries
    int cost; // Variable to store the cost of the flight

    // Vector to store the countries as pairs (country name, index)
    vector<pair<string, int>> countries;
    countries.push_back(make_pair("THA", 0)); // "THA" is the starting country

    // Adjacency matrix to store the flight costs
    vector<vector<int>> flightCost(n + 1, vector<int>(n + 1, 0));

    // Input flight data
    for (int i = 0; i < p; i++) {
        cin >> country1 >> country2 >> cost;
        int found1 = -1, found2 = -1;

        // Check if the countries already exist in the list
        for (int j = 0; j < countries.size(); j++) {
            if (country1 == countries[j].first) {
                found1 = j;
            }
            if (country2 == countries[j].first) {
                found2 = j;
            }
        }

        // If not found, add the countries to the list
        if (found1 == -1) {
            countries.push_back(make_pair(country1, countries.size()));
            found1 = countries.size() - 1;
        }
        if (found2 == -1) {
            countries.push_back(make_pair(country2, countries.size()));
            found2 = countries.size() - 1;
        }

        // Assign flight costs to the adjacency matrix
        flightCost[found1][found2] = flightCost[found2][found1] = cost;
    }

    int maxCost = 0; // Variable to store the maximum cost of any path
    vector<pair<string, int>> optimalPath; // Vector to store the optimal path

    // Brute-force permutation search to find the maximum cost path
    do {
        int currentCost = 0;

        // Calculate the total cost of the current permutation path
        for (int i = 0; i < n; i++) {
            currentCost += flightCost[countries[i].second][countries[i + 1].second];
        }
        currentCost += flightCost[countries[n].second][countries[0].second]; // Return to the start

        // Update the maximum cost and optimal path if the current cost is higher
        if (currentCost > maxCost) {
            maxCost = currentCost;
            optimalPath = countries;
        }
    } while (next_permutation(countries.begin() + 1, countries.end())); // Permute starting from the second country

    // Output the optimal path
    for (int i = 0; i < n + 1; i++) {
        cout << optimalPath[i].first << " ";
    }
    cout << "THA" << endl;
    cout << maxCost << endl;

    return 0;
}
