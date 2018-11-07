/**
 * 图
 * 邻接矩阵
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100         // 最大顶点数
#define INFINITY 65535     // 用 65535 代表 ∞
#define TRUE 1
#define FALSE 0
typedef int Boolean;
Boolean visited[MAXVEX];   // 访问标志的数组
typedef char VertexType;   // 顶点类型
typedef int EdgeType;      // 边上的权值
typedef struct 
{
  VertexType vexs[MAXVEX];      // 顶点表
  EdgeType arc[MAXVEX][MAXVEX]; // 邻接矩阵，可看做边表
  int numVertexes, numEdges;    // 图中当前顶点数和边数
} MGraph;

void CreateMGraph(MGraph *G)
{
  int i,j,k,w;
  printf("输入顶点数和边数：\n");
  scanf("%d,%d", &G->numVertexes, &G->numEdges); // 输入定点数和边数
  for(i = 0; i < G->numVertexes; i++)    // 读入顶点信息，建立顶点表
    scanf(&G->vexs[i]);
  for(i = 0; i < G->numVertexes; i++)
    for(j = 0; j < G->numVertexes; j++)
      G->arc[i][j] = INFINITY;          // 邻接矩阵初始化
  for (k = 0; k < G->numEdges; k++)     // 读入numEdges条边，建立邻接矩阵
  {
    printf("输入边（vi,vj）上的下标i, 下标j和权w：\n");
    scanf("%d,%d,%d", &i,&j,&w);  // 输入边（vi，vj）上的权w
    G->arc[i][j] = w;
    G->arc[j][i] = G->arc[i][j]; // 因为是无向图，矩阵对称
  }
}

// Depth First Search
// 深度优先递归算法
void DFS(MGraph G, int i)
{
  int j;
  printf("%c", G.vexs[i]);
  visited[i] = TRUE;
  for(j = 0; j < G.numVertexes; j++)
    if(G.arc[i][j] == 1 && !visited[j])
      DFS(G, j); // 对未访问的邻接顶点递归调用
}

// 深度遍历操作
void DFSTraverse(MGraph G)
{
  int i;
  for(i = 0; i < G.numVertexes; i++)
    visited[i] = FALSE;  // 初始化所有顶点为未访问状态
  for(i = 0; i < G.numVertexes; i++)
    if(!visited[i])
      DFS(G, i);
}