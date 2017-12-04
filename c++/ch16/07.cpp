#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
vector<int> Lotto(int all, int num);

void show(int n)
{
  cout << n << " ";
}

int main()
{
  vector<int> winners;
  winners = Lotto(51, 6);
  for_each(winners.begin(), winners.end(), show);
  cout << endl;
}

vector<int> Lotto(int all, int num)
{
  srand(time(0));
  vector<int> randall(all),winner(num);
  auto r = randall.begin();
  for (int i = 0; r != randall.end(); r++) {
    *r = ++i;
  }
  random_shuffle(randall.begin(), randall.end());
//  for_each(randall.begin(), randall.end(), show);
//  cout << endl;
  r = randall.begin();
  for(auto p = winner.begin(); p != winner.end(); p++, r++) *p = *r;
  return winner;
}
