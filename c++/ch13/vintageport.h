#ifndef VINTAGEPORT_H
#define VINTAGEPORT_H
#include "port.h"
class VintagePort : public Port  //style necessarily = "vintage"
{
private:
  char * nickname;
  int year;
public:
  VintagePort();
  VintagePort(const char * br, const char * st, int b, const char * nn, int y);
  VintagePort(const VintagePort & vp);
  ~VintagePort() {
    cout << " [Nickname: " << nickname << "] destoryed.\n";
    delete [] nickname;
  }
  VintagePort & operator=(const VintagePort & vp);
  void Show() const;
  friend ostream & operator<<(ostream & os, const VintagePort & vp);
};
#endif

#ifndef VINTAGEPORT_CPP
#define VINTAGEPORT_CPP
#include <cstring>
VintagePort::VintagePort() : Port()
{
  const char * nn = "NICKNAME";
  nickname = new char[std::strlen(nn)+1];
  std::strcpy(nickname, nn);
  year = 0;
}
VintagePort::VintagePort(const char * br, const char * st, int b, const char * nn, int y) : Port(br, st, b)
{
  nickname = new char[std::strlen(nn)+1];
  std::strcpy(nickname, nn);
  year = y;
}
VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
  delete [] nickname;
  char * nickname = new char[std::strlen(vp.nickname)+1];
  std::strcpy(nickname, vp.nickname);
  year = vp.year;
}
VintagePort & VintagePort::operator=(const VintagePort & vp)
{
  if(this == &vp)
    return *this;
  Port::operator=(vp);
  delete [] nickname;
  char * nickname = new char[std::strlen(vp.nickname)+1];
  std::strcpy(nickname, vp.nickname);
  year = vp.year;
  return *this;
}
void VintagePort::Show() const
{
  Port::Show();
  std::cout << "    Nickname: " << nickname << std::endl;
  std::cout << "    Year: " << year << endl;
}
ostream & operator<<(ostream & os, const VintagePort & vp)
{
  os << (const Port &)vp;
  os << "  " << vp.nickname << ", " << vp.year << '\n';
  return os;
}
#endif
