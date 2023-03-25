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
   ElemType *elem;     // 存储空间的基址
   int top;    // 栈顶元素的下一个位置，简称栈顶位标
   int size;    // 当前分配的存储容量
   int increment;    // 扩容时，增加的存储容量
} SqStack;

Status InitStack_Sq(SqStack &S, int size, int increment){ 
// 初始化空的顺序栈S
   S.elem = (ElemType*)malloc(size*sizeof(ElemType));
   // 分配容量为size的存储空间
   if(NULL==S.elem) return OVERFLOW;
   S.top = 0;       // 置S为空栈
   S.size = size;  // 初始容量值
   S.increment = increment; // 初始增量值
   return OK;
}
 
Status StackEmpty_Sq(SqStack S){
   
}

Status Push_Sq(SqStack &S, ElemType e) { // 元素e压入栈S
   ElemType *newbase;
   if(S.top>=S.size) { // 若栈顶位标已到达所分配的容量，则栈满，扩容
      newbase = (ElemType*)realloc(S.elem, 
                                       (S.size+S.increment)*sizeof(ElemType));
      if(NULL==newbase) return OVERFLOW;   
      S.elem = newbase;
      S.size = S.size+S.increment;
   }
   S.elem[S.top++] = e;  //e入栈，并将S.top加1
   return OK; 
}

Status ClearStack_Sq(SqStack &S){ // 清空栈S
   
}

Status GetTop_Sq(SqStack S, ElemType &e) { // 取栈S的栈顶元素，用e返回
   
}

Status Pop_Sq(SqStack &S, ElemType &e) { // 栈S的栈顶元素出栈，并用e返回
    
}

Status DestroyStack_Sq(SqStack &S)
{
   
}
void Converstion(int N) {
   SqStack S; 
   ElemType e;
   InitStack_Sq(S, 10, 3); 
   while(N!=0) {
      Push_Sq(S, N%8);  // 将N除以8的余数入栈
      N /= 8;             // N取值为其除以8的商
   }
   while(FALSE==StackEmpty_Sq(S)) { // 依次输出栈中的余数
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
                       return ERROR;  // 第(2)种不匹配情形
                    else {
                       GetTop_Sq(S, e);                       
                       if((exp[i]==')' && e=='(') ||(exp[i]==']' && e=='[')) {
                           Pop_Sq(S, e); i++;
                        } 
                       else 
                           return ERROR; // 第(1)种不匹配情况
                    }
         break;  
      } //end switch
   }   
   if(TRUE==StackEmpty_Sq(S)) return OK;
   else return ERROR; // 第(3)种不匹配情况
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
