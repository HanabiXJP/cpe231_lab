//66070501038 Phanthach Jiamjaruschot
#include <iostream>
#include <string>

using namespace std;

int main() {

  int minlength;
  int result = 0;
  char bless1, bless2;
  
  string bracetext;

  cin >> bracetext;

  int length = bracetext.size();

  cin >> bless1 >> bless2;

  cin >> minlength;

  for (int i = 0; i < length; i++) {
    for (int j = i; j < length; j++) {
      if (bracetext[i] == bless1 && bracetext[j] == bless2 && (j-i+1) >= minlength) {
        result++;
      }
    }
  }

  cout << result;

  return 0;
}
  
