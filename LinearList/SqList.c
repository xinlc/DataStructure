/**
 * 线性表顺序存储结构
 */
#include <stdio.h>
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int ElemType;
typedef int Status;
typedef struct
{
  ElemType data[MAXSIZE];
  int length;
} SqList;

Status GetElem(SqList L, int i, ElemType *e)
{
  if (L.length == 0 || i<1 || i>L.length)
    return ERROR;
  *e = L.data[i-1];
  return OK;
}

Status ListInsert(SqList *L, int i , ElemType e)
{
  int k;
  if (L->length == MAXSIZE) // 表已满
    return ERROR;

  if (i<1 || i>L->length+1) // i不在范围
    return ERROR;
  
  if (i<=L->length)
  {
    // 将要插入位置后数据元素向后移一位
    for (k=L->length-1; k>=i-1; k--)
      L->data[k+1] = L->data[k];
  }
  L->data[i-1] = e; // 插入新元素
  L->length++;
  return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e){
  int k;
  if (L->length == 0)
    return ERROR;
  if (i<1 || i>L->length)
    return ERROR;
  *e = L->data[i-1];
  if (i<L->length)
  {
    for (k=i; k<L->length; k++)
      L->data[k-1] = L->data[k];
  }
  L->length--;
  return OK;
}

int main(int argc, char const *argv[])
{
  SqList list = {
    .data[0] = 1,
    .length = 1,
  };
  printf("hello world\n");
  ListInsert(&list, 2, 5);
  ListInsert(&list, 3, 6);
  for (int i=0; i<list.length; i++)
    printf("%d \n", list.data[i]);
  return 0;
}