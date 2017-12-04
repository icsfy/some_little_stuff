#include <iostream>
#include <string>
using namespace std;

struct Car {
  string product;
  int year;
};

int main(int argc, char const *argv[]) {
  cout << "How many cars do you wish to catalog? ";
  int cars;
  (cin >> cars).get();

  Car *mycars = new Car [cars];
  for(int i=0; i<cars; i++){
    cout << "Car #" << i+1 << ":\n";
    cout << "Please enter the make: ";
    getline(cin, mycars[i].product);
    cout << "Please enter the year made: ";
    (cin >> mycars[i].year).get();
  }
  cout << "Here is your collection:\n";
  for(int i=0; i<cars; i++){
    cout << mycars[i].year << " " << mycars[i].product << endl;
  }
  delete [] mycars;

  return 0;
}
