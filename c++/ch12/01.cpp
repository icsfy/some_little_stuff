#include <iostream>
#include "cow.h"

int main()
{
  {
    std::cout << "Cow One:\n";
    Cow one;
    one.ShowCow();
//    std::cout << '\n';
  }
  {
    std::cout << "Cow Two:\n";
    Cow two("Best Cow", "water", 94.3);
    two.ShowCow();
//    std::cout << '\n';
    std::cout << "Cow Three:\n";
    Cow three;
    three = two;
    three.ShowCow();
//    std::cout << '\n';
    std::cout << "Cow Four:\n";
    Cow four = Cow(three);
    four.ShowCow();
  }
  {
    std::cout << "Cow Five:\n";
    Cow five = Cow("The last cow", "dancing, fighting", 87.4);
    five.ShowCow();
  }
  std::cout << "Bye.\n";
}
