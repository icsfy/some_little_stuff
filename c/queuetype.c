// 循环队列
// 测试数据{1, 2, 3, 4, 5, 6, 7}
#include <stdio.h>

#define MAXNUM 4  // 队列容量
#define true 1
#define false 0
#define ELEMTYPE int  // 队列数据类型

typedef struct {
  ELEMTYPE queue[MAXNUM + 1];  // 用数组存储队列元素
  int front;  // 队头指针
  int rear;  // 队尾指针
} queuetype;

// 初始化队列
void initiate_queue(queuetype *q)
{
  q->front = q->rear = 0;  // 队头指针和队尾指针都置为零
}

// 入队列操作
int enter_q(queuetype *q, ELEMTYPE x)
{
  if (((q->rear) + 1) % (MAXNUM + 1) == q->front)
    return false;  // 队列已满
  q->rear = (q->rear + 1) % (MAXNUM + 1);
  q->queue[q->rear] = x;
  return true;
}

// 出队操作
ELEMTYPE delete_q(queuetype *q)
{
  if (q->rear == q->front)
    return NULL;  // 队列已空
  q->front = (q->front + 1) % (MAXNUM + 1);
  return q->queue[q->front];
}

// 显示队列内容
void display_q(queuetype *q)
{
  printf("\t队列内容：");
  int p = q->front;
  while (p != q->rear) {
    p = (p + 1) % (MAXNUM + 1);
    printf("%d ", q->queue[p]);
  }
  putchar('\n');
}

int main(int argc, char const *argv[])
{
  queuetype q, *qp;  // 声明一个队列变量和一个队列指针变量
  qp = &q;  // 队列指针变量指向队列变量

  printf("初始化队列, 队列容量为%d\n", MAXNUM);
  initiate_queue(qp); display_q(qp);

  printf("将1, 2, 3三个数据依次做入队操作\n");
  enter_q(qp, 1); display_q(qp);
  enter_q(qp, 2); display_q(qp);
  enter_q(qp, 3); display_q(qp);

  printf("做两次出队操作（1, 2出队）\n");
  delete_q(qp); display_q(qp);
  delete_q(qp); display_q(qp);

  printf("将4, 5, 6三个数据依次做入队操作\n");
  enter_q(qp, 4); display_q(qp);
  enter_q(qp, 5); display_q(qp);
  enter_q(qp, 6); display_q(qp);

  printf("将数据7做入队操作\n");
  enter_q(qp, 7); display_q(qp);

  return 0;
}
