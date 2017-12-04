#ifndef POKERPLAYER_H
#define POKERPLAYER_H
#include "person.h"
class PokerPlayer : virtual public Person
{
private:
//  int random_num;
public:
  PokerPlayer(const char*fn = "FIRST_NAME(PokerPlayer)", const char*ln = "LAST_NAME(PokerPlayer)");
  int Draw();
  void Show() { Person::Show(); }
};
#endif

#ifndef POKERPLAYER_CPP
#define POKERPLAYER_CPP
#include <cstdlib>
#include <ctime>
#include "person.h"
PokerPlayer::PokerPlayer(const char * fn, const char * ln) : Person(fn, ln)
{
}
int PokerPlayer::Draw()
{
  {
  std::srand(std::time(0));
  return rand()%52+1;
  }
//  random_num = rand() % 52 + 1;
//  return random_num;
}
#endif
