#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int reduce(long ar[], int n);

int main()
{
  long a[10] = {4, 2, 7, 2, 4, 7, 7, 4, 5, 9};
  cout << "Unique elements: " << reduce(a, 10) << endl;
  for (long x : a) cout << x << " ";
  cout << endl;
}

int reduce(long ar[], int n)
{
  vector<long> arr(n);
  copy(ar, ar+n, arr.begin());
  cout << "Original: \n";
  for(auto p = arr.begin(); p != arr.end(); ++p) cout << *p << " ";
  cout << endl;
  sort(arr.begin(), arr.end());
  cout << "After sort: \n";
  for(auto p = arr.begin(); p != arr.end(); ++p) cout << *p << " ";
  cout << endl;
  arr.erase(unique(arr.begin(), arr.end()), arr.end());
  cout << "After unique and erase: \n";
  for(auto p = arr.begin(); p != arr.end(); ++p) cout << *p << " ";
  cout << endl;
  copy(arr.begin(), arr.end(), ar);
  return arr.size();
}
