#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2
#define INFEASIBLE -1

typedef int Status;

typedef char TElemType;    // �������������Ԫ������Ϊ�ַ�

typedef struct  BiTNode {
    TElemType   data;                     // ������
    struct BiTNode   *lchild,*rchild;    // ���Һ���ָ��
}BiTNode,*BiTree;

typedef struct TriTNode {
  TElemType data; // ������
  TriTNode *parent, *lchild, *rchild; // ˫�ס����Һ���ָ��
} TriTNode,*TriTree;

typedef BiTree SElemType; // ��ջԪ��Ϊ��������ָ������

typedef struct LSNode {
   SElemType data;    // ������
   struct LSNode *next;    // ָ����
} LSNode, *LStack;    // ������ջ����

typedef struct LQNode {     
  SElemType  data;
  struct LQNode  *next;
} LQNode, *QueuePtr; // ���ͽ��ָ������

typedef struct {     
  QueuePtr  front;  // ��ͷָ��
  QueuePtr  rear;   // ��βָ��
} LQueue; // ����������

Status InitStack_LS(LStack &S){
   S = NULL;
}

Status Push_LS(LStack &S, SElemType e) { // Ԫ��eѹ��ջS
   LSNode *t;
   t = (LSNode*)malloc(sizeof(LSNode)); // ΪԪ��e����һ���½��
   if(NULL==t)  return OVERFLOW; // ����ʧ�ܣ�����
   t->data = e;
   t->next = S;  // ��ջ��λ�ò����½��
   S = t;
   return OK;
}

Status Pop_LS(LStack &S, SElemType &e) { // ջS��ջ��Ԫ�س�ջ������e����
   LSNode *t;
   if(NULL==S) return ERROR; // �ж��Ƿ�Ϊ��ջ
   t = S;    // tָ��ջ��Ԫ�ؽ��
   e = S->data;      // ��e����ջ��Ԫ��ֵ
   S = S->next;       // ɾ��ջ��Ԫ�ؽ��
   free(t);          // �ͷŽ��
   return OK;
}

Status StackEmpty_LS(LStack S){
  // �жϿ�ջ����ջS���򷵻�TRUE������FALSE
   if(S == NULL) return TRUE;
   return FALSE;
}

Status DestroyStack_LS(LStack &S){ // ������ջS
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
   // ȡջS��ջ��Ԫ�أ�����e����
   if(NULL==S) return ERROR; // �ж��Ƿ�Ϊ��ջ
   e = S->data; 
   return OK;
}

void InitQueue_LQ(LQueue &Q){ // ����һ���ն��� Q
  Q.front = Q.rear = NULL;
}

void DestroyQueue_LQ(LQueue &Q){ // ���ٶ���Q
  while(Q.front!=NULL) // Q.front��Ϊ��
  { 
    Q.rear=Q.front; // Q.rearָ��Q.front��ָ��Ľ��
    free(Q.front); // �ͷ�Q.front��ָ���
    Q.front=Q.rear; // Q.frontָ��Q.front����һ�����
   }
   // ElemType e;
   //while ( !QueueEmpty_LQ(Q)) DeQueue_LQ(Q,e) ;
}
Status QueueEmpty_LQ(LQueue Q){
  // ������ Q Ϊ�գ��򷵻�TRUE������FALSE
  if(NULL==Q.front) return TRUE;
  else return FALSE;
}

Status DeQueue_LQ(LQueue &Q, SElemType &e) {
     // ������Q�ǿգ���ɾ����ͷԪ�أ��� e ������ֵ��������OK�����򷵻�ERROR
    LQNode *p;
    if(NULL==Q.front) return ERROR;
    p = Q.front;   // ָ���ͷ���
    e = p->data;   // �����ͷ��������
    Q.front = p->next; 
    if(Q.rear==p) Q.rear = NULL; // ����ֻ��һ����㣬ɾȥ����б��
    free(p);                 // �ͷű�ɾ��ͷ���
    return OK;
}

Status EnQueue_LQ(LQueue &Q, SElemType e){
  LQNode *p;
   p = (LQNode*)malloc(sizeof(LQNode)); // �����½��
   if(NULL==p) return OVERFLOW;
   p->data = e;
   p->next = NULL;
   if(NULL==Q.front) Q.front = p; // e����ն���
   else Q.rear->next = p; // e����ǿն���
   Q.rear = p; // ��βָ��ָ���µĶ�β
   return OK;
}  

int QueueLength_LQ(LQueue Q){
   // �����Q�ĳ���
   int i=0; // ����������ֵΪ0
   QueuePtr p=Q.front; // pָ��ͷ���
   while(p!=NULL) // p��ָ����NULL
   { i++; // ������+1
     p=p->next; // pָ����һ�����
   }
   return i;
}

Status GetHead_LQ(LQueue Q, SElemType &e){
  // �����в��գ����� e ����Q�Ķ�ͷԪ�أ�������OK������ERROR
  if (QueueEmpty_LQ(Q) == NULL)  return  ERROR;
  e= Q.front->data;
  return OK;
}
