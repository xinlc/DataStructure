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
typedef int Status;
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

// 简单选择排序
void SelectSort(SqList *L)
{
  int i, j, min;
  for(i=1; i < L->length; i++)
  {
    min = i;
    for(j = i+1; j <= L->length; j++)
    {
      if(L->r[min] > L->r[j]) // 如果小于当前最小值的关键字
        min = j;
    }
    if(i!=min) // 若min不等于i,说明找到最小值,交换
      swap(L, i, min);
  }
}

// 插入排序
void InsertSort(SqList *L)
{
  int i,j;
  for(i=2; i<=L->length; i++)
  {
    if(L->r[i] < L->r[i-1])
    {
      L->r[0] = L->r[i];  // 设置哨兵
      for(j=i-1; L->r[j] > L->r[0]; j--)
        L->r[j+1] = L->r[j];  // 记录后移
      L->r[j+1] = L->r[0];    // 插入到正确位置
    }
  }
}

// 希尔排序
void ShellSort(SqList *L)
{
  int i, j;
  int increment = L->length;
  do
  {
    increment = increment / 3 + 1;
    for (i = increment + 1; i <= L->length; i++)
    {
      if (L->r[i] < L->r[i-increment])
      {
        L->r[0] = L->r[i];
        for(j=i-increment; j>0 && L->r[0] < L->r[j]; j-=increment)
          L->r[j+increment] = L->r[j];
        L->r[j+increment] = L->r[0];
      }
    }
  }
  while(increment>1);
}

// 堆排序
void HeapSort(SqList *L)
{
  int i;
  for(i=L->length/2; i>0; i--)  // 把L中的r构建成一个大顶堆
    HeapAdjust(L,i,L->length);
  for(i=L->length; i>1; i--)
  {
    swap(L,1,i);          // 将堆顶记录和当前未经排序子序列的最后一个记录交换
    HeapAdjust(L,1,i-1);  // 将L->r[1...i-1]重新调整为大顶堆
  }
}
void HeapAdjust(SqList *L, int s, int m)
{
  int temp,j;
  temp = L->r[s];
  for(j=2*s; j<=m; j*=2)
  {
    if(j<m && L->r[j] < L->r[j+1])
      ++j;
    if(temp >= L->r[j])
      break;
    L->r[s] = L->r[j];
    s = j;
  }
  L->r[s] = temp;
}

// 归并排序
void MergeSort(SqList *L)
{
  MSort(L->r, L->r, 1, L->length);
}
void MSort(int SR[], int TR1[], int s, int t)
{
  int m;
  int TR2[MAXSIZE+1];
  if(s==t)
    TR1[s] = SR[s];
  else
  {
    m = (s+t) / 2;
    MSort(SR, TR2, s, m);
    MSort(SR,TR2, m+1, t);
    Merge(TR2, TR1, s, m, t);
  }
}
void Merge(int SR[], int TR[], int i, int m, int n)
{
  int j,k,l;
  for(j=m+1,k=i; i<=m && j<=n; k++) // 将SR中记录由小到大归并入TR
  {
    if(SR[i] < SR[j])
      TR[k] = SR[i++];
    else
      TR[k] = SR[j++];
  }
  if(i<=m)
  {
    for(l=0; l<=m-i;l++)
      TR[k+1] = SR[i+1];
  }
  if(j<=n)
  {
    for(l=0;l<=n-j;l++)
      TR[k+1] = SR[j+1];
  }
}


// 快速排序
void QuickSort(SqList *L)
{
  QSort(L, 1, L->length);
}
void QSort(SqList *L, int low, int high)
{
  int pivot;
  if(low < high)
  {
    pivot = Partition(L, low, high);     // 将L->r[low...high] 一分为二,算出枢轴值pivot
    QSort(L,low,pivot-1);        // 对低子表递归排序
    QSort(L,pivot+1,high);       // 对高子表递归排序
  }
}
// 交换顺序表L中子表的记录，使枢轴记录到位，并返回其所在位置
// 此时在它之前（后）的记录不大（小）于它。
int Partition(SqList *L, int low, int high)
{
  int pivotkey;
  pivotkey = L->r[low];    // 用子表的第一个记录作枢轴记录
  while(low < high)          // 从表的两端交替向中间扫描
  {
    while(low < high && L->r[high] >= pivotkey)
      high--;
    swap(L, low, high);  // 将比枢轴记录小的记录交换到低端
    while(low < high && L->r[low] <= pivotkey)
      low++;
    swap(L, low, high);  // 将比数轴记录大的记录交换到高端
  }
  return low;            // 返回枢轴所在位置
}