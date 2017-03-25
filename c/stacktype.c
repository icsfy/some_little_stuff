// 顺序栈
// 测试数据{1, 2, 3, 4, 5, 6, 7}
#include <stdio.h>

#define MAXNUM 4  // 栈容量
#define true 1
#define false 0
#define ELEMTYPE int  // 栈数据类型

typedef struct {
  ELEMTYPE stack[MAXNUM];  // 用数组存储栈元素
  int top;  // 栈顶指针
} stacktype;

// 初始化
void initiate_stack(stacktype *s)
{
  s->top = -1;  // 栈顶指针置为-1
}

// 入栈
int pushs(stacktype *s, ELEMTYPE x)
{
  if (s->top >= MAXNUM - 1)
    return false;  // 栈满
  s->top++;
  s->stack[s->top] = x;
  return true;
}

// 出栈
ELEMTYPE pops(stacktype *s)
{
  if (s->top < 0)
    return NULL;  // 栈空
  s->top--;
  return s->stack[s->top + 1];
}

// 显示栈内容
void display_s(stacktype *s)
{
  printf("\t栈内容：");
  int p = s->top;
  while (p >= 0) {
    printf("%d ", s->stack[p]);
    p--;
  }
  putchar('\n');
}

// 主函数入口
int main(int argc, char const *argv[])
{
  stacktype s, *sp;  // 声明一个栈变量和栈指针变量
  sp = &s;  // 栈指针变量指向栈变量

  printf("栈初始化，栈容量为%d\n", MAXNUM);
  initiate_stack(sp); display_s(sp);

  printf("将1, 2, 3三个数据依次压栈\n");
  pushs(sp, 1); display_s(sp);
  pushs(sp, 2); display_s(sp);
  pushs(sp, 3); display_s(sp);

  printf("两次出栈操作\n");
  pops(sp); display_s(sp);
  pops(sp); display_s(sp);

  printf("将4, 5, 6三个数据依次压栈\n");
  pushs(sp, 4); display_s(sp);
  pushs(sp, 5); display_s(sp);
  pushs(sp, 6); display_s(sp);

  printf("将数据7压栈\n");
  pushs(sp, 7); display_s(sp);

  return 0;
}
