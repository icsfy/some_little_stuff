#include <iostream>

//#include <move.h>
#ifndef MOVE_H
#define MOVE_H
class Move
{
  private:
    double x;
    double y;
  public:
    Move(double a=0, double b=0);  //set x, y to a, b
    void showmove() const;  //shows current x, y values
    Move add(const Move & m) const;
    void reset(double a=0, double b=0);  //reset x, y to a, b
};
#endif

//#include <move.c>
#ifndef MOVE_C
#define MOVE_C
Move::Move(double a, double b)
{
  x=a; y=b;
}
void Move::showmove() const
{
  std::cout << "x=" << x << ", " << "y=" << y << std::endl;
}
Move Move::add(const Move & m) const
{
  Move nmove;
  nmove.x = x + m.x;
  nmove.y = y + m.y;
  return nmove;
}
void Move::reset(double a, double b)
{
  x=a; y=b;
}
#endif

int main()
{
  Move one;
  one.showmove();
  Move two(2,3);
  two.showmove();
  Move three = one.add(two);
  three.showmove();
  three.reset();
  three.showmove();
}

