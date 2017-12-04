#include <iostream>
#include <array>
using namespace std;

int main()
{
  array<double, 4> score;
  
  cout << "first time for 40m score: ";
  cin >> score[0];
  cout << "second time for 40m score: ";
  cin >> score[1];
  cout << "third time for 40m score: ";
  cin >> score[2];
  
  score[3] = (score[0] + score[1] + score[2])/3.0;

  cout << "average score: " << score[3] << endl;
}
