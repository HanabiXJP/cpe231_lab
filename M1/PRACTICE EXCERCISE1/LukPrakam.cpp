#include <iostream>

using namespace std;

int main () {
    int n,distance,start,result;
    int pos = 0;

    int mindis = 1000;

    cin >> n;
    int bead[n];

    for (int i = 0; i < n; i++) {
        cin >> bead[i];
    }

    //find min distance
    for (int i = 0; i < n-1; i++) {
        distance = bead[i+1] - bead[i];
        if (distance < mindis) {
            mindis = distance;
        }
    }

    for (int i = 0; i < n; i++) {

        result = bead[0] + pos;

        result = bead[i] - result;

        pos+=mindis;

        cout << result << " ";

    }

return 0;

}
