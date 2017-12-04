#include <iostream>
using namespace std;

int main()
{
  int num1, num2;
  int sum = 0;

  cout << "Enter a small integer: ";
  cin >> num1;
  cout << "Enter a bigger integer: ";
  cin >> num2;

  for(int i = num1; i <= num2; i++){
    sum += i;
  }

  cout << "sum = " << sum << endl;

  return 0;
}
