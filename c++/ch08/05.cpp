#include <iostream>
using namespace std;

template <class T>
T max5(T arr[]);

int main()
{
  int arri[5] {34, 12, 4, 23, 67};
  double arrd[5] {34.21, 4.2, 56.4, 4.2, 12.3};
  cout << "max arri[]: " << max5(arri) << endl;
  cout << "max arrd[]: " << max5(arrd) << endl;
}

template <class T>
T max5(T arr[])
{
  T max_t = arr[0];
  for(int i=1;i<5;i++){
    if(arr[i]>max_t)
      max_t = arr[i];
  }
  return max_t;
}

