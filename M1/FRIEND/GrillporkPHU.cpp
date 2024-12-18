//Grilled Pork
//66070501041 Phubordin Ramsiri
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int main() {
    int a, b, c, d; //for define each mhooping set
    int overload; //max number that mhooping set can make in single purchase
    int temp; //storing max val for combination of mhooping set
    int sol; //ans for this question

    //for time complexity
    int add = 0, mul = 0, comprs = 0;

    //input all mhooping set and overload number
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> overload;

    //this list will store the check mark for all combination that we can make
    vector<int> possible_list(overload + 1);

    //find all the max numbers each single mhooping set can make in single purchase without overloading
    int w = floor(overload/a), x = floor(overload/b), y = floor(overload/c), z = floor(overload/d);
    mul += 4;

    for (int i = 0; i < w - 1; i++) 
        for (int j = 0; j < x - 1; j++)
            for (int k = 0; k < y - 1; k++)
                for (int p = 0; p < z - 1; p++) {
                    temp = (a * i) + (b * j) + (c * k) + (d * p);
                    mul += 4;
                    add += 3;
                    if (temp > overload) {comprs++; continue;}  //prevent overload case.
                    possible_list[temp] = 1;                    //mark!, we can make "temp" combination out of each mhooping set.
                }

    //search the max combination that we "can't" make from tail -> head of the list
    for (int i = overload; i > 0; i--) {
        if (possible_list[i] == 0) {comprs++; sol = i; break;}
    }

    //output ans for this headache quesiton
    cout << sol <<endl;

    //output time complexity counter
    cout << "add/sub: " + to_string(add) + "  mul/div: " + to_string(mul) + "  comprs: " + to_string(comprs);

    return 0;
}