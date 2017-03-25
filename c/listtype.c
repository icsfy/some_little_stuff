// 顺序表
// 测试数据{1, 2, 3, 4, 6}
#include <stdio.h>
#include <stdlib.h>  // malloc

#define ELEMTYPE int  // 顺序表中数据类型
#define MAXNUM 5  // 顺序表中最多元素个数
#define true 1
#define false 0

typedef struct {
  ELEMTYPE data[MAXNUM];  // 用数组存储元素
  int num;  // 元素个数计数
} listtype;

// 初始化顺序表
void initiatelist(listtype *l) {
  l->num = 0;  // 顺序表中元素置为0
}

// 插入元素，第一个参数为需要操作的顺序表指针，第二个参数为插入的位置，第三个参数为插入的元素
int insert_l(listtype *l, int i, ELEMTYPE x)
{
  int j;

  // 判断顺序表中元素是否已满
  if (l->num >= MAXNUM) {
    printf("the list is full, can not insert.\n");
    return(false);  // 顺序表元素已满，返回0
  }

  // 判断插入位置是否有效
  if ((i < 0 )||(i > l->num)) {
    printf("i is invalid value.\n");
    return(false);  // 插入位置无效，返回0
  }

  // 将元素逐个后移
  for (j = l->num - 1; j >= i; j--) {
    l->data[j+1] = l->data[j];
  }

  l->data[i] = x;  // 插入元素x
  l->num++;  // 顺序表元素计数加1

  return(true);  // 操作成功，返回1
}

// 删除元素，第一个参数为需要操作的顺序表指针，第二个参数为删除元素的位置
int delete_l(listtype *l, int i)
{
  int j;

  // 判断删除位置是否存在
  if ((i < 0)||(i > l->num - 1)) {
    printf("not exist.\n");
    return(false);  // 删除位置不存在，返回0
  }

  // 将元素逐个前移
  for (j = i + 1; j < l->num; j++) {
    l->data[j-1] = l->data[j];
  }

  l->num--;  // 顺序表元素计数减1

  return(true);  // 操作成功，返回1
}

// 主函数入口
int main(int argc, char const *argv[])
{
  listtype *lp;  // 声明一个顺序表变量指针
  lp = (listtype *)malloc(sizeof(listtype));  // 分配内存
  initiatelist(lp);  // 初始化顺序表
  int i, tmp;  // tmp用于存储临时输入数据

  // 从键盘依次输入数据添加到顺序表中
  for (i = 0; i < MAXNUM; i++) {
    printf("输入第%d个元素：", i+1);
    scanf("%d", &tmp);
    insert_l(lp, i, tmp);
  }

  int k;
  printf("你想删除第几个元素：");
  scanf("%d", &k);

  delete_l(lp, k - 1);  // 删除表中的第k个数据元素(地址从0开始，因此要删除第k个数据元素传值为k-1)

  // 显示操作后顺序表中的内容
  printf("删除第%d个数据后顺序表中内容：", k);
  for (i = 0; i < lp->num; i++) {
    printf("%d ", lp->data[i]);
  }
  putchar('\n');

  free(lp);  // 释放内存

  return 0;
}
