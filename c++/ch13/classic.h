#ifndef CLASSIC_H
#define CLASSIC_H
#include "cd.h"
class Classic : public Cd
{
private:
  char * product;
public:
  Classic(const char * s, const char * s1, const char *s2, int n, double x);
  Classic(const Classic & c);
  Classic();
  ~Classic();
  void Report() const;
  Classic & operator=(const Classic & c);
};
#endif

#ifndef CLASSIC_CPP
#define CLASSIC_CPP
#include <iostream>
#include <cstring>
Classic::Classic(const char * s, const char * s1, const char *s2, int n, double x) : Cd(s1, s2, n, x)
{
  product = new char[std::strlen(s)+1];
  std::strcpy(product, s);
}
Classic::Classic(const Classic & c) : Cd(c)
{
  product = new char[std::strlen(c.product)+1];
  std::strcpy(product, c.product);
}
Classic::Classic() : Cd()
{
  const char * s = "PRODUCT";
  product = new char[std::strlen(s)+1];
  std::strcpy(product, s);
}
Classic::~Classic()
{
//  std::cout << " [" << product << "] destoryed.\n";
  delete [] product;
}
void Classic::Report() const
{
  std::cout << "                  Product: " << product << std::endl;
  Cd::Report();
}
Classic & Classic::operator=(const Classic & c)
{
  if(this == &c)
    return *this;
  Cd::operator=(c);
  delete [] product;
  product = new char[std::strlen(c.product)+1];
  std::strcpy(product, c.product);
  return *this;
}
#endif
