#include "BiTree.h"
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
// typedef int Status;  // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��

// typedef int Status;
//
// typedef char TElemType;    // �������������Ԫ������Ϊ�ַ�
//
// typedef struct  BiTNode {
//     TElemType   data;                     // ������
//     struct BiTNode   *lchild,*rchild;    // ���Һ���ָ��
// }BiTNode,*BiTree;

Status InitBiTree(BiTree& T) {
    // �������: ����ն�����T
    T = NULL;
    return OK;
}

Status visit(TElemType e) {
    printf("%c ", e);
    return OK;
}

BiTree MakeBiTree(TElemType e, BiTree L, BiTree R) {
    // ����һ�ö�����T�����и�����ֵΪe��L��R�ֱ���Ϊ��������������
    BiTree t;
    t = (BiTree)malloc(sizeof(BiTNode));
    if (NULL == t)
        return NULL;
    t->data = e;
    t->lchild = L;
    t->rchild = R;
    return t;
}

Status ReplaceLeft(BiTree& T, BiTree& LT) {
    // �滻����������T�ǿգ�����LT�滻T��������������LT����T��ԭ��������
    BiTree temp;
    if (NULL == T)
        return ERROR;
    temp = T->lchild;
    T->lchild = LT;
    LT = temp;
    return OK;
}

Status ReplaceRight(BiTree& T, BiTree& RT) {
    // �滻����������T�ǿգ�����RT�滻T��������������RT����T��ԭ��������
    BiTree temp;
    if (NULL == T)
        return ERROR;
    temp = T->rchild;
    T->rchild = RT;
    RT = temp;
    return OK;
}

Status CutLeft(BiTree& T, BiTree& LT) {
    // �Ͽ�����������T�ǿգ���Ͽ�T����������������LT
    if (NULL == T)
        return ERROR;
    LT = T->lchild;
    T->lchild = NULL;
    return OK;
}

Status CutRight(BiTree& T, BiTree& RT) {
    // ��������������T�ǿգ������T��������������RT����
    if (NULL == T)
        return ERROR;
    RT = T->rchild;
    T->rchild = NULL;
    return OK;
}

Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e)) {
    // �������������T��visit�Ƕ�����Ԫ�ز�����Ӧ�ú���
    if (NULL == T)
        return OK;
    // cout << "GG" << endl;
    InOrderTraverse(T->lchild, visit);
    visit(T->data);
    // cout << "xx" << endl;
    InOrderTraverse(T->rchild, visit);
    return OK;
}

BiTree CreateBiTree(char* definition, int& i) {
    // ��definition������������Ķ�������iΪdefinition�ĵ�ǰλ�꣬��ֵΪ0
    BiTree T;
    TElemType ch;
    ch = definition[i++];
    if (ch == '#')
        InitBiTree(T);
    else {
        T = MakeBiTree(ch, NULL, NULL);
        T->lchild = CreateBiTree(definition, i);
        T->rchild = CreateBiTree(definition, i);
    }
    return T;
}

int BiTreeDepth(BiTree T) {  // ���ض��������, TΪ������ָ��
    int depthLeft, depthRight;
    if (NULL == T)
        return 0;
    else {
        depthLeft = BiTreeDepth(T->rchild);
        depthRight = BiTreeDepth(T->lchild);
        return 1 + (depthLeft > depthRight ? depthLeft : depthRight);
    }
}

int Degrees1(BiTree T) {
    int d1Left, d1Right;
    if (NULL == T)
        return 0;
    if (T->lchild != NULL && T->rchild == NULL ||
        T->lchild == NULL && T->rchild != NULL)
        return 1 + Degrees1(T->lchild) + Degrees1(T->rchild);
    return Degrees1(T->lchild) + Degrees1(T->rchild);
}

void Degree1(BiTree T, int& count) {
    int d1Left, d1Right;
    if (NULL == T)
        return;
    if (T->lchild != NULL && T->rchild == NULL ||
        T->lchild == NULL && T->rchild != NULL) {
        count++;
    }
    Degrees1(T->lchild);
    Degrees1(T->rchild);
}
void CountLeaf(BiTree T, int& count) {
    if (T != NULL) {
        if (NULL == T->lchild && NULL == T->rchild)
            count++;
        CountLeaf(T->lchild, count);
        CountLeaf(T->rchild, count);
    }
}

