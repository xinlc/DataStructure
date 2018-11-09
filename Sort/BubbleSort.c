/**
 * 冒泡排序
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef struct
{
  int r[MAXSIZE + 1]; // 存储要排序数组,r[0] 用作哨兵或临时变量
  int length;
} SqList;

// 交换L中数组r的下标为i和j的值
void swap(SqList *L, int i, int j)
{
  int temp = L->r[i];
  L->r[i] = L->r[j];
  L->r[j] = temp;
}

void BubbleSort0 (SqList *L)
{
  int i, j;
  for (i=1; i<L->length; i++)
  {
    for(j=i+1; j<L->length; j++)
    {
      if(L->r[i] > L->r[j])
      {
        swap(L,i,j);
      }
    }
  }
}

void BubbleSrot(SqList *L)
{
  int i, j;
  for(i=1; i<L->length; i++)
  {
    for(i=L->length-1; j>=i; j--)
    {
      if(L->r[j] > L->r[j+1])
      {
        swap(L, j, j+1);
      }
    }
  }
}

void BulleSort2(SqList *L)
{
  int i,j;
  Status flag = TRUE;
  for(i=1; i<L->length && flag; i++)
  {
    flag = FALSE;
    for(j=L->length-1; j >= i; j--)
    {
      if(L->r[j] > L->r[j+1])
      {
        swap(L,j,j+1);
        flag = TRUE;
      }
    }
  }
}