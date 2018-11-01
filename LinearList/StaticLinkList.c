/**
 * 静态链表
 * 用数组描述的链表
 */
#include <stdio.h>
#define MAXSIZE 1000
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;
typedef struct
{
  ElemType data;
  int cur;  // 游标（Cursor）,为0表示无指向
} Component, StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space)
{
  int i;
  for (i=0; i<MAXSIZE-1; i++)
    space[i].cur = i+1;
  space[MAXSIZE-1].cur = 0;  // 最后一个元素设置为0
  return OK;
}

// 若备用空间链表非空，则返回分配的结点下标，否则返回0
int Malloc_SSL(StaticLinkList space)
{
  int i = space[0].cur;
  if (space[0].cur)
    space[0].cur = space[i].cur;
  return i;
}

int ListLength(StaticLinkList L)
{
  int j = 0;
  int i = L[MAXSIZE - 1].cur;
  while(i)
  {
    i = L[i].cur;
    j++;
  }
  return j;
}

Status ListInsert(StaticLinkList L, int i, ElemType e)
{
  int j, k, l;
  k = MAXSIZE - 1;
  if (i < 1 || i > ListLength(L) + 1)
    return ERROR;
  j = Malloc_SSL(L); // 获得空闲分量的下表
  if (j)
  {
    L[j].data = e;
    for (l = 1; l <= i -1; l++)
      k = L[k].cur;
    L[j].cur = L[k].cur;
    L[k].cur = j;
    return OK;
  }
}

Status ListDelete(StaticLinkList L, int i)
{
  int j, k;
  if (i < 1 || i > ListLength(L) + 1)
    return ERROR;
  k = MAXSIZE - 1;
  for (j = 1; j <= i -1; j++)
    k = L[k].cur;
  j = L[k].cur;
  L[k].cur = L[j].cur;
  Free_SSL(L, j);
  return OK;
}

void Free_SSL(StaticLinkList space, int k)
{
  space[k].cur = space[0].cur;
  space[0].cur = k;
}