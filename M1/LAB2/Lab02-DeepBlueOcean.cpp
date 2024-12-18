//66070501038 PHANTHACH JIAMJARUSCHOT
#include <iostream>
#include <string>
using namespace std;

int AS_complexity = 0, MD_complexity = 0, COMPARE_complexity = 0; //AdditonSubtraction, MultiplicationDivision, Compare

int factorial (int n) {
    COMPARE_complexity++;
    if (n == 1) 
        return 1;
    else {
        AS_complexity++;
        MD_complexity++;
        return factorial(n-1)*n;
    }
        
}

int main() {

    int n,v,p;

    cin >> n >> v; // number of student & professor and professor Wee position

    int arrayN[n];

    for (int i = 0; i < n; i++) { //student number 4 digits
        cin >> arrayN[i];
        COMPARE_complexity++;
    }

    cin >> p; // number of student who don't want to receive with professor Wee

    int arrayP[p];
    for (int i = 0; i < p; i++) { //student number 4 digits
        cin >> arrayP[i];
        COMPARE_complexity++;
    }

    int output = factorial(n-1) * (n-p); //Number of solution
    AS_complexity++;
    MD_complexity++;

    cout << output << endl;

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