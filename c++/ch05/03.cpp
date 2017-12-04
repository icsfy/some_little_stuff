#include <iostream>
using namespace std;

int main()
{
  int num, sum=0;
  cout << "Enter a integer: ";
  cin >> num;
  while (num) {
    sum += num;
    cout << "sum = " << sum << endl;
    cout << "Enter next integer(Enter 0 to quit): ";
    cin >> num;
  }
}
