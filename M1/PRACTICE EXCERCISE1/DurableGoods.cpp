#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double BestPrice(vector<vector<double>>price) {

    vector<int> depart(price.size());

    double total = 0;

    for (int i = 0; i < price.size(); i++) {

        depart[i] = i;
        
    }
    
    do {
        
        double cost = 0;
        for (int i = 0; i < depart.size(); i++) {

            cost += price[i][depart[i]];

        }

        total = total > cost ? total : cost;

    } while(next_permutation(depart.begin(),depart.end()));

    return total;
}

int main() {

    int n; //Goods amount and total department 

    cin >> n;

    vector<vector<double>> price(n,vector<double>(n));

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            cin >> price[i][j];

        }
    }

    double Total = BestPrice(price);

    cout << Total;

    return 0;
}