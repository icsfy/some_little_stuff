#include <iostream>
#include <string>
using namespace std;

struct CandyBar {
  string brand;
  double mass;
  int calorie;
};

int main()
{
  CandyBar *snack = new CandyBar[3];
  snack[0] = {"Mocha Munch", 2.3, 350};
  snack[1] = {"candy bar", 5.43, 476};
  snack[2] = {"hjc ufibc", 7.84, 683};

  cout << "snack[0].brand: " << snack[0].brand << endl
       << "snack[0].mass: " << snack[0].mass << endl
       << "snack[0].calorie: " << snack[0].calorie << endl;
  cout << "snack[1].brand: " << snack[1].brand << endl
       << "snack[1].mass: " << snack[1].mass << endl
       << "snack[1].calorie: " << snack[1].calorie << endl;
  cout << "snack[2].brand: " << snack[2].brand << endl
       << "snack[2].mass: " << snack[2].mass << endl
       << "snack[2].calorie: " << snack[2].calorie << endl;
  
  delete [] snack;

  return 0;
}
