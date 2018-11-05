/**
 * 树
 * 孩子兄弟表示法
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
typedef struct CTNode
{
  TElemType data;
  struct CSNode *firstchild, *rightsib;
} CSNode, *CStree;