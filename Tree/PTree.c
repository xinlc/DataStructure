/**
 * 树
 * 双亲表示法
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define MAX_TREE_SIZE 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int TElemType;
typedef int Status;
typedef struct PTNode
{
  TElemType data;
  int parent;      // 双亲位置
} PTNode;

typedef struct
{
  PTNode nodes[MAX_TREE_SIZE]; // 结点数组
  int r, n;      // 根的位置和结点数
} PTree;
