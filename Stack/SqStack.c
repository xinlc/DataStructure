/**
 * 顺序栈
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
  int top;   // 栈顶指针, -1 空栈
} SqStack;

Status Push(SqStack *S, SElemType e)
{
  if (S->top == MAXSIZE -1 ) // 栈满
    return ERROR;
  S->top++;
  S->data[S->top] = e;
  return OK;
}

Status Pop(SqStack *S, SElemType *e)
{
  if (S->top == -1)
    return ERROR;

  *e = S->data[S->top];
  S->top--;
  return OK;
}

int main(int argc, char const *argv[])
{
  printf("hello world\n");
  return 0;
}