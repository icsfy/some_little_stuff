#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;
bool is_palindrome(const string & str);

int main()
{
  cout << "Enter a string: ";
  string temp;
  getline(cin, temp);
  if(is_palindrome(temp))
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
