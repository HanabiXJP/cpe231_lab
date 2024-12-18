//66070501038 PHANTHACH JIAMJARUSCHOT
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}
int main() {

    int n; //number of plant and plant pot

    cin >> n;

    if (n > 1000 || n < 1) {
        cout << "Please enter number between 1 to 1000";

        return 0;
    }

    int plant[n];
    int pot[n];
    int group[n]; //variable name, group is plant with pot

    int d; // common difference

    for (int i = 0; i < n ; i++) {
        cin >> pot[i];
    }

    for (int i = 0; i < n ; i++) {
        cin >> plant[i];
    }
    //sorting height
    sort(plant, plant + n); //Ascending
    sort(pot, pot + n, compare); //Descending

    // for (int i = 0; i < n ; i++) {
    //     cout << pot[i] << " ";
    // }

    // cout << endl;

    // for (int i = 0; i < n ; i++) {
    //     cout << plant[i] << " ";
    // }

    for (int i = 0; i < n ; i++) {
        group[i] = plant[i] + pot[i];
    }

    sort(group, group + n, compare);

    for(int i = 0; i < n-1 ;i++) {
        d += group[i]-group[i+1];
        // cout << d << endl; process
    }

    cout << d;
    return 0;
}