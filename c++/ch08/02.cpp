#include <iostream>
#include <string>
using namespace std;
struct CandyBar {
  string product;
  double mass;
  int hot;
};

void setCB(CandyBar & sCB,const char *p="Millennium Munch",double m=2.85,int h=350);
void showCB(const CandyBar & candyBar);

int main()
{
  
  CandyBar cb;
  setCB(cb);
  showCB(cb);
  setCB(cb,"BHJbjh IN",23.4,345);
  showCB(cb);
}

void setCB(CandyBar & sCB,const char *p,double m,int h)
{
  string temp;
  temp = *p;
  while(*p++)
    temp += *p;
  sCB.product = temp;
  sCB.mass = m;
  sCB.hot = h;
}

void showCB(const CandyBar & candyBar)
{
  using std::cout;
  cout << endl;
  cout << "CandyBar.product: " << candyBar.product << endl;
  cout << "CandyBar.mass: " << candyBar.mass << endl;
  cout << "CandyBar.hot: " << candyBar.hot << endl;
}
