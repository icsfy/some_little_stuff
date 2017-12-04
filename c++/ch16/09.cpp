#include <iostream>
#include <ctime>
struct iBig
{
  double val[10000];
};
int main()
{
  using std::cin;
  using std::cout;
  clock_t start = clock();
  iBig *a = new iBig;
  for (int i = 0; i < 1000; i++) {
    a->val[i] = i;
    for (int j = 0; j < 1000; j++)
      for (int k = 0; k < 1000; k++)
        a->val[i] += k + j;
  }
  delete a;
  clock_t end = clock();
  cout << "cost " << (double)(end - start)/CLOCKS_PER_SEC << " seconds.\n";
}
