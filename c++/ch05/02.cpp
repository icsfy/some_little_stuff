#include <iostream>
#include <array>
using namespace std;
const int ArSize = 101;

int main(int argc, char const *argv[]) {
  array<long double, ArSize> factorials;
  factorials[1] = factorials[0] = 1;
  for(int i=2;i<ArSize;i++){
    factorials[i]=factorials[i-1]*i;
  }
  cout.setf(ios_base::fixed/*, /*ios_base::floatfield*/);
  for(int i=0;i<ArSize;i++){
    std::cout << i << "! = " << factorials[i] << '\n';
  }
  return 0;
}
