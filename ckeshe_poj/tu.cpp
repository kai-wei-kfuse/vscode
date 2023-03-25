#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef char VexType;

typedef enum {
    DG,
    DN,
    UDG,
    UDN
} GraphKind;  //图的四种类型：有向图，有向带权图，无向图和无向带权图

#define Status int
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define INFINITY 1e9 + 7
#define VISITED 1
#define UNVISITED 0

// VexType* vexs;

typedef struct {
    VexType* vexs;   // 顶点数组，VexType是顶点类型，可由用户定义
    int** arcs;      // 关系数组，对无权图，用0或1表示相邻否；对带权图，则为权值或INFINITY
    int n, e;        // 顶点数和边（弧）数
    GraphKind kind;  // 图的类型
    int* tags;       // 标志数组，遍历时可用于标记顶点访问与否
} MGraph;

Status visit(int v) {
    printf("%d ",v);
    return OK;
}

typedef struct {
    VexType v, w;  //边的端点
    int info;      //边权
} ArcInfo;         //边信息

typedef int ElemType;
typedef struct {
    ElemType* base;  // 存储空间的基址
    int front;
    int rear;
    int maxSize;
} SqQueue;

Status InitQueue_Sq(SqQueue& Q, int size) {               // 构造一个空队列
    Q.base = (ElemType*)malloc(size * sizeof(ElemType));  // 分配存储空间
    if (NULL == Q.base) return OVERFLOW;
    Q.maxSize = size;
    Q.front = Q.rear = 0;  // 置Q为空队列
    return OK;
}

Status DeQueue_Sq(SqQueue& Q, ElemType& e) {
    // 若队列不空，则删除队列Q中的头元素，用 e 返回其值
    if (Q.front == Q.rear) return FALSE;  // 队空报错
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % Q.maxSize;  // Q.front循环加1
    return TRUE;
}

Status EnQueue_Sq(SqQueue& Q, ElemType e) {
    // 若当前队列不满，在队列的尾元素之后，插入元素 e 为新的队列尾元素
    if ((Q.rear + 1) % Q.maxSize == Q.front) return FALSE;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % Q.maxSize;
    return TRUE;
}
Status DestroyQueue_Sq(SqQueue& Q) {  // 销毁队列Q，Q不再存在
    free(Q.base);
    Q.base = NULL;
    Q.front = Q.rear = 0;
    return OK;
}

Status InitGraph_M(MGraph& G, GraphKind kind, VexType* vexs, int n);
//初始化含 n个顶点且无边的 kind 类的图 G//
Status CreateGraph_M(MGraph& G, GraphKind kind, VexType* vexs, int n, ArcInfo* arcs, int e);
//创建 n 个顶点和 e条边的 kind 类的图 G,vexs 为顶点信息，arcs 为边信息/
Status DestroyGraph_M(MGraph& G);
//销毁图 G/
int LocateVex_M(MGraph G, VexType v);
//查找顶点v在图G中的位序/
Status GetVex_M(MGraph G, int k, VexType& w);
//取图G的k顶点的值到 w/
Status PutVex_M(MGraph G, int k, VexType w);
//对图G的k顶点赋值 w/
int FirstAdjVex_M(MGraph G, int k);
//求图 G 中k 顶点的第一个邻接顶点的位序/
int NextAdjVex_M(MGraph G, int k, int m);
// m顶点为 k 顶点的邻接顶点,求图 G中k 顶点相对于m 顶点的下一个邻接顶点的位序/
Status AddArc_M(MGraph& G, int k, int m, int info);
//在图G中增加 k 顶点到m 顶点的边或弧,若为带权图,nfo为权值,否则为1/
Status RemoveArc_M(MGraph& G, int k, int m);
//在图G 中删除k 顶点到m 顶点的边或弧
Status DFS_M(MGraph G, int k, Status (*visit)(int));
//深度优先遍历图G
Status BFS_M(MGraph G, int k, Status (*visit)(int));
//广度优先遍历图G