void DestroyBiTree(BiTree& T) {    // ���ٶ�����T
    if (T != NULL) {               //�������ǿ�
        DestroyBiTree(T->lchild);  //�ݹ�����������
        DestroyBiTree(T->rchild);  //�ݹ�����������
        free(T);                   //�ͷŸ����
    }
}

Status BiTreeEmpty(BiTree T) {
    // �������пա���Ϊ�շ��� TRUE������FALSE
    if (NULL == T)
        return TRUE;
    else
        return FALSE;
}

Status BreakBiTree(BiTree& T, BiTree& L, BiTree& R) {
    if (T == NULL)
        return ERROR;
    else {
        L = T->lchild;
        R = T->rchild;
        T->lchild = NULL;
        T->rchild = NULL;
        return OK;
    }
}

Status InOrder(BiTree T, Status (*visit)(TElemType e)) {
    if (NULL == T)
        return OK;
    if (ERROR == InOrder(T->lchild, visit))
        return ERROR;
    if (ERROR == visit(T->data))
        return ERROR;
    if (ERROR == InOrder(T->rchild, visit))
        return ERROR;
}

Status PreOrder(BiTree T, Status (*visit)(TElemType e)) {
    // �������������T��visit�Ƕ�����Ԫ�ز�����Ӧ�ú���
    if (NULL == T)
        return OK;
    if (ERROR == visit(T->data))
        return ERROR;
    if (ERROR == PreOrder(T->lchild, visit))
        return ERROR;                   //��2�����ʽ���������
    return PreOrder(T->rchild, visit);  //��3���ݹ����T��������
}

BiTNode* GoFarLeft(BiTree T, LStack& S) {  // ջS��Ԫ��������BiTree
    // ��T�������������֧�������룬ֱ�����֧Ϊ�յĽ�㣬��;�����ջS��
    if (NULL == T)
        return NULL;
    while (T->lchild != NULL) {
        Push_LS(S, T);
        T = T->lchild;
    }
    return T;
}

void InorderTraverse_I(BiTree T, Status (*visit)(TElemType e)) {
    // ����ǵݹ����������T��visit�Ƕ�����Ԫ�ز�����Ӧ�ú���
    LStack S;
    InitStack_LS(S);
    BiTree p;
    p = GoFarLeft(T, S);  // �ҵ������µĽ��
    while (p != NULL) {
        visit(p->data);
        if (p->rchild != NULL) {
            p = GoFarLeft(p->rchild, S);
        } else if (StackEmpty_LS(S) != TRUE)
            Pop_LS(S, p);
        else
            p = NULL;
    }
}

void PreorderTraverse_I(BiTree T, Status (*visit)(TElemType e)) {
    BiTree p = T;
    LStack s;
    InitStack_LS(s);
    Push_LS(s, NULL);  //����С����
    while (p != NULL) {
        visit(p->data);
        if (p->rchild != NULL)
            Push_LS(s, p->rchild);
        if (p->lchild != NULL)
            p = p->lchild;
        else
            Pop_LS(s, p);
    }
}

//�����������
TriTree CreateTriTree(char* definition, int& i) {
    /* �������������������н���ֵ(��Ϊ�ַ��ͻ����ͣ��������ж���)��*/
    /* �������������ʾ�Ķ�����T */
    TriTree T;
    TElemType ch;
    ch = definition[i++];
    if ('#' == ch)
        T = NULL;
    else {
        T = (TriTree)malloc(sizeof(TriTNode)); /* ��̬���ɸ���� */
        if (NULL == T)
            return NULL;

        T->data = ch;     /* ������㸳ֵ */
        T->parent = NULL; /* �������˫�� */
        T->lchild = CreateTriTree(definition, i);
        if (T->lchild)             /* ������ */
            T->lchild->parent = T; /* �����ӵ�˫����ֵ */
        T->rchild = CreateTriTree(definition, i);
        if (T->rchild)             /* ���Һ��� */
            T->rchild->parent = T; /* ���Һ��ӵ�˫����ֵ */
    }
    return T;
}

