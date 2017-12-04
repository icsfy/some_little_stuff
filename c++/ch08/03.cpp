#include <iostream>
#include <string>
#include <cctype>
using namespace std;
void toUpperStr(string & str);

int main()
{
  cout << "Enter a string (q to quit): ";
  string strin;
  getline(cin, strin);
  while(strin != "q" ){
    toUpperStr(strin);
    cout << strin << endl;
    cout << "Next string (q to quit): ";
    getline(cin, strin);
  }
  cout << "Bye.\n";
}

void toUpperStr(string & str)
{
  for(int i=0;str[i];i++){
    if(isalpha(str[i]))
      str[i] = toupper(str[i]);
  }
}
