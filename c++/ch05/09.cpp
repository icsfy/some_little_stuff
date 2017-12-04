#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  string words;
  int count = 0;

  cout << "Enter words (to stop, type the word done):\n";
  cin >> words;
  while (words!="done") {
    ++count;
    cin >> words;
  }
  cout << "You entered a total of " << count << " words." << endl;
  return 0;
}
