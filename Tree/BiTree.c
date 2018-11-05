/**
 * 二叉树
 * 二叉链表
 */
#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int TElemType;
typedef int Status;
typedef struct BiTNode
{
  TElemType data;
  struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

void CreateBiTree(BiTree *T)
{
  TElemType ch;
  scanf("%c", &ch);
  if (ch == '#')
    *T = NULL;
  else
  {
    *T = (BiTree) malloc(sizeof(BiTNode));
    if (!*T)
      exit(OVERFLOW);
    (*T) -> data = ch; // 生成根节点
    CreateBiTree(&(*T)->lchild); // 生成左子树
    CreateBiTree(&(*T)->rchild); // 生成右子树
  }
}

// 前序遍历
void PreOrderTraverse(BiTree T)
{
  if (T == NULL)
    return;
  printf("%c", T->data);       // 显示结点数据
  PreOrderTraverse(T->lchild); // 遍历左子树
  PreOrderTraverse(T->rchild); // 遍历右子树
}

// 中序遍历
void InOrderTraverse(BiTree T)
{
  if (T == NULL)
    return;
  InOrderTraverse(T->lchild);   // 中序遍历左树
  printf("%c", T->data);        // 显示结点数据
  InOrderTraverse(T->rchild);   // 遍历右树
}

void PostOrderTraverse(BiTree T)
{
  if (T == NULL)
    return;
  PostOrderTraverse(T->lchild);
  PostOrderTraverse(T->rchild);
  printf("%c", T->data);        // 显示结点数据
}