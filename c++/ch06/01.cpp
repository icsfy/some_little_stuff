#include <iostream>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[]) {
  char ch;
  cout << "Enter: \n";

  while ((ch=cin.get())!='@') {
    if (isdigit(ch))
      continue;
    else if (isupper(ch)) {
      ch=tolower(ch);
    } else if (islower(ch)) {
      ch=toupper(ch);
    }
    cout << ch;
  }
  
  return 0;
}
