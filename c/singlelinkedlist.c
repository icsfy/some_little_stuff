// 单链表
// 测试数据{1, 2, 2, 3, 4, 6, 6}
#include <stdio.h>
#include <stdlib.h>  // malloc

#define ELEMTYPE int  // 单链表中数据类型

typedef struct node1 {
  ELEMTYPE data;  // 数据元素
  struct node1 *next;  // 节点指针
} node;

// 初始化单链表
void initiate_sl(node **h)
{
  *h = (node *)malloc(sizeof(node));  // 分配内存
  (*h)->data = 0;  // 初始化单链表元素个数置为0
  (*h)->next = NULL;  // 初始化单链表节点
}

// 插入元素
void insert_sl(node *h, int i, ELEMTYPE x)
{
  node *p, *t;
  int j = 0;
  p = h;

  // 寻找第i-1个节点
  while (p != NULL && j < i-1) {
    p = p->next;
    j++;
  }

  if (j != i-1) {
    printf("i is invalid.\n");
    return;  // 插入位置i不合理，返回
  }

  t = (node *)malloc(sizeof(node));  // 分配新节点
  t->data = x;  // 节点数据域赋值
  t->next = p->next;
  p->next = t;  // 链的重新连接
  h->data++;  // 插入元素成功，元素个数计数加1
}

// 删除元素，第一个参数为需要操作的单链表指针，第二个参数为删除元素的位置
void delete_sl(node *h, int i)
{
  node *p, *s;
  int j = 0;
  p = h;

  // 寻找第i-1个节点
  while (p != NULL && j < i-1) {
    p = p->next;
    j++;
  }

  if (j != i-1) {
    printf("i is invalid.\n");
    return;  // 删除位置i不合理，返回
  }

  s = p->next;
  p->next = s->next;  // 链的重新连接
  free(s);  // 释放被删除节点的存储空间
  h->data--;  // 单链表元素个数计数减1
}

// 单链表的访问
node *access(node *h, int i)
{
  node *p;
  int j = 0;
  p = h;

  while (p->next != NULL && j < i) {
    p = p->next;
    j++;
  }

  if (p != NULL && j == i)
    return p;
  return NULL;
}

// 单链表的释放
void freelist(node *h) {
  node *p, *s;
  p = h;
  while ((s = p->next) != NULL) {
    free(p);
    p = s;
  }
  free(s);
}

// 主函数入口
int main(int argc, char const *argv[])
{
  node *slp;  // 声明一个节点指针变量
  initiate_sl(&slp);  // 初始化空链表
  int i, tmp;  // tmp用于存储临时输入数据

  // 从键盘依次输入数据添加到单链表中
  for (i = 1; i <= 7; i++) {
    printf("第%d个元素：", i);
    scanf("%d", &tmp);
    insert_sl(slp, i, tmp);
  }
  printf("单链表长度：%d\n", slp->data);

  printf("数据为3的节点位置：");
  for (i = 1; i <= slp->data; i++) {
    if (access(slp, i)->data == 3)
      printf("%d ", i);
  }

  printf("\n数据为7的节点位置：");
  for (i = 1; i <= slp->data; i++) {
    if (access(slp, i)->data == 7)
      printf("%d ", i);
  }

  // 删除相邻重复节点
  for (i = 1; i <= slp->data; i++) {
    if (access(slp, i+1) != NULL)
      if (access(slp, i)->data == access(slp, i+1)->data)
        delete_sl(slp, i+1);
  }

  printf("\n删除相邻重复节点后链表内容：");
  for (i = 1; i <= slp->data; i++) {
    printf("%d ", access(slp, i)->data);
  }
  putchar('\n');

  freelist(slp);  // 释放链表

  return 0;
}
