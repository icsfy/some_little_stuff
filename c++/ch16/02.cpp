#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <cctype>
using namespace std;
bool is_palindrome(const string & str);
string toLower(const string & s);

int main()
{
  cout << "Enter a string: ";
  string temp;
  getline(cin, temp);
  if(is_palindrome(toLower(temp)))
    cout << " [ " << temp << " ] is a palindrome.\n";
  else 
    cout << " [ " << temp << " ] is not a palindrome.\n";
}

bool is_palindrome(const string & str)
{
  string orig = str;
  string rstr = orig;
  reverse(rstr.begin(), rstr.end());
  if (str != rstr)
    return false;
  return true;
  
}

string toLower(const string & s)
{
  string temp = s;
  int i,j;
  for (i = 0, j = 0; s[i] != '\0'; i++) {
    if(isalpha(s[i])) {
      cout << s[i] << " is alpha.\n";
      temp[j] = tolower(s[i]);
      ++j;
    }
  }
  string pstr = string(temp.begin(),temp.begin()+j);
//  copy(temp.begin(), temp.begin()+j,pstr.begin());
  cout << pstr << endl;
  return pstr;
}
