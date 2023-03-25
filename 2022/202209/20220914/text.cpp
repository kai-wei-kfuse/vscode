#include <bits/stdc++.h>
#include <stdio.h>
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
typedef struct {
    ElemType* elem;  // ´æ´¢¿Õ¼äµÄ»ùÖ·
    int top;  // Õ»¶¥ÔªËØµÄÏÂÒ»¸öÎ»ÖÃ£¬¼ò³ÆÕ»¶¥Î»±ê
    int size;       // µ±Ç°·ÖÅäµÄ´æ´¢ÈÝÁ¿
    int increment;  // À©ÈÝÊ±£¬Ôö¼ÓµÄ´æ´¢ÈÝÁ¿
} SqStack;

Status InitStack_Sq(SqStack& S, int size, int increment) {
    // ³õÊ¼»¯¿ÕµÄË³ÐòÕ»S
    S.elem = (ElemType*)malloc(size * sizeof(ElemType));
    // ·ÖÅäÈÝÁ¿ÎªsizeµÄ´æ´¢¿Õ¼ä
    if (NULL == S.elem)
        return OVERFLOW;
    S.top = 0;                // ÖÃSÎª¿ÕÕ»
    S.size = size;            // ³õÊ     ¼ÈÝÁ¿Öµ
    S.increment = increment;  // ³õÊ¼  ÔöÁ¿Öµ
    return OK;
}

Status StackEmpty_Sq(SqStack S) {
    if (S.top == 0)
        return TRUE;
    else
        return FALSE;
}

Status Push_Sq(SqStack& S, ElemType e) {  // ÔªËØeÑ¹ÈëÕ»S
    ElemType* newbase;
    if (S.top >= S.size) {  // ÈôÕ»¶¥Î»±êÒÑµ½´ïËù·ÖÅäµÄÈÝÁ¿£¬ÔòÕ»Âú£¬À©ÈÝ
        newbase = (ElemType*)realloc(S.elem,
                                     (S.size + S.increment) * sizeof(ElemType));
        if (NULL == newbase)
            return OVERFLOW;
        S.elem = newbase;
        S.size = S.size + S.increment;
    }
    S.elem[S.top++] = e;  // eÈëÕ»£¬²¢½«S.top¼Ó1
    return OK;
}

Status ClearStack_Sq(SqStack& S) {  // Çå¿ÕÕ»S

    while (S.top != 0) {
        S.top--;
    }
    return TRUE;
}

Status GetTop_Sq(SqStack S, ElemType& e) {  // È¡Õ»SµÄÕ»¶¥ÔªËØ£¬ÓÃe·µ»Ø
    if (S.top == 0) {
        return FALSE;
    }

    e = S.elem[S.top - 1];
    return OK;
}

Status Pop_Sq(SqStack& S, ElemType& e) {  // Õ»SµÄÕ»¶¥ÔªËØ³öÕ»£¬²¢ÓÃe·µ»Ø
    if (S.top == 0)
        return FALSE;
    e = S.elem[S.top - 1];
    S.top--;
}

Status DestroyStack_Sq(SqStack& S) {
    free(S.elem);
    return OK;
}
void Converstion(int N) {
    SqStack S;
    ElemType e;
    InitStack_Sq(S, 10, 3);
    while (N != 0) {
        Push_Sq(S, N % 8);  // ½«N³ýÒÔ8µÄÓàÊýÈëÕ»
        N /= 8;             // NÈ¡ÖµÎªÆä³ýÒÔ8µÄÉÌ
    }
    while (FALSE == StackEmpty_Sq(S)) {  // ÒÀ´ÎÊä³öÕ»ÖÐµÄÓàÊý
        Pop_Sq(S, e);
        printf("%d", e);
    }
}

Status Matching(char* exp, int n) {
    int i = 0;
    ElemType e;
    SqStack S;
    InitStack_Sq(S, n, n);
    // printf("2233\n");
    while (i < n) {
        switch (exp[i]) {
            case '(':
            case '[':
                Push_Sq(S, exp[i]);
                i++;
                break;
            case ')':
            case ']':
                if (TRUE == StackEmpty_Sq(S))
                    return ERROR;  // µÚ(2)ÖÖ²»Æ¥ÅäÇéÐÎ
                else {
                    GetTop_Sq(S, e);
                    if ((exp[i] == ')' && e == '(') ||
                        (exp[i] == ']' && e == '[')) {
                        Pop_Sq(S, e);
                        i++;
                    } else {
                        // printf("233333\n");
                        return ERROR;  // µÚ(1)ÖÖ²»Æ¥ÅäÇé¿ö
                    }
                }
                break;
        }  // end switch
    }
    // cout << 233 << endl;
    // printf("233\n");
    if (TRUE == StackEmpty_Sq(S))
        return OK;
    else
        return ERROR;  // µÚ(3)ÖÖ²»Æ¥ÅäÇé¿ö
}

int main() {
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

    printf("%d\n", StackEmpty_Sq(S));
    // printf("233\n");

    //

    // Pop_Sq(S, e);
    // Pop_Sq(S, e);
    // Pop_Sq(S, e);

    // Converstion(1348);
    // char exp[6] = {'(', '[', ']', ']', '[', ']'};
    char exp[6] = {'(', '(', '[', ']', ')', ')'};
    int n;
    n = 6;
    printf("%d\n", Matching(exp, n));
    //printf("是否成功销毁栈：");
    printf("%d", DestroyStack_Sq(S));
}