//66070501038 PHANTHACH
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to check if there is an increasing adjacent pair
bool consecutiveIncreasing(const vector<char>& start_Pattern) {
    for (int i = 0; i < start_Pattern.size() - 1; i++) {
        if (start_Pattern[i] < start_Pattern[i + 1]) return true;
    }
    return false;
}

// Find the largest 'i' such that start_Pattern[i] < start_Pattern[i + 1]
int findLargestIncreasingIndex(const vector<char>& start_Pattern) {
    for (int i = start_Pattern.size() - 2; i >= 0; i--) {
        if (start_Pattern[i] < start_Pattern[i + 1]) return i;
    }
    return -1;  // No such i exists
}

// Find the largest 'j' such that start_Pattern[i] < start_Pattern[j]
int findLargestGreaterIndex(const vector<char>& start_Pattern, int i) {
    for (int j = start_Pattern.size() - 1; j > i; j--) {
        if (start_Pattern[j] > start_Pattern[i]) return j;
    }
    return -1;  // No such j exists
}

// Reverse the substring from 'left' to 'right'
void reverseStr(vector<char>& start_Pattern, int left, int right) {
    while (left < right) {
        swap(start_Pattern[left], start_Pattern[right]);
        left++;
        right--;
    }
}

// Function to calculate the lexicographic position of the given pattern
long long FindTheMatchPattern(const vector<char>& start_Pattern, const string& target_Pattern) {
    vector<char> current_Pattern = start_Pattern;
    long long counter = 1;

    do {
        string tempPattern(current_Pattern.begin(), current_Pattern.end());
        if (tempPattern == target_Pattern) {
            return counter;
        }

        int i = findLargestIncreasingIndex(current_Pattern);
        if (i == -1) break;  // No valid 'i' found, meaning we're at the last permutation

        int j = findLargestGreaterIndex(current_Pattern, i);
        swap(current_Pattern[i], current_Pattern[j]);
        reverseStr(current_Pattern, i + 1, current_Pattern.size() - 1);
        counter++;

    } while (consecutiveIncreasing(current_Pattern));

    return counter;
}

int main() {
    int n, m;  // pattern & question numbers
    cin >> n >> m;

    // Generate initial pattern A to Z (or as long as len)
    vector<char> start_Pattern;
    for (int i = 0; i < n; i++) {
        start_Pattern.push_back('A' + i);
    }

    // Input the target patterns
    vector<string> find_Pattern(m);
    for (int i = 0; i < m; i++) {
        cin >> find_Pattern[i];
    }

    // Find and print the lexicographic position for each target pattern
    for (int i = 0; i < m; i++) {
        cout << FindTheMatchPattern(start_Pattern, find_Pattern[i]) << '\n';
    }

    return 0;
}