Status InitGraph_M(MGraph& G, GraphKind kind, VexType* vexs, int n)
//初始化含 n个顶点且无边的 kind 类的图 G
{
    int i, j, info;
    if (n < 0 || (n > 0 && vexs == NULL))
        return ERROR;
    info = 0;
    // if (kind == DG || kind == UDG)
    //     info = 0;
    // else if (kind == DN || kind == UDN)
    //     info = INFINITY;
    // else
    //     return ERROR;
    G.n = n, G.e = 0;
    G.kind = kind;
    if (0 == n) return OK;
    if ((G.vexs = (VexType*)malloc(n * sizeof(VexType))) == NULL)
        return OVERFLOW;
    for (i = 0; i < G.n; i++) {  ///建立顶点数组
        G.vexs[i] = vexs[i];
    }
    if ((G.arcs = (int**)malloc(n * sizeof(int*))) == NULL)  //分配指针数组
        return OVERFLOW;
    for (i = 0; i < n; i++) {
        //分配每个指针所指向的数组
        if ((G.arcs[i] = (int*)malloc(n * sizeof(int))) == NULL)  //再给每个数组分配
            return OVERFLOW;
    }
    if ((G.tags = (int*)malloc(n * sizeof(int))) == NULL) return OVERFLOW;
    for (i = 0; i < n; i++) {  //初始化标志数组和关系数组
        G.tags[i] = UNVISITED;
        for (j = 0; j < n; j++)
            G.arcs[i][j] = info;
    }
    return OK;
}
Status CreateGraph_M(MGraph& G, GraphKind kind, VexType* vexs, int n, ArcInfo* arcs, int e) {
    //创建含n个顶点和e条边的无向图 G,vexs 为顶点信息,arcs 为边信息
    int i, j, k;
    VexType v, w;
    if (InitGraph_M(G, G.kind, vexs, n) != OK)
        return ERROR;  //初始化
    G.e = e;                     //边数
    for (k = 0; k < G.e; k++) {  //建立关系数组
        v = arcs[k].v;
        w = arcs[k].w;  //读入边(v,w)i = LocateVex_M(G,v);j = LocateVex_M(G,w);
       // cout << v << ' ' << w << endl;
        i = LocateVex_M(G, v);
        j = LocateVex_M(G, w);
       // cout << i << ' ' << j << endl;
        //确定 和w在顶点数组中的位序 i和i
        if (i < 0 || j < 0)
            return ERROR;
        G.arcs[i][j] = G.arcs[j][i] = 1;
        //对应行列的元素赋值为1
    }
    return OK;
}
int FirstAdjVex_M(MGraph G, int k) {  //求图G中k顶点的第一个邻接顶点的位序
    int i;
    if (k < 0 || k >= G.n) return ERROR;  // k 顶点不存在
    for (i = 0; i < G.n; i++) {           //查找第一个值非零且非 的元素
        // if ((G.kind == UDG || G.kind == DG) && G.arcs[k][i] != 0)
        //     return i;
        // else if ((G.kind == UDN || G.kind == DN) && G.arcs[k][i] != INFINITY)
        //     return i;
        if (G.arcs[k][i] == 1) {
            return i;
        }
    }
    return ERROR;  // k 顶点无邻接顶点
}
int NextAdjVex_M(MGraph G, int k, int m) {
    int i = 0;
    if (G.n == 0 && k == 0 && m == 0) return ERROR;
    for (i = m + 1; i < G.n; i++) {
        if (G.arcs[k][i] ==1)
            return i;
    }
    return -1;
}
Status DestroyGraph_M(MGraph& G) {
    free(G.tags);
    free(G.arcs);
    free(G.vexs);
    G.e = 0;
    G.n = 0;
    return OK;
}
int LocateVex_M(MGraph G, VexType v) {
    for (int i = 0; i < G.n; i++) {
        if (G.vexs[i] == v) {
            return i;
        }
    }
    return ERROR;
}
Status GetVex_M(MGraph G, int k, VexType& w) {
    //取图G的k顶点的值到 w
    if (k > G.e || k < 0) return ERROR;
    w = G.vexs[k];
    return OK;
}
Status PutVex_M(MGraph G, int k, VexType w) {
    //对图G的k顶点赋值 w
    if (k > G.e || k < 0) return ERROR;
    w = G.vexs[k];
    return OK;
}
Status AddArc_M(MGraph& G, int k, int m, int info) {
    //在图G中增加 k 顶点到m 顶点的边或弧,若为带权图,nfo为权值,否则为1
    if (k > G.e || k < 0) return ERROR;
    if (m > G.e || m < 0) return ERROR;
    G.arcs[k][m] = G.arcs[m][k] = 1;
    return OK;
}
Status RemoveArc_M(MGraph& G, int k, int m) {
    //在图G 中删除k 顶点到m 顶点的边或弧
    if (k > G.e || k < 0) return ERROR;
    if (m > G.e || m < 0) return ERROR;
    G.arcs[k][m] = G.arcs[m][k] = 0;
    return OK;
}
Status DFS_M(MGraph G, int k, Status (*visit)(int)) {
    //深度优先遍历图G
    int i;
    if (visit(k) == ERROR) return ERROR;
    printf("%c\n", G.vexs[k]);
    G.tags[k] = VISITED;
    for (i = FirstAdjVex_M(G, k); i >= 0; i = NextAdjVex_M(G, k, i)) {
        if (G.tags[i] == UNVISITED) {
            if (DFS_M(G, i, visit)) return ERROR;
        }
    }
    return OK;
}
Status BFS_M(MGraph G, int k, Status (*visit)(int)) {
    //广度优先遍历图G
    SqQueue Q;
    InitQueue_Sq(Q, 10);
    if (ERROR == visit(k)) return ERROR;
    printf("%c\n", G.vexs[k]);
    G.tags[k] = VISITED;
    EnQueue_Sq(Q, k);                 // 访问i顶点，并入队
    while (OK == DeQueue_Sq(Q, k)) {  // 出队元素到 k
        for (int i = 0; i < G.n; i++) {
            if (G.arcs[k][i] ==1 && UNVISITED == G.tags[i]) {
                if (ERROR == visit(i)) return ERROR;
                printf("%c\n", G.vexs[i]);
                G.tags[i] = VISITED;
                EnQueue_Sq(Q, i);
            }
        }
    }
    DestroyQueue_Sq(Q);
    return OK;
}
void print(MGraph G){
    printf("- A B C D E\n");
    for (int i = 0; i < G.n;i++){
        printf("%c ", G.vexs[i]);
        for (int j = 0; j < G.n;j++){
            printf("%d ", G.arcs[i][j]);
        }
        printf("\n");
    }
    return;
}
int main() {
    //图信息
    VexType vexs[5] = {'A', 'B', 'C', 'D', 'E'};
    ArcInfo arcs[5] = { {'A', 'C', 1}, {'B', 'D', 1}, {'D', 'E', 1}, {'C', 'E', 1}, {'B', 'E', 1}};
    int n, e, i;
    MGraph G;
    n = 5;
    e = 5;
    //建图
    if (CreateGraph_M(G, UDG, vexs, n, arcs, e))
        printf("建图成功\n");
    print(G);
    //测试1:查找顶点v在图G中的位序
    printf("测试1:查找顶点v在图G中的位序\n");
    for (char a = 'A'; a <= 'E'; a++) {
        printf("%c:%d\n",a,LocateVex_M(G, a));
    }
    printf("测试2:求图 G 中k 顶点的第一个邻接顶点的位序\n");
    for (int i = 0; i <= 4; i++) {
        printf("%c:", vexs[i]);
        printf("%c\n", vexs[FirstAdjVex_M(G, i)]);
    }
    printf("测试3:深度优先遍历图G\n");
    DFS_M(G,0,visit);
    for (int i = 0; i < G.n;i++){
        G.tags[i] = UNVISITED;
    }
        printf("测试4:广度优先遍历图G\n");
    BFS_M(G, 0, visit);
    printf("测试5:在图G中增加 2:C 顶点到3:D 顶点的边\n");
    AddArc_M(G,2,3,1);
    print(G);
    printf("测试6:在图G中删除 2:C 顶点到3:D 顶点的边\n");
    RemoveArc_M(G, 2, 3);
    print(G);
    return 0;
}
