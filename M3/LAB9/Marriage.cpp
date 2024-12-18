#include <iostream>
#include <vector>
#include <cstring> // For memset
using namespace std;

// This function returns true if company 'c' prefers student 's1' over student 's'
bool cPrefersS1OverS(const vector<vector<int>>& prefer, int c, int s, int s1, int n) {
    // Check if c prefers s over its current engagement s1
    for (int i = 0; i < n; i++) {
        // If s1 comes before s in list of c, then c prefers its current engagement, don't do anything
        if (prefer[c][i] == s1)
            return true;

        // If s comes before s1 in c's list, then free its current engagement and engage with s
        if (prefer[c][i] == s)
            return false;
    }
    return false; // This line ensures that a value is returned in all cases
}

// Prints stable matching for n students and n companies
void stableInternship(const vector<vector<int>>& studentPrefer, const vector<vector<int>>& companyPrefer, int n) {
    // Stores partner of companies. This is our output array that stores partner information.
    // The value of cPartner[i] indicates the partner assigned to company i. The value -1
    // indicates that i'th company is free
    int cPartner[n];

    // An array to store availability of students. If sFree[i] is false, then student 'i' is free, otherwise engaged.
    bool sFree[n];

    // Initialize all students and companies as free
    memset(cPartner, -1, sizeof(cPartner));
    memset(sFree, false, sizeof(sFree));
    int freeCount = n;

    // While there are free students
    while (freeCount > 0) {
        // Pick the first free student (we could pick any)
        int s;
        for (s = 0; s < n; s++)
            if (!sFree[s])
                break;

        // One by one go to all companies according to s's preferences.
        // Here s is the picked free student
        for (int i = 0; i < n && !sFree[s]; i++) {
            int c = studentPrefer[s][i];

            // The company of preference is free, c and s become partners
            // (note that the partnership may be changed later). So we can say they are engaged not hired
            if (cPartner[c] == -1) {
                cPartner[c] = s;
                sFree[s] = true;
                freeCount--;
            } else { // If c is not free
                // Find current engagement of c
                int s1 = cPartner[c];

                // If c prefers s over its current engagement s1, then break the engagement between c and s1 and engage c with s
                if (!cPrefersS1OverS(companyPrefer, c, s, s1, n)) {
                    cPartner[c] = s;
                    sFree[s] = true;
                    sFree[s1] = false;
                }
            } // End of Else
        } // End of the for loop that goes to all companies in s's list
    } // End of main while loop

    // Print the solution
    for (int i = 0; i < n; i++)
        cout << i << " " << cPartner[i] << endl;
}

// Driver program to test above functions
int main() {

    int n;

    cin >> n;

    vector<vector<int>> StudentPrefer(n, vector<int>(n));
    vector<vector<int>> CompanyPrefer(n, vector<int>(n));

    // Collecting preferences for Students
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> StudentPrefer[i][j];
        }
    }

    // Collecting preferences for Companies
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> CompanyPrefer[i][j];
        }
    }

    // Running the stable internship algorithm
    stableInternship(StudentPrefer, CompanyPrefer, n);

    return 0;
}
