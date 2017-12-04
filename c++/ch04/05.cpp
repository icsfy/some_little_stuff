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
  CandyBar snack = {
    "Mocha Munch",
    2.3,
    350
  };

  cout << "snack.brand: " << snack.brand << endl
       << "snack.mass: " << snack.mass << endl
       << "snack.calorie: " << snack.calorie << endl;

  return 0;
}
