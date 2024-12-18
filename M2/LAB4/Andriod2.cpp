//66070501038 Phanthach
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to generate the origin pattern (1D vector)
vector <char> GenerateOriginPattern(int n) 
{
    vector <char> pattern;
    for (int i = 65; i < n + 65; i++) {
        pattern.push_back(i); // Fill with ASCII starting from 'A'
    }
    return pattern;
}

// Function to input and store the pattern in a 2D vector
vector <string> InputFindPattern(int m) 
{
    vector<string> pattern(m);
    for (int i = 0; i < m; i++) {
        cin >> pattern[i];
    }
    return pattern;
}

// Function to generate the next lexicographical permutation
bool GenerateNextPermutation(vector<char>& start_Pattern) 
{
    // Step 1: Find the largest i such that start_Pattern[i] < start_Pattern[i+1]
    int i = start_Pattern.size() - 2;
    while (i >= 0 && start_Pattern[i] >= start_Pattern[i + 1]) {
        i--;
    }
    
    // If no such i exists, we are at the last permutation
    if (i < 0) {
        return false; // No further permutation is possible
    }
    
    // Step 2: Find the largest j such that start_Pattern[i] < start_Pattern[j]
    int j = start_Pattern.size() - 1;
    while (start_Pattern[i] >= start_Pattern[j]) {
        j--;
    }
    
    // Step 3: Swap start_Pattern[i] and start_Pattern[j]
    swap(start_Pattern[i], start_Pattern[j]);
    
    // Step 4: Reverse the elements from i+1 to the end of the pattern
    reverse(start_Pattern.begin() + i + 1, start_Pattern.end());
    
    return true;
}

// Function to find and print the match for the given patterns
void FindTheMatchPattern(vector<char> start_Pattern, const vector<string>& find_Pattern, int index) 
{
    int counter = 1; // Permutation counter
    string target = find_Pattern[index]; // The pattern we are trying to find
    
    do {
        // Create a string representation from the current permutation
        string tempPattern(start_Pattern.begin(), start_Pattern.end());

        // Check if the current permutation matches the target pattern
        if (tempPattern == target) {
            cout << counter << endl;
            return;
        }
        
        counter++;
    } while (GenerateNextPermutation(start_Pattern)); // Generate the next permutation
    
    // If no match was found
    cout << "Pattern not found!" << endl;
}

int main() 
{
    int n, m; // n: length of pattern, m: number of patterns to find
    cin >> n >> m;

    // Generate the starting pattern (e.g., 'A', 'B', 'C', ...)
    vector<char> start_Pattern = GenerateOriginPattern(n);

    // Input the patterns to be matched
    vector<string> find_Pattern = InputFindPattern(m);

    // Find and print the match for each pattern
    for (int i = 0; i < m; i++) {
        FindTheMatchPattern(start_Pattern, find_Pattern, i);
    }

    return 0;
}
