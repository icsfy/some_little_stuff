// 顺序查找
#include <stdio.h>

#define keytype int
#define MAXNUM 10

typedef struct {
  keytype key;
} ELEMTYPE;

int seq_search(ELEMTYPE s[], keytype k, int n)
{
  int i;
  s[n].key = k;                 // 设置监视哨
  i = 0;
  while (s[i].key != k)
    i++;
  if (i < n) {
    printf("searching success");
    return i;
  }
  printf("searching failed");
  return -1;
}

int main(int argc, char const *argv[])
{
  ELEMTYPE s[MAXNUM + 1] = { 16, 22, 33, 38, 51, 52, 79, 91, 105, 112 };

  printf(" for 52, index: %d\n", seq_search(s, 52, MAXNUM));

  printf(" for 36, index: %d\n", seq_search(s, 36, MAXNUM));

  return 0;
}
