#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1

typedef int Status;

typedef char TElemType;    // 假设二叉树结点的元素类型为字符

typedef struct  BiTNode {
    TElemType   data;                     // 数据域
    struct BiTNode   *lchild,*rchild;    // 左、右孩子指针
}BiTNode,*BiTree;

typedef struct TriTNode {
  TElemType data; // 数据域
  TriTNode *parent, *lchild, *rchild; // 双亲、左右孩子指针
} TriTNode,*TriTree;

typedef BiTree SElemType; // 设栈元素为二叉树的指针类型

typedef struct LSNode {
   SElemType data;    // 数据域
   struct LSNode *next;    // 指针域
} LSNode, *LStack;    // 结点和链栈类型

typedef struct LQNode {     
  SElemType  data;
  struct LQNode  *next;
} LQNode, *QueuePtr; // 结点和结点指针类型

typedef struct {     
  QueuePtr  front;  // 队头指针
  QueuePtr  rear;   // 队尾指针
} LQueue; // 链队列类型

Status InitStack_LS(LStack &S){
   S = NULL;
}

Status Push_LS(LStack &S, SElemType e) { // 元素e压入栈S
   LSNode *t;
   t = (LSNode*)malloc(sizeof(LSNode)); // 为元素e生成一个新结点
   if(NULL==t)  return OVERFLOW; // 生成失败，返回
   t->data = e;
   t->next = S;  // 在栈顶位置插入新结点
   S = t;
   return OK;
}

Status Pop_LS(LStack &S, SElemType &e) { // 栈S的栈顶元素出栈，并用e返回
   LSNode *t;
   if(NULL==S) return ERROR; // 判断是否为空栈
   t = S;    // t指向栈顶元素结点
   e = S->data;      // 用e返回栈顶元素值
   S = S->next;       // 删除栈顶元素结点
   free(t);          // 释放结点
   return OK;
}

Status StackEmpty_LS(LStack S){
  // 判断空栈，若栈S空则返回TRUE，否则FALSE
   if(S == NULL) return TRUE;
   return FALSE;
}

Status DestroyStack_LS(LStack &S){ // 销毁链栈S
   // ElemType e;
   // while(StackEmpty_LS(S)==FALSE) Pop_LS(S,e);
   LSNode *t;
   while(S!=NULL){
      t=S;
      S=S->next;
      free(t);
   }   
   return OK;
}

Status GetTop_LS(LStack S, SElemType &e){
   // 取栈S的栈顶元素，并用e返回
   if(NULL==S) return ERROR; // 判断是否为空栈
   e = S->data; 
   return OK;
}

void InitQueue_LQ(LQueue &Q){ // 构造一个空队列 Q
  Q.front = Q.rear = NULL;
}

void DestroyQueue_LQ(LQueue &Q){ // 销毁队列Q
  while(Q.front!=NULL) // Q.front不为空
  { 
    Q.rear=Q.front; // Q.rear指向Q.front所指向的结点
    free(Q.front); // 释放Q.front所指结点
    Q.front=Q.rear; // Q.front指向Q.front的下一个结点
   }
   // ElemType e;
   //while ( !QueueEmpty_LQ(Q)) DeQueue_LQ(Q,e) ;
}
Status QueueEmpty_LQ(LQueue Q){
  // 若队列 Q 为空，则返回TRUE，否则FALSE
  if(NULL==Q.front) return TRUE;
  else return FALSE;
}

Status DeQueue_LQ(LQueue &Q, SElemType &e) {
     // 若队列Q非空，则删除队头元素，用 e 返回其值，并返回OK；否则返回ERROR
    LQNode *p;
    if(NULL==Q.front) return ERROR;
    p = Q.front;   // 指向队头结点
    e = p->data;   // 保存队头结点的数据
    Q.front = p->next; 
    if(Q.rear==p) Q.rear = NULL; // 队列只有一个结点，删去后队列变空
    free(p);                 // 释放被删队头结点
    return OK;
}

Status EnQueue_LQ(LQueue &Q, SElemType e){
  LQNode *p;
   p = (LQNode*)malloc(sizeof(LQNode)); // 申请新结点
   if(NULL==p) return OVERFLOW;
   p->data = e;
   p->next = NULL;
   if(NULL==Q.front) Q.front = p; // e插入空队列
   else Q.rear->next = p; // e插入非空队列
   Q.rear = p; // 队尾指针指向新的队尾
   return OK;
}  

int QueueLength_LQ(LQueue Q){
   // 求队列Q的长度
   int i=0; // 计数器，初值为0
   QueuePtr p=Q.front; // p指向头结点
   while(p!=NULL) // p所指不是NULL
   { i++; // 计数器+1
     p=p->next; // p指向下一个结点
   }
   return i;
}

Status GetHead_LQ(LQueue Q, SElemType &e){
  // 若队列不空，则用 e 返回Q的队头元素，并返回OK；否则ERROR
  if (QueueEmpty_LQ(Q) == NULL)  return  ERROR;
  e= Q.front->data;
  return OK;
}
