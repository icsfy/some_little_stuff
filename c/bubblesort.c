// 简单冒泡排序
#include <stdio.h>

#define keytype int

typedef struct {
  keytype key;
} ELEMTYPE;

void bubblesort(ELEMTYPE x[], int n)
{
  int i, j, k, flag;
  ELEMTYPE swap;
  flag = 1;
  for (i = 0; i < n - 1 && flag == 1; i++) {
    flag = 0;
    for (j = 0; j < n - i - 1; j++) {
      if (x[j].key > x[j + 1].key) {
        flag = 1;
        swap = x[j];
        x[j] = x[j + 1];
        x[j + 1] = swap;

        // 显示每一趟的排序结果
        for (k = 0; k < n; k++) {
          printf("%d ", x[k].key);
        }
        putchar('\n');

      }
    }
    if (flag == 0)
      return;
  }
}

int main(int argc, char const *argv[])
{
  ELEMTYPE x[10] = { 51, 38, 79, 22, 91, 105, 33, 52, 16, 112 };

  bubblesort(x, 10);

  return 0;
}
