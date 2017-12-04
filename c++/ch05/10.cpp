#include <iostream>
using namespace std;

int main(){
  cout << "Enter number of rows: ";
  int rows;
  cin >> rows;

  for(int i=1; i<=rows; i++){
    for(int j=rows; j>i; j--){
      cout << ".";
    }
    for(int k=0; k<i; k++){
      cout << "*";
    }
    std::cout << '\n';
  }
}
