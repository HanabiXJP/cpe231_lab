    //66070501038 Phanthach Jiamjaruschot
    #include <iostream>
    #include <string>
    #include <cmath>
    #include <vector>
    #include <algorithm>

    using namespace std;

    vector<bool> binary(int nBit, int n) {
        vector<bool> bin(nBit, 0);
        int i = nBit - 1;
        while (n && i >= 0) {
            bin[i] = n % 2;
            n /= 2;
            i--;    
        }
        return bin;
    }

    int isPalindrome(vector<char> LetterSet) {

        // Convert vector<char> back to string
        string Normal(LetterSet.begin(), LetterSet.end());

        string Reverse = Normal;

        // Reverse the string
        reverse(Reverse.begin(), Reverse.end());

        if (Normal == Reverse) {
            return 1;
        }

        else {
            return 0;
        }

    }

    int main() {

        int len;
        int count = 0;
        string name;

        cin >> name;

        // Convert string to vector<char>
        vector<char> vecname(name.begin(), name.end());

        // Find vector length
        len = vecname.size();

        // Calculate 2^len    
        int set = pow(2, len);
        int i = 2;

        // Vector to store unique palindromes
        vector<string> uniquePalindromes;

        for (int i = 1; i < set; i++) {
            vector<bool> BinarySet = binary(len, i);
            vector<char> LetterSet;

            // Print characters based on binary set
            for (int j = 0; j < len; j++) {

                // for (bool ch : BinarySet) {
                // cout << ch;
                // }
                // cout << endl;
                if (BinarySet[j] == 1) {
                    LetterSet.push_back(vecname[j]);
                }
            }

            if (isPalindrome(LetterSet) == 1 && LetterSet.size() != 1) {
                string palindrome(LetterSet.begin(), LetterSet.end());

                // Check if the palindrome is unique    
                if (find(uniquePalindromes.begin(), uniquePalindromes.end(), palindrome) == uniquePalindromes.end()) {
                    uniquePalindromes.push_back(palindrome);
                    // cout << palindrome << endl;
                    count++;
                }
            }


            // for (char ch : LetterSet) {
            //     cout << ch;
            // }
            // cout << endl;

        }

        cout << count;
        return 0;
    }