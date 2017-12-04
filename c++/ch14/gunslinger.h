#ifndef GUNSLINGER_H
#define GUNSLINGER_H
#include "person.h"
class Gunslinger : virtual private Person
{
protected:
  double time;
  int trace;
public:
  Gunslinger(const char * fn = "FIRST_NAME(Gunslinger)", const char * ln = "LAST_NAME(Gunslinger)", double ti = 0.0, int tr = 0);
//  Gunslinger(Person & p, double ti = 0.0, int tr = 0);
  double Draw() { return time; };
  void Show() const;
};
#endif

#ifndef GUNSLINGER_CPP
#define GUNSLINGER_CPP
#include <iostream>
Gunslinger::Gunslinger(const char * fn, const char * ln, double ti, int tr) : Person::Person(fn, ln)
{
  time = ti;
  trace = tr;
}
//Gunslinger::Gunslinger(Person & p, double ti, int tr) : Person(p)
//{
//  time = ti;
//  trace = tr;
//}
void Gunslinger::Show() const
{
  Person::Show();
  std::cout << "    Time : " << time << std::endl;
  std::cout << "    Trace: " << trace << std::endl;
}
#endif
