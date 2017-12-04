#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

template <class T>
int reduce(T ar[], int n);

int main()
{
  cout << ">>long test: \n";
  long a[10] = {4, 2, 7, 2, 4, 7, 7, 4, 5, 9};
  cout << "Unique elements: " << reduce(a, 10) << endl;
  for (long x : a) cout << x << " ";
  cout << endl << endl;
  cout << ">>string test: \n";
  string s[10] = {"hello", "good", "ok", "hello", "many", "many", "funny", "good", "love", "end"};
  cout << "Unique elements: " << reduce(s, 10) << endl;
  for (string x : s) cout << x << " ";
  cout << endl;
}

template <class T>
int reduce(T ar[], int n)
{
  vector<T> arr(n);
  copy(ar, ar+n, arr.begin());
  cout << "\tOriginal: \n";
  for(auto p = arr.begin(); p != arr.end(); ++p) cout << *p << " ";
  cout << endl;
  sort(arr.begin(), arr.end());
  cout << "\tAfter sort: \n";
  for(auto p = arr.begin(); p != arr.end(); ++p) cout << *p << " ";
  cout << endl;
  arr.erase(unique(arr.begin(), arr.end()), arr.end());
  cout << "\tAfter unique and erase: \n";
  for(auto p = arr.begin(); p != arr.end(); ++p) cout << *p << " ";
  cout << endl;
  copy(arr.begin(), arr.end(), ar);
  return arr.size();
}
