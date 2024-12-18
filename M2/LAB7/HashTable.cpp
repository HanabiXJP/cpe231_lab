//66070501038 Phanthach
#include <bits/stdc++.h>

using namespace std;

int HashOrder(vector<string> &HashTable, string Word, int Z)
{
    int n = Word.length();
    int index = 0;

    for (int i = 0; i < n; i++) {
        index += Word[i] - 'A' + 1;
    }

    index = index % Z;

    return index;
}

int main() {
    int Z,n;
    cin >> Z >> n;

    vector<string> HashTable(Z);
    vector<string> Word(n);

    for (int i = 0; i < n; i++) {

        cin >> Word[i];

    }

    for (int i = 0; i < Z; i++) {

        HashTable[i] = "NULL";

    }

    for (int i = 0 ; i < n; i++)
    {
        int num = HashOrder(HashTable, Word[i], Z);

        while (HashTable[num] != "NULL") {
            num++;
        }
        HashTable[num] = Word[i];
    }
    

    for (int i = 0; i < Z; i++) {

        cout << HashTable[i] << " ";
    }

    return 0;
}