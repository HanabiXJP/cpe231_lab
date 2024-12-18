//66070501038 PHANTHACH
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to generate the origin pattern (1D vector)
vector <char> GenerateOriginPattern(int n) 
{
    vector <char> pattern;
    for (int i = 65 ; i < n+65; i++) {

        pattern.push_back(i); // Fill with ASCII starting from 'A'
    }

    return pattern;
}

// Function to input and store the pattern in a 2D vector
vector <string> InputFindPattern(int m, int n) 
{

    vector<string> pattern(m);

    for (int i = 0; i < m; i++) {
        cin >> pattern[i];
    }

    return pattern;

}

int findLargestIncreasingIndex(vector<char> start_Pattern) 
{
    for (int i = start_Pattern.size() - 2; i >= 0; i--) {
        if (start_Pattern[i] < start_Pattern[i+1]) {
            return i;
        }
    }

    return 0;
}

int findLargestGreaterIndex(vector<char> start_Pattern, int i) 
{
    for (int j = start_Pattern.size() - 1; j >= 0; j--) {
        if (start_Pattern[i] < start_Pattern[j]) {
            return j;
        }
    }

    return 0;
}

bool consecutiveIncreasing(vector<char> start_Pattern) 
{
    for (int i = 0; i <= start_Pattern.size() - 2; i++) {

        if (start_Pattern[i] < start_Pattern[i+1]) {
            
            return true;
        }
    }

    return false;
}
bool permutation(vector<char> &start_Pattern) 
{   
    int i = findLargestIncreasingIndex(start_Pattern);
    int j = findLargestGreaterIndex(start_Pattern, i);
    swap(start_Pattern[i], start_Pattern[j]);
    reverse(start_Pattern.begin() + i + 1,start_Pattern.end());

    return consecutiveIncreasing(start_Pattern);
}

void FindTheMatchPattern(vector<char> start_Pattern, vector<string> find_Pattern, int m) 
{
    int counter = 1;
    do {
        string tempPattern(start_Pattern.begin(), start_Pattern.end());

        if (tempPattern == find_Pattern[m]) {
            cout << counter << endl;
        }

        counter++;

    } while(permutation(start_Pattern));

    string tempPattern(start_Pattern.begin(), start_Pattern.end());

    if (tempPattern == find_Pattern[m]) {
            cout << counter << endl;
        }
}

int main() 
{

    int n,m; //pattern & question numbers

    cin >> n >> m;

    vector<char> start_Pattern = GenerateOriginPattern(n);

    vector<string> find_Pattern = InputFindPattern(m,n);

//DEBUG
    for (int i = 0; i < m; i++) {
        FindTheMatchPattern(start_Pattern, find_Pattern, i);
    }

    return 0;
}