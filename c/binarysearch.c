// 二分查找
#include <stdio.h>

#define keytype int
#define MAXNUM 10

typedef struct {
  keytype key;
} ELEMTYPE;

int bin_search(ELEMTYPE s[], keytype k, int n)
{
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (s[mid].key == k) {
      printf("searching success");
      return mid;
    } else if (s[mid].key < k)
      low = mid + 1;
    else
      high = mid - 1;
  }
  printf("searching failed");
  return -1;
}

int main(int argc, char const *argv[])
{
  ELEMTYPE s[MAXNUM] = { 16, 22, 33, 38, 51, 52, 79, 91, 105, 112 };

  printf(" for 22, index: %d\n", bin_search(s, 22, MAXNUM));

  return 0;
}
