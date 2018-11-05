/**
 * 链队列
 *    人生，就像是一个很大的栈演变。出生时你赤条条地来到人世，慢慢地长大，渐渐地变老，最终还得赤条条的离开世间。
 *    人生，又仿佛是一天一天小小的栈重现。童年父母每天抱你不断地进出家门，壮年你每天奔波于家与事业之间，
 * 老年你每天独自蹒跚于养老院的门里屋前。
 *    人生，更需要有进栈出栈精神的体现。在哪里跌倒，就应该在哪里爬起来。无论陷入何等困境，只要能抬头能仰望蓝天，
 * 就有希望，不断进取，你就可以让出头之日重现。困难不会永远存在，强者才能勇往直前。
 *    人生，其实就是一个大大的队列演变。无知童年、快乐少年，稚傲青年，成熟中年，安逸晚年。
 *    人生，又是一个又一个小小的队列重现。春夏秋冬轮回年年，早中晚夜循环天天。变化的是时间，不变的是你对未来执著的信念。
 *    人生，更需要有队列精神的体现。南极到北极，不过是南纬90度到北纬90度的队列，如果你中途犹豫，临时转向，
 * 也许你就只能和企鹅相伴永远。可事实上，无论哪个方向，只要你坚持到底，你都可以到达终点。
 */
#include <stdio.h>
#include <stdlib.h>
#define OVERFLOW -2
#define MAXSIZE 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int QElemType;
typedef int Status;
typedef struct QNode // 结点结构
{
  QElemType data;
  struct QNode *next;
} QNode, *QueuePtr;

typedef struct // 队列链表结构
{ 
  QueuePtr front, rear;    // 队头，队尾指针
} LinkQueue;

Status EnQueue(LinkQueue *Q, QElemType e)
{
  QueuePtr s = (QueuePtr) malloc(sizeof(QNode));
  if (!s)  // 存储分配失败
    exit(OVERFLOW);
  s->data = e;
  s->next = NULL;
  Q->rear->next = s; // 新节点赋值给原队列尾结点后继
  Q->rear = s;       // 把当前的s设置为尾队结点
  return OK;
}

Status DeQueue(LinkQueue *Q, QElemType *e)
{
  QueuePtr p;
  if (Q->front == Q->rear)
    return ERROR;
  p = Q->front->next; // 将欲删除的队头结点暂存给p
  *e = p->data;
  Q->front->next = p->next;
  // 若队头是队尾，则删除后将rear指向头结点
  if (Q->rear == p)
    Q->rear = Q->front;
  free(p);
  return OK;
}
