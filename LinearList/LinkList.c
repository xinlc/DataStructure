/**
 * 线性表链式存储结构
 */
#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;
typedef struct Node
{
  ElemType data;
  struct Node *next;
} Node;
typedef struct Node *LinkList;

Status GetElem(LinkList L, int i, ElemType *e)
{
  int j;
  LinkList p;
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

Status ListInsert(LinkList *L, int i, ElemType e)
{
  int j;
  LinkList p, s;
  p = *L;
  j = 1;
  while (p && j < i) // 寻找第i-1个结点
  {
    p = p->next;
    ++j;
  }
  if (!p || j > i)
    return ERROR;
  s = (LinkList)malloc(sizeof(Node));
  s->data = e;
  s->next = p->next;   // 将p的后继结点赋值给s的后继结点
  p->next = s;         // 将s赋值给p的后继结点
  return OK;
}

Status ListDelete(LinkList *L, int i, ElemType *e)
{
  int j;
  LinkList p, q;
  p = *L;
  j = 1;
  while (p->next && j < i) // 寻找第i-1个结点
  {
    p = p->next;
    ++j;
  }
  if (!(p->next) || j > i)
    return ERROR;         // 第i个结点不存在
  q = p->next;
  p->next = q->next;      // 将q的后继付给p的后继
  *e = q->data;           // 将q结点中数据赋值给e
  free(q);                // 释放q内存
  return OK;
}

// 整表创建，头插法
void CreateListHead(LinkList *L, int n)
{
  LinkList p;
  int i;
  srand(time(0));  // 初始化随机数种子
  *L = (LinkList) malloc(sizeof(Node));
  (*L)->next = NULL;        // 先建立一个带头结点的单连表
  for (i=0; i<n; i++)
  {
    p = (LinkList) malloc(sizeof(Node));   // 生成新结点
    p->data = rand() % 100 + 1;     // 随机生成100以内的数字
    p->next = (*L)->next;
    (*L)->next = p;         // 插入到表头
  }
}

// 尾插法
void CreateListTail(LinkList *L, int n)
{
  LinkList p, r;
  int i;
  srand(time(0));  // 初始化随机数种子
  *L = (LinkList) malloc(sizeof(Node));
  r = *L;       // r为指向尾部的结点
  for (i=0; i<n; i++)
  {
    p = (LinkList) malloc(sizeof(Node));   // 生成新结点
    p->data = rand() % 100 + 1;     // 随机生成100以内的数字
    r->next = p;          // 将表尾终端结点的指针指向新结点
    r = p;                // 将当前的新结点定义为尾结点
  }
  r->next = NULL;         // 表示当前链表结束
}

// 单链表整表删除
Status ClearList(LinkList *L)
{
  LinkList p, q;
  p = (*L)->next; // p 指向第一个结点
  while (p) // 没到尾结点
  {
    q = p->next;
    free(p);
    p = q;
  }
  (*L)->next = NULL;  // 头结点指针域为空
  return OK;
}

int main(int argc, char const *argv[])
{
  printf("hello world\n");
  return 0;
}