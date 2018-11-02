/**
 * 链栈
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int SElemType;
typedef int Status;
typedef struct StackNode
{
  SElemType data;
  struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct LinkStack
{
  LinkStackPtr top;
  int count;
} LinkStack;

Status Push(LinkStack *S, SElemType e)
{
  LinkStackPtr s = (LinkStackPtr) malloc(sizeof(StackNode));
  s->data = e;
  s->next = S->top; // 把当前的栈顶元素赋值给新结点的直接后继
  S->top = s;       // 将新结点s赋值给栈顶指针
  S->count++;
  return OK;
}

Status Pop(LinkStack *S, SElemType *e)
{
  LinkStackPtr p;
  if (S->top == NULL)
    return ERROR;
  *e = S->top->data;
  p = S->top;
  S->top = S->top->next;
  free(p);
  S->count--;
  return OK;
}

// 栈递归应用，斐波那契数列（Fibonacci）
int Fbi(int i)
{
  if (i < 2)
    return i == 0 ? 0 : i;
  return Fbi(i-1) + Fbi(i-2);
}

int main(int argc, char const *argv[])
{
  int i;
  for(int i = 0; i < 40; i++)
    printf("%d ", Fbi(i));
  return 0;
}
