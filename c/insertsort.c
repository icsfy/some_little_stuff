// 简单插入排序
#include <stdio.h>

#define keytype int

typedef struct {
  keytype key;
} ELEMTYPE;

//简单插入排序算法
void insertsort(ELEMTYPE x[], int n)
{
  int i, j, k;
  ELEMTYPE a;
  for (i = 0; i < n - 1; i++) {
    a = x[i + 1];
    j = i;
    while (j > -1 && a.key < x[j].key) {
      x[j + 1] = x[j];          // 将元素往后移
      j--;
    }
    x[j + 1] = a;               // 插入a元素

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

  insertsort(x, 10);

  return 0;
}
