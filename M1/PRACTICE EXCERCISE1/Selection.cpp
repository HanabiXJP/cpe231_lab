#include <iostream>

using namespace std;

void stableSelectionSort(int score[], int n, int number[]) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        // Find the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (score[j] > score[max_idx]) {
                max_idx = j;
            }
        }

        // Move the minimum element to its correct position
        int maxScore = score[max_idx];
        int maxNumber = number[max_idx];
        // Shift elements to the right to make space for the minimum element
        while (max_idx > i) {
            score[max_idx] = score[max_idx - 1];
            number[max_idx] = number[max_idx - 1];
            max_idx--;
        }

        // Place the minimum element at its correct position
        score[i] = maxScore;
        number[i] = maxNumber;
    }
}

void printNumber(int number[], int n) {
    for (int i = 0; i < n; i++) {
        cout << number[i] << endl;
    }
}

int main() {
    int n;
    cin >> n;

    int number[n], score[n];

    for (int i = 0; i < n; i++) {
        cin >> number[i] >> score[i];
    }

    stableSelectionSort(score, n, number);

    cout << "OUTPUT" << endl;
    printNumber(number, n);

    return 0;
}
