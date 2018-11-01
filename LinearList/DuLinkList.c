/**
 * 线性表双向链式存储结构
 */
#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;
typedef struct DuLNode
{
  ElemType data;
  struct DuLNode *prior;
  struct DuLNode *next;
} DuLNode, *DuLinkList;

Status GetElem(DuLinkList L, int i, ElemType *e)
{
  int j;
  DuLinkList p;
  p = L->next;  // 让p指向链表L第一个结点
  j = 1;        // j 为计数器
  while (p && j < i)
  {
    p = p->next;
    ++j;
  }
  if (!p || j > i)
    return ERROR;
  *e = p->data;     // 取第i个结点的数据
  return OK;
}

Status ListInsert(DuLinkList *L, int i, ElemType e)
{
  int j;
  DuLinkList p, s;
  p = *L;
  j = 1;
  while (p && j < i) // 寻找第i-1个结点
  {
    p = p->next;
    ++j;
  }
  if (!p || j > i)
    return ERROR;
  s = (DuLinkList)malloc(sizeof(DuLNode));
  s->prior = p;        // 把p赋值给是的前驱
  s->next = p->next;   // 将p的后继结点赋值给s的后继结点
  p->next->prior = s;  // 把s赋值给p->next的前驱
  p->next = s;         // 把s赋值给p的后继
  return OK;
}

Status ListDelete(DuLinkList *L, int i, ElemType *e)
{
  int j;
  DuLinkList p, q;
  p = *L;
  j = 1;
  while (p->next && j < i) // 寻找第i-1个结点
  {
    p = p->next;
    ++j;
  }
  if (!(p->next) || j > i)
    return ERROR;         // 第i个结点不存在

  p->prior->next = p->next;
  p->next->prior = p->prior;
  *e = p->data;
  // q = p->next;
  // p->next = q->next;      // 将q的后继付给p的后继
  // *e = q->data;           // 将q结点中数据赋值给e
  // free(q);                // 释放q内存
  return OK;
}

int main(int argc, char const *argv[])
{
  printf("hello world\n");
  return 0;
}