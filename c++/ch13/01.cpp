#include <iostream>
using namespace std;
#include "classic.h"
void Bravo(const Cd & disk);
int main()
{
  Cd c1("Beatles", "Capitol", 14, 35.5);
  Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
  Cd *pcd = &c1;
  
  cout << "Using object directly:\n";
  std::cout << " [c1]:\n";
  c1.Report();
  std::cout << " [c2]:\n";
  c2.Report();
  
  cout << "\nUsing type cd * pointer to objects:\n";
  std::cout << " [*pointer--c1]:\n";
  pcd->Report();
  std::cout << " [*pointer--c2]:\n";
  pcd = &c2;
  pcd->Report();

  cout << "\nCalling a function with a Cd reference argument:\n";
  std::cout << " [Bravo--c1]:\n";
  Bravo(c1);
  std::cout << " [Bravo--c2]:\n";
  Bravo(c2);
  
  cout << "\nTesting assignment:\n";
  Classic copy;
  copy = c2;
  std::cout << " [copy from c2]:\n";
  copy.Report();
  
  return 0;
}

void Bravo(const Cd & disk)
{
  disk.Report();
}
