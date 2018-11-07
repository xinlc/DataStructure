/**
 * 图
 * 邻接表
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100         // 最大顶点数
#define INFINITY 65535     // 用 65535 代表 ∞
typedef char VertexType;   // 顶点类型
typedef int EdgeType;      // 边上的权值
typedef struct  EdgeNode   // 边表结点
{
  int adjvex;              // 邻接点域，存储该顶点对应的下标
  EdgeType weight;         // 存储权值
  struct EdgeNode *next;   // 链域，指向下一个邻结点
} EdgeNode;

typedef struct VertexNode  // 顶点表结点
{
  VertexType data;         // 顶点域，存储顶点信
  EdgeNode *firstedge;     // 边表头指针
} VertexNode, AdjList[MAXVEX];

typedef struct
{
  AdjList adjList;
  int numVertexes, numEdges;     // 图中当前顶点数和边数
} GraphAdjList;

void CreateALGraph(GraphAdjList *G)
{
  int i,j,k;
  EdgeNode *e;
  printf("输入顶点数和边数:\n");
  scanf("%d,%d", &G->numVertexes, &G->numEdges);
  for(i = 0; i < G->numVertexes; i++)     // 读入顶点信息，建立顶点表
  {
    scanf(&G->adjList[i].data);
    G->adjList[i].firstedge = NULL;
  }
  for(k = 0; k < G->numEdges; k++)
  {
    printf("输入边(vi,vj)上的顶点序号:\n");
    scanf("%d,%d", &i,&j);
    e = (EdgeNode *)malloc(sizeof(EdgeNode));
    e->adjvex = j;      // 邻接序号为j
    e->next = G->adjList[i].firstedge; // 将e指针指向当前顶点指向的结点
    G->adjList[j].firstedge = e;  // 将当前顶点的指针指向e
  }
}