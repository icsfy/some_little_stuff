#include <iostream>
using namespace std;

int main()
{
  int count = 0;
  char ch;
  cout << "Enter your message ($ to quit):\n";
//  while(ch=cin.get() != '$')
//    count++;
//  cin.putback('$');
  while(cin.peek() != '$') {
    cin.get();
    count++;
  }
  string s;
  getline(cin, s);
  cout << "There are " << count << " characters before '$'\n";
  cout << "And remain these characters: " << s << endl;
}
