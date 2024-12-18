//66070501038 PHANTHACH JIAMJARUSCHOT
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int main () {

    int AS_complexity = 0, MD_complexity = 0, COMPARE_complexity = 0; //AdditonSubtraction, MultiplicationDivision, Compare

    int p[4];
    int n, result, val;

    for (int i = 0; i < 4; i++) { //input grilledpork number of 4 boxes
        cin >> p[i];
    }

    cin >> n; //overload

    vector<int> universe(n + 1); //for check combination that are makeable
    //find all the maximum boxes we can buy single grilledpork each boxes
    int a = floor(n/p[0]), b = floor(n/p[1]), c = floor(n/p[2]), d = floor(n/p[3]);
    MD_complexity += 4;

    for (int i = 0; i < a - 1; i++) {
        for (int j = 0; j < b - 1; j++) {
            for (int k = 0; k < c - 1; k++) {
                for (int l = 0; l < d - 1; l++) {
                    val = (p[0]*i) + (p[1]*j) + (p[2]*k) + (p[3]*l);
                    MD_complexity += 4;
                    AS_complexity += 3;
                    if (val > n) {
                        COMPARE_complexity++;
                        continue; //skip loop   
                    }
                    universe[val] = 1; //mark the makeable boxes pattern
                }
            }
        }
    }

    //find maximum numnber that can't be possible to make
    for (int i = n; i > 0; i--) {
        COMPARE_complexity++;
        if (universe[i] == 0) {
            COMPARE_complexity++;
            result = i;
            break;
        }
    }

    cout << result <<endl; //OUTPUT

    string max_group = "AS Group";
    int max_complexity = AS_complexity;

    // Compare with MD Group
    if (MD_complexity > max_complexity) {
        max_group = "MD Group";
        max_complexity = MD_complexity;
    }

    // Compare with Compare Group
    if (COMPARE_complexity > max_complexity) {
        max_group = "Compare Group";
        max_complexity = COMPARE_complexity;
    }

    cout << "Addition & Subtraction Group Operation : " << AS_complexity << endl;
    cout << "Mulitplication & Division Group Operation : " << MD_complexity << endl;
    cout << "Compare Group Operation : " << COMPARE_complexity << endl;

    cout << "Time Complexity Operation : " << max_group; 

    return 0;
}