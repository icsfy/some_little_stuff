#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char const *argv[]) {
  char words[20];
  int count = 0;

  cout << "Enter words (to stop, type the word done):\n";
  cin >> words;
  while (strcmp(words,"done")) {
    ++count;
    cin >> words;
  }
  cout << "You entered a total of " << count << " words." << endl;
  return 0;
}
