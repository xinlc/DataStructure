/**
 * 树
 * 孩子表示法
 */
#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_SIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int TElemType;
typedef int Status;
typedef struct CTNode // 孩子结点
{
  int child;
  struct CTNode *next;
} *ChildPtr;

typedef struct // 表头结构
{
  TElemType data;
  ChildPtr firstchild;
} CTBox;

typedef struct // 树结构
{
  CTBox nodes[MAX_TREE_SIZE]; // 结点数组
  int r, n;             // 根的位置和结点数
} Ctree;