Status PreOrderTraverse_Tri(TriTree T, Status (*visit)(TElemType e)) {
    // ����ǵݹ����������T��visit�Ƕ�����Ԫ�ز�����Ӧ�ú���
    TriTree p, pr;
    if (T != NULL) {
        p = T;
        while (p != NULL) {
            visit(p->data);
            if (p->lchild != NULL)
                p = p->lchild;
            else if (p->rchild != NULL)
                p = p->rchild;
            else {
                do {
                    pr = p;
                    p = p->parent;
                } while (p != NULL && p->rchild == pr || NULL == p->rchild);
                {
                    if (p != NULL)
                        p = p->rchild;
                }
            }
        }
    }
    return OK;
}

void LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e)) {
    // ��α���������T��visit�Ƕ�����Ԫ�ز�����Ӧ�ú���
    if (T != NULL) {
        LQueue Q;
        InitQueue_LQ(Q);
        BiTree p = T;
        visit(p->data);
        EnQueue_LQ(Q, p);
        while (OK == DeQueue_LQ(Q, p)) {
            if (p->lchild != NULL) {
                visit(p->lchild->data);
                EnQueue_LQ(Q, p->lchild);
            }
            if (p->rchild != NULL) {
                visit(p->rchild->data);
                EnQueue_LQ(Q, p->rchild);
            }
        }
    }
}

void CopyTree(BiTree T, BiTree& T1)  //����������,��T������T1
{
    if (T == NULL)
        return;
    BiTree L, R;
    // cout << "xx" << endl;
    L = R = NULL;
    CopyTree(T->lchild, L);
    CopyTree(T->rchild, R);
    T1 = MakeBiTree(T->data, L, R);
}
int equal(BiTree a, BiTree b) {
    //�ж������������ǲ������,��ȷ���1,���ȷ���0
    if (!a and !b)
        return 1;
    if ((!a and b) or (a and !b))
        return 0;
    if ((!a->lchild and !b->lchild) or (!a->rchild and !b->rchild))
        return 0;
    if (a->data == b->data)
        return 1;

    return equal(a->lchild, b->lchild) & equal(a->rchild, b->rchild);
}

int main() {
    BiTree T;
    int count = 0;
    int depth;
    int i = 0;
    BiTree T1, T2, T3, L, R;
    BiTree T4, T5, T6;
    TriTree T7;
    char definition[11] = {'A', 'B', 'D', '#', '#', 'E',
                           '#', '#', 'C', '#', '#'};

    // T1=MakeBiTree(1,NULL,NULL);
    // T2=MakeBiTree(2,NULL,NULL);
    // T3=MakeBiTree(T1->data+T2->data,NULL,NULL);
    // ReplaceLeft(T3,T1);
    // ReplaceRight(T3,T2);
    // T4=MakeBiTree(4,NULL,NULL);
    // T5=MakeBiTree(5,NULL,NULL);
    // T6=MakeBiTree(T4->data+T5->data,T4,T5);
    // T=MakeBiTree(T3->data+T6->data,T3,T6);

    T = CreateBiTree(definition, i);
    CountLeaf(T, count);
    printf("Ҷ������:%d ", count);
    depth = BiTreeDepth(T);
    printf("\n");
    printf("��ȣ�%d ", depth);
    printf("\n�ǵݹ����:\n");
    InorderTraverse_I(T, visit);
    printf("\n��α���:\n");
    LevelOrderTraverse(T, visit);
    printf("\n");
    printf("�������1:\n");
    PreorderTraverse_I(T, visit);
    printf("\n");
    printf("�������2:\n");
    PreOrder(T, visit);
    printf("\n");
    printf("�������:\n");
    InOrderTraverse(T, visit);
    printf("\n");
    // DestroyBiTree(T);
    // printf("���ٳɹ�\n");
    CopyTree(T, T6);

    printf("\nT,T6�Ƿ����:%d\n", equal(T6, T));
    int count1;
    count1 = 0;
    Degree1(T, count1);
    printf("����Ϊ1��ĸ���:%d", count1);
    i = 0;
    T7 = CreateTriTree(definition, i);
    printf("���������������:\n");
    PreOrderTraverse_Tri(T7, visit);

    //  BreakBiTree(T,L,R);
    // MakeBiTree(T->data,L,R);
}
