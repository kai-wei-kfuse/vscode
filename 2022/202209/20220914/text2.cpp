#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW 0
typedef int Status;

typedef char ElemType;

typedef struct{
   ElemType *elem;     // ´æ´¢¿Õ¼äµÄ»ùÖ·
   int length;  // ±í³¤
   int size;    // ´æ´¢ÈÝÁ¿
   int increment; // ´æ´¢ÔöÁ¿
}SqList;

Status InitList_Sq(SqList &L, int size, int increment){
  // ³õÊ¼»¯Ë³Ðò±íL 
    S.elem = (ElemType*)malloc(size * sizeof(ElemType));
    // ·ÖÅäÈÝÁ¿ÎªsizeµÄ´æ´¢¿Õ¼ä
    if (NULL == S.elem)
        return OVERFLOW;
    S.length=0;                 //³õÊ¼»¯±í³¤
    S.size = size;            // ³õÊ¼ÈÝÁ¿Öµ
    S.increment = increment;  // ³õÊ¼ÔöÁ¿Öµ
    return OK;
}

Status  Append_Sq(SqList &L, ElemType e) { // ÔÚË³Ðò±íL±íÎ²Ìí¼ÓÔªËØ
    if(S.length==0)return ERROR;
    S.elem[S.length++]=e;
    return OK;
}
Status DeleteLast_Sq(SqList &L, ElemType &e) { 
  // É¾³ýË³Ðò±íLµÄ±íÎ²ÔªËØ£¬²¢ÓÃ²ÎÊýe·µ»ØÆäÖµ                      
  	if(S.length==0)return ERROR;
  	S.elem[S.length--]=e;
  	return OK;
}

int Search_Sq(SqList L, ElemType  e) {
  // Ë³Ðò±íLÖÐË³Ðò²éÕÒÊý¾ÝÔªËØe£¬³É¹¦Ê±·µ»Ø¸ÃÔªËØÔÚ±íÖÐµÚÒ»´Î³öÏÖµÄÎ»ÖÃ£¬·ñÔò·µ»Ø-1
  int i = 0;
  while(i<L.length && L.elem[i]!=e) i++; // Ë³Ðò²éÕÒe
  if(i<L.length) return i; // ·µ»ØeµÄÎ»Ðò
  else return -1;
} 

int  ListLength_Sq(SqList L){
  return L.length;
} 
Status (* visit)(ElemType e);

Status  printElement(ElemType e){//´òÓ¡ÔªËØ
   printf("%c ",e);
   return OK;
}

Status ListEmpty_Sq(SqList L){
  // ÈôË³Ðò±íLÎª¿Õ±í£¬Ôò·µ»ØTRUE£¬·ñÔòFALSE 
  if(S.length==0)return TRUE;
  else return FAlSE;
}

Status ClearList_Sq(SqList &L){ // ½«Ë³Ðò±íLÇå¿Õ
   S.length=0;
   return TRUE;
}

Status GetElem_Sq(SqList L, int i, ElemType &e){
   // ÓÃ e ·µ»ØË³Ðò±íL ÖÐµÚ i¸öÔªËØµÄÖµ 0<=i<L.length
   e=L.elem[i];
   return TRUE;
}

Status DestroyList_Sq(SqList &L){ // Ïú»ÙË³Ðò±íL
 	free(L.elem);
 	return OK;
}

Status ListTraverse_Sq(SqList L, Status(*visit)(ElemType e)){
	int tmp;
	while(tmp<=L.length){
		visit(L.elem[tmp]);
	}
}

Status PutElem_Sq(SqList &L, int i, ElemType e){
  // ½«Ë³Ðò±íLÖÐµÚ i ¸öÔªËØ¸³ÖµÎª  e
  L.elem[i]=e;
   return TRUE;
}

void MergeList_Sq(SqList La, SqList Lb, SqList &Lc) {  
   int i=0, j=0;   ElemType ai, bj;
   InitList_Sq(Lc, La.length+Lb.length, 10); // ´´½¨¿Õ±íLc 
   while(i<La.length && j<Lb.length) { // ±íLaºÍLb¾ù·Ç¿Õ 
      GetElem_Sq(La,i,ai);   
      GetElem_Sq(Lb,j,bj); 
      if(ai<=bj) {   Append_Sq(Lc,ai);   ++i;   }
      else {   Append_Sq(Lc,bj);   ++j;   }
   }
   while(i< La.length) { // ±íLb¿Õ   
      GetElem_Sq(La,i++,ai);   Append_Sq(Lc,ai);
   }
   while(j< Lb.length) { // ±íLa¿Õ    
      GetElem_Sq(Lb,j++,bj);   Append_Sq(Lc,bj);
   }
} 

void main(){
  SqList L,L1,L2;
  int size;
  int increment;
  size = 10;
  increment =5;
  printf("³õÊ¼»¯Ë³Ðò±í\n");
  InitList_Sq(L, size, increment);
  InitList_Sq(L1, size, increment);
  Append_Sq(L,'A');
  Append_Sq(L,'B');
  Append_Sq(L,'E');
  Append_Sq(L1,'C');
  Append_Sq(L1,'D');
  Append_Sq(L1,'F');
  visit=printElement; //È¡º¯ÊýµØÖ·
  ListTraverse_Sq(L,visit);
  MergeList_Sq(L,L1,L2);
  printf("\n");
  ListTraverse_Sq(L2,visit);
}  