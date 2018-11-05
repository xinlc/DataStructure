/**
 * 队列
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int QElemType;
typedef int Status;
typedef struct
{
  QElemType data[MAXSIZE];
  int front; // 头指针
  int rear;  // 尾指针，若列队不为空，指向队列尾元素的下一个位置。
} SqQueue;

Status InitQueue(SqQueue *Q)
{
  Q->front = 0;
  Q->rear = 0;
  return OK;
}

int QueueLength(SqQueue Q)
{
  return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

Status EnQueue(SqQueue *Q, QElemType e)
{
  if ((Q->rear+1) % MAXSIZE == Q->front) // 队列已满
    return ERROR;
  Q->data[Q->rear] = e;
  Q->rear = (Q->rear+1) % MAXSIZE;  // rear 指针向后移一位置, 若到最后则转到数组头部
  return OK;
}

Status DeQueue(SqQueue *Q, QElemType *e)
{
  if (Q->front == Q->rear) // 队列为空
    return ERROR;
  *e = Q->data[Q->front];
  Q->front = (Q->front+1) % MAXSIZE; // front 指针向后移动一位, 若到最后则转到数组头部
  return OK;
}