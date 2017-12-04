#include <iostream>
#include "vintageport.h"
void port_fun(Port & rp);
int main()
{
  Port p1("brand 1", "tawny", 8);
  VintagePort vp1("vbrand 1", "ruby", 12, "The Noble", 1984);
std::cout << "p1.Show():\n";
  p1.Show();
std::cout << "os << p1:\n";
  std::cout << p1;
std::cout << "vp1.Show():\n";
  vp1.Show();
std::cout << "os << vp1:\n";
  std::cout << vp1;
std::cout << "Call function:\n";
std::cout << " p1:\n";
  port_fun(p1);
std::cout << " vp1:\n";
  port_fun(vp1);
std::cout << "Testing assignment:\n";
  VintagePort copy;
std::cout << " copy.Show(): (copy vp1)\n";
  copy = vp1;
  copy.Show();
}

void port_fun(Port & rp)
{
  rp.Show();
}
