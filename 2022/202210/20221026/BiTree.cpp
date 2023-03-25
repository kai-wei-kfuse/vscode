#include "BiTree.h"
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
// typedef int Status;  // Status是函数的类型,其值是函数结果状态代码，如OK等

// typedef int Status;
//
// typedef char TElemType;    // 假设二叉树结点的元素类型为字符
//
// typedef struct  BiTNode {
//     TElemType   data;                     // 数据域
//     struct BiTNode   *lchild,*rchild;    // 左、右孩子指针
// }BiTNode,*BiTree;

Status InitBiTree(BiTree& T) {
    // 操作结果: 构造空二叉树T
    T = NULL;
    return OK;
}

Status visit(TElemType e) {
    printf("%c ", e);
    return OK;
}

BiTree MakeBiTree(TElemType e, BiTree L, BiTree R) {
    // 创建一棵二叉树T，其中根结点的值为e，L和R分别作为左子树和右子树
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
    // 替换左子树。若T非空，则用LT替换T的左子树，并用LT返回T的原有左子树
    BiTree temp;
    if (NULL == T)
        return ERROR;
    temp = T->lchild;
    T->lchild = LT;
    LT = temp;
    return OK;
}

Status ReplaceRight(BiTree& T, BiTree& RT) {
    // 替换右子树。若T非空，则用RT替换T的右子树，并用RT返回T的原有右子树
    BiTree temp;
    if (NULL == T)
        return ERROR;
    temp = T->rchild;
    T->rchild = RT;
    RT = temp;
    return OK;
}

Status CutLeft(BiTree& T, BiTree& LT) {
    // 断开左子树，若T非空，则断开T的左子树，并赋给LT
    if (NULL == T)
        return ERROR;
    LT = T->lchild;
    T->lchild = NULL;
    return OK;
}

Status CutRight(BiTree& T, BiTree& RT) {
    // 剪除右子树。若T非空，则剪除T的右子树，并用RT返回
    if (NULL == T)
        return ERROR;
    RT = T->rchild;
    T->rchild = NULL;
    return OK;
}

Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e)) {
    // 中序遍历二叉树T，visit是对数据元素操作的应用函数
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
    // 按definition先序构造二叉树的二叉链表，i为definition的当前位标，初值为0
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

int BiTreeDepth(BiTree T) {  // 返回二叉树深度, T为树根的指针
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

void DestroyBiTree(BiTree& T) {    // 销毁二叉树T
    if (T != NULL) {               //二叉树非空
        DestroyBiTree(T->lchild);  //递归销毁左子树
        DestroyBiTree(T->rchild);  //递归销毁右子树
        free(T);                   //释放根结点
    }
}

Status BiTreeEmpty(BiTree T) {
    // 二叉树判空。若为空返回 TRUE，否则FALSE
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
    // 先序遍历二叉树T，visit是对数据元素操作的应用函数
    if (NULL == T)
        return OK;
    if (ERROR == visit(T->data))
        return ERROR;
    if (ERROR == PreOrder(T->lchild, visit))
        return ERROR;                   //（2）访问结点的数据域
    return PreOrder(T->rchild, visit);  //（3）递归遍历T的右子树
}

BiTNode* GoFarLeft(BiTree T, LStack& S) {  // 栈S的元素类型是BiTree
    // 从T结点出发，沿左分支不断深入，直到左分支为空的结点，沿途结点入栈S，
    if (NULL == T)
        return NULL;
    while (T->lchild != NULL) {
        Push_LS(S, T);
        T = T->lchild;
    }
    return T;
}

void InorderTraverse_I(BiTree T, Status (*visit)(TElemType e)) {
    // 中序非递归遍历二叉树T，visit是对数据元素操作的应用函数
    LStack S;
    InitStack_LS(S);
    BiTree p;
    p = GoFarLeft(T, S);  // 找到最左下的结点
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
    Push_LS(s, NULL);  //处理小技巧
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

//三叉链表相关
TriTree CreateTriTree(char* definition, int& i) {
    /* 按先序次序输入二叉树中结点的值(可为字符型或整型，在主程中定义)，*/
    /* 构造三叉链表表示的二叉树T */
    TriTree T;
    TElemType ch;
    ch = definition[i++];
    if ('#' == ch)
        T = NULL;
    else {
        T = (TriTree)malloc(sizeof(TriTNode)); /* 动态生成根结点 */
        if (NULL == T)
            return NULL;

        T->data = ch;     /* 给根结点赋值 */
        T->parent = NULL; /* 根结点无双亲 */
        T->lchild = CreateTriTree(definition, i);
        if (T->lchild)             /* 有左孩子 */
            T->lchild->parent = T; /* 给左孩子的双亲域赋值 */
        T->rchild = CreateTriTree(definition, i);
        if (T->rchild)             /* 有右孩子 */
            T->rchild->parent = T; /* 给右孩子的双亲域赋值 */
    }
    return T;
}

Status PreOrderTraverse_Tri(TriTree T, Status (*visit)(TElemType e)) {
    // 先序非递归遍历二叉树T，visit是对数据元素操作的应用函数
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
    // 层次遍历二叉树T，visit是对数据元素操作的应用函数
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

void CopyTree(BiTree T, BiTree& T1)  //拷贝二叉树,将T拷贝到T1
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
    //判断两个二叉树是不是相等,相等返回1,不等返回0
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
    printf("叶子数量:%d ", count);
    depth = BiTreeDepth(T);
    printf("\n");
    printf("深度：%d ", depth);
    printf("\n非递归遍历:\n");
    InorderTraverse_I(T, visit);
    printf("\n层次遍历:\n");
    LevelOrderTraverse(T, visit);
    printf("\n");
    printf("先序遍历1:\n");
    PreorderTraverse_I(T, visit);
    printf("\n");
    printf("先序遍历2:\n");
    PreOrder(T, visit);
    printf("\n");
    printf("中序遍历:\n");
    InOrderTraverse(T, visit);
    printf("\n");
    // DestroyBiTree(T);
    // printf("销毁成功\n");
    CopyTree(T, T6);

    printf("\nT,T6是否相等:%d\n", equal(T6, T));
    int count1;
    count1 = 0;
    Degree1(T, count1);
    printf("度数为1点的个数:%d", count1);
    i = 0;
    T7 = CreateTriTree(definition, i);
    printf("三叉链表先序遍历:\n");
    PreOrderTraverse_Tri(T7, visit);

    //  BreakBiTree(T,L,R);
    // MakeBiTree(T->data,L,R);
}
