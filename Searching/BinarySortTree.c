/**
 * 二叉树排序查找
 */
#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW -2
#define MAXSIZE 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef struct BiTNode
{
  int data;
  struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 递归查找二叉排序树T中是否存在key
// 指针f指向T的双亲，其初始调用值为NULL
// 若查找成功，则指针p指向该数据元素结点，并返回TRUE
// 否则指针p指向查找路径上访问的最后一个结点并返回FALSE
// SearchBST(T, 93, NULL, p)
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
  if (!T) // 查找不成功
  {
    *p = f;
    return FALSE;
  }
  else if(key == T->data)  // 查找成功
  {
    *p = T;
    return TRUE;
  }
  else if(key < T->data)
    return SearchBST(T->lchild, key, T, p); // 在左子树继续查找
  else
    return SearchBST(T->rchild, key, T, p); // 在右子数继续查找
}

// 当二叉排序树T中不存在关键字等于key的数据元素时
// 插入key 并返回TRUE, 否则返回FALSE
Status InsertBST(BiTree *T, int key)
{
  BiTree p,s;
  if(!SearchBST(*T, key, NULL, &p)) // 查找不成功
  {
    s = (BiTree)malloc(sizeof(BiTNode));
    s->data = key;
    s->lchild = s->rchild = NULL;
    if (!p)
      *T = s;
    else if(key < p->data)
      p->lchild = s;
    else
      p->rchild = s;
    return TRUE;
  }
  else
    return FALSE;
}

// 从二叉排序树种删除及结点p, 并重接它的左或右子树
Status Delete(BiTree *p)
{
  BiTree q,s;
  if ((*p)->rchild == NULL)  // 右子树空则只需重接它的左子树
  {
    q = *p;
    *p = (*p)->lchild;
    free(q);
  }
  else if((*p)->lchild == NULL) // 只需重接它的右子树
  {
    q = *p;
    *p = (*p)->rchild;
    free(q);
  }
  else // 左右子树均不空
  {
    q = *p;
    s = (*p)->lchild;
    while(s->rchild)    // 转左, 然后向右到尽头（找待删结点的前驱）
    {
      q = s;
      s = s->rchild;
    }
    (*p)->data = s->data;   // s 指向被删结点的直接前驱
    if (q != *p)
      q->rchild = s->lchild; // 重接q的右子树
    else
      q->lchild = s->lchild; // 重接q的左子树
    free(s);
  }
  return TRUE;
}

Status DeleteBST(BiTree *T, int key)
{
  if(!*T)
    return FALSE;
  else
  {
    if(key == (*T)->data)
      return Delete(T);
    else if (key < (*T)->data)
      return DeleteBST(&(*T)->lchild, key);
    else
      return DeleteBST(&(*T)->rchild, key);
  }
}

int main(int argc, char const *argv[])
{
  int i;
  int a[10] = {62,88,58,47,35,73,51,99,37,93};
  BiTree T = NULL;
  for (i = 0; i< 10; i++)
    InsertBST(&T, a[i]);
  return 0;
}
