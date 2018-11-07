/**
 * 查找
 */
#include <stdio.h>
#include <stdlib.h>

// 有哨兵顺序查找
int Sequential_Search(int *a, int n, int key)
{
  int i;
  a[0] = key; // 哨兵
  i = n;   // 循环从尾部开始
  while(a[i] != key)
    i--;
  return i; // 返回0，没找到
}

// 二分查找
int Binary_Search(int *a, int n, int key)
{
  int low, high, mid;
  low = 1;            // 定义最低下标为记录首位
  high = n;           // 定义最高下标为记录末尾
  while(low <= high)
  {
    mid = (low+high) / 2;  // 折半
    // mid = low + (high - low) * (key - a[low]) / (a[high] - a[low]);   // 插值查找
    if (key < a[mid])      // 若查找值比中值小
      high = mid - 1;      // 最高下标调整到中位下标小一位
    else if(key > a[mid])  // 若比中值大
      low = mid + 1;       // 最低下标调整到中位下标大一位
    else
      return mid;          // 找到的位置
  }
  return 0;
}

// 斐波那契查找
int Fibonacci_Search(int *a, int n, int key)
{
  int F[30] = {1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368};
  int low, hight, mid, i, k;
  low = 1;
  hight = n;
  k = 0;
  while(n > F[k]- 1) // 计算n位于斐波那契数列中的位置
    k++;

  for(i = n; i < F[k] - 1; i++) // 将不满的数值补全
    a[i] = a[n];

  while(low <= hight)
  {
    mid = low + F[k-1]-1; // 计算当前分隔的下标
    if(key < a[mid])      // 若查找记录小于当前分隔记录
    {
      hight = mid - 1;    // 若查找记录小于当前分隔记录
      k = k - 1;          // 斐波那契数列下标减一位
    }
    else if(key > a[mid]) // 若查找记录大于当前分隔记录
    {
      low = mid + 1;      // 最低下标调整到分隔下标mid+1处
      k = k - 2;          // 斐波那契数列下标减两位
    }
    else
    {
      if(mid <= n)
        return mid;       // 若相等则说明mid即为查找的位置
      else
        return n;         // 若 mid > n 说明是补全数值，返回 n
    }
  }
}