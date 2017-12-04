#ifndef BADDUDE_H
#define BADDUDE_H
#include "gunslinger.h"
#include "pokerplayer.h"
class BadDude : public Gunslinger, public PokerPlayer
{
private:
public:
  BadDude(const char * fn = "FIRSTNAME(BadDude)", const char * ln = "LASTNAME(BadDude)", double ti = 0.0, int tr = 0);
  double Gdraw();
  int Cdraw();
  void Show();
};
#endif

#ifndef BADDUDE_CPP
#define BADDUDE_CPP
BadDude::BadDude(const char *fn, const char *ln, double ti, int tr) : Person(fn, ln)
{
  time = ti;
  trace = tr;
}
double BadDude::Gdraw()
{
  return Gunslinger::Draw();
}
int BadDude::Cdraw()
{
  return PokerPlayer::Draw();
}
void BadDude::Show()
{
  Gunslinger::Show();
//  PokerPlayer::Show();
}
#endif
