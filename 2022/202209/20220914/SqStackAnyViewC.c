#include<stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW 0
typedef int Status;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10 
typedef char ElemType;
typedef struct{
   ElemType *elem;     // �洢�ռ�Ļ�ַ
   int top;    // ջ��Ԫ�ص���һ��λ�ã����ջ��λ��
   int size;    // ��ǰ����Ĵ洢����
   int increment;    // ����ʱ�����ӵĴ洢����
} SqStack;

Status InitStack_Sq(SqStack &S, int size, int increment){ 
// ��ʼ���յ�˳��ջS
   S.elem = (ElemType*)malloc(size*sizeof(ElemType));
   // ��������Ϊsize�Ĵ洢�ռ�
   if(NULL==S.elem) return OVERFLOW;
   S.top = 0;       // ��SΪ��ջ
   S.size = size;  // ��ʼ����ֵ
   S.increment = increment; // ��ʼ����ֵ
   return OK;
}
 
Status StackEmpty_Sq(SqStack S){
   
}

Status Push_Sq(SqStack &S, ElemType e) { // Ԫ��eѹ��ջS
   ElemType *newbase;
   if(S.top>=S.size) { // ��ջ��λ���ѵ������������������ջ��������
      newbase = (ElemType*)realloc(S.elem, 
                                       (S.size+S.increment)*sizeof(ElemType));
      if(NULL==newbase) return OVERFLOW;   
      S.elem = newbase;
      S.size = S.size+S.increment;
   }
   S.elem[S.top++] = e;  //e��ջ������S.top��1
   return OK; 
}

Status ClearStack_Sq(SqStack &S){ // ���ջS
   
}

Status GetTop_Sq(SqStack S, ElemType &e) { // ȡջS��ջ��Ԫ�أ���e����
   
}

Status Pop_Sq(SqStack &S, ElemType &e) { // ջS��ջ��Ԫ�س�ջ������e����
    
}

Status DestroyStack_Sq(SqStack &S)
{
   
}
void Converstion(int N) {
   SqStack S; 
   ElemType e;
   InitStack_Sq(S, 10, 3); 
   while(N!=0) {
      Push_Sq(S, N%8);  // ��N����8��������ջ
      N /= 8;             // NȡֵΪ�����8����
   }
   while(FALSE==StackEmpty_Sq(S)) { // �������ջ�е�����
      Pop_Sq(S, e);
      printf("%d", e); 
   }
}

Status Matching(char *exp, int n) {
   int  i = 0;
   ElemType e;
   SqStack S; InitStack_Sq(S, n, n);
   while(i<n) {
      switch(exp[i]) {
         case  '(':    
         case  '[': Push_Sq(S, exp[i]);  i++;  break; 
         case  ')':  
         case  ']': if(TRUE==StackEmpty_Sq(S))
                       return ERROR;  // ��(2)�ֲ�ƥ������
                    else {
                       GetTop_Sq(S, e);                       
                       if((exp[i]==')' && e=='(') ||(exp[i]==']' && e=='[')) {
                           Pop_Sq(S, e); i++;
                        } 
                       else 
                           return ERROR; // ��(1)�ֲ�ƥ�����
                    }
         break;  
      } //end switch
   }   
   if(TRUE==StackEmpty_Sq(S)) return OK;
   else return ERROR; // ��(3)�ֲ�ƥ�����
}


void main(){
   SqStack S;
   int size, increment;
   size = 10;
   increment = 5;
   InitStack_Sq(S, size, increment);
   
   ElemType e;

   Push_Sq(S, 'A');
   Push_Sq(S, 'B');
   Push_Sq(S, 'C');
   ClearStack_Sq(S);
   
   printf("%d",StackEmpty_Sq(S));
   
   //
   
   //Pop_Sq(S, e);
   //Pop_Sq(S, e);
   //Pop_Sq(S, e);
   
   //Converstion(1348);
   
   char exp[6] = {'(','[',']',')','[',']'};
   //char exp[6] = {'(','[','[',']',')',')'};
   int n;
   n = 6;
  // printf("%d", Matching(exp, n));
   //printf("%d",DestroyStack_Sq(S));
}
