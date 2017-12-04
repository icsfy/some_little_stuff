#include <iostream>
#include "baddude.h"

int main()
{
std::cout << "Person:\n";
  Person test0;
  test0.Show();
std::cout << "Gunslinger:\n";
  Gunslinger test1;
  test1.Show();
std::cout << "PokerPlayer:\n";
  PokerPlayer test2;
  test2.Show();
  std::cout << "   Draw(): " << test2.Draw() << std::endl;
std::cout << "BadDude:\n";
  BadDude test;
  test.Show();
  std::cout << "  Gdraw(): " << test.Gdraw() << std::endl;
  std::cout << "  Cdraw(): " << test.Cdraw() << std::endl;
}
