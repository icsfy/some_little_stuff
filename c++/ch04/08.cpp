#include <iostream>
#include <string>
using namespace std;

struct pizza {
  string company;
  double diameter;
  double mass;
};

int main()
{
  pizza *myPizza = new pizza;

  cout << "Enter your pizza's diameter: ";
  (cin >> myPizza->diameter).get();
  cout << "Enter your pizza's company: ";
  getline(cin, myPizza->company);
  cout << "Enter your pizza's mass: ";
  cin >> myPizza->mass;
  
  cout << endl;
  cout << "Company: " << myPizza->company << endl
       << "Diameter: " << myPizza->diameter << endl
       << "Mass: " << myPizza->mass << endl;
  
  return 0;
}
