/**
 * 顺序栈
 * 两栈共享空间
 */
#include <stdio.h>
#define MAXSIZE 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int SElemType;
typedef int Status;
typedef struct
{
  SElemType data[MAXSIZE];
  int top1;   // 栈1顶指针, -1 空栈
  int top2;   // 栈2指正
} SqDoubleStack;

Status Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
  if (S->top1+1 == S->top2 ) // 栈满,两栈相遇 【123-top1 top2-789】
    return ERROR;
  if (stackNumber == 1) // 栈1 有元素进栈
    S->data[++S->top1] = e;
  else if (stackNumber == 2)
    S->data[--S->top2] = e;
  return OK;
}

Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
  if (stackNumber == 1)
  {
    if (S->top1 == -1)
      return ERROR;
    *e = S->data[S->top1--];
  }
  else if (stackNumber == 2)
  {
    if (S->top2 == MAXSIZE)
      return ERROR;
    *e = S->data[S->top2++];
  }
  return OK;
}

int main(int argc, char const *argv[])
{
  printf("hello world\n");
  return 0;
}