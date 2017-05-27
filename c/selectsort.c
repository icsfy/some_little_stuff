// 简单选择排序
#include <stdio.h>

#define keytype int

typedef struct {
  keytype key;
} ELEMTYPE;

void selectsort(ELEMTYPE x[], int n)
{
  int i, j, k, small;
  ELEMTYPE swap;
  for (i = 0; i < n - 1; i++) {
    small = i;
    for (j = i + 1; j < n; j++) {       // 找出排序码最小的数据元素
      if (x[j].key < x[small].key)
        small = j;
    }
    if (small != i) {           // 把无序区中最小元素与无序区中第一个元素交换
      swap = x[i];
      x[i] = x[small];
      x[small] = swap;
    }
    // 显示每一趟的排序结果
    for (k = 0; k < n; k++) {
      printf("%d ", x[k].key);
    }
    putchar('\n');

  }
}

int main(int argc, char const *argv[])
{
  ELEMTYPE x[10] = { 51, 38, 79, 22, 91, 105, 33, 52, 16, 112 };

  selectsort(x, 10);

  return 0;
}
