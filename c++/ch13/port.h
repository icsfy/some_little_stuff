#ifndef PORT_H
#define PORT_H
#include <iostream>
using namespace std;
class Port
{
private:
  char * brand;
  char style[20];  //i.e., tawny, ruby, vintage
  int bottles;
public:
  Port(const char * br = "none", const char * st = "none", int b = 0);
  Port(const Port & p);  //copy constructor
  virtual ~Port() {
    cout << " [Brand: " << brand << "] destoryed.\n";
    delete [] brand;
  }
  Port & operator=(const Port & p);
  Port & operator+=(int b);  //adds b to bottles
  Port & operator-=(int b);  //subtracts b from bottles, if available
  int BottleCount() const { return bottles; }
  virtual void Show() const;
  friend ostream & operator<<(ostream & os, const Port & p);
};
#endif

#ifndef PORT_CPP
#define PORT_CPP
#include <cstring>
Port::Port(const char * br, const char * st, int b)
{
  brand = new char[std::strlen(br)+1];
  std::strcpy(brand, br);
  for(int i=0; st[i] != '\0' && i<20; i++){
    style[i] = st[i];
    i!=19 ? style[i+1]='\0' : style[19]='\0';
  }
  bottles = b;
}
Port::Port(const Port & p)
{
  delete [] brand;
  char * brand = new char[std::strlen(p.brand)+1];
  std::strcpy(brand, p.brand);
  for(int i=0; p.style[i] != '\0' && i<20; i++){
    style[i] = p.style[i];
    i!=19 ? style[i+1]='\0' : style[19]='\0';
  }
  bottles = p.bottles;
}
Port & Port::operator=(const Port & p)
{
  if(this == &p)
    return *this;
  delete [] brand;
  char * brand = new char[std::strlen(p.brand)+1];
  std::strcpy(brand, p.brand);
  for(int i=0; p.style[i] != '\0' && i<20; i++){
    style[i] = p.style[i];
    i!=19 ? style[i+1]='\0' : style[19]='\0';
  }
  bottles = p.bottles;
  return *this;
}
Port & Port::operator+=(int b)
{
  bottles += b;
  return *this;
}
Port & Port::operator-=(int b)
{
  bottles -= b;
  return *this;
}
void Port::Show() const
{
  cout << "    Brand: " << brand << endl;
  cout << "    Kind: " << style << endl;
  cout << "    Bottles: " << bottles << endl;
}
ostream & operator<<(ostream & os, const Port & p)
{
  os << "  " << p.brand << ", " << p.style << ", " << p.bottles << endl;
  return os;
}
#endif

