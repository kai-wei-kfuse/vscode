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
} GraphKind;  //ͼ���������ͣ�����ͼ�������Ȩͼ������ͼ�������Ȩͼ

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
    VexType* vexs;   // �������飬VexType�Ƕ������ͣ������û�����
    int** arcs;      // ��ϵ���飬����Ȩͼ����0��1��ʾ���ڷ񣻶Դ�Ȩͼ����ΪȨֵ��INFINITY
    int n, e;        // �������ͱߣ�������
    GraphKind kind;  // ͼ������
    int* tags;       // ��־���飬����ʱ�����ڱ�Ƕ���������
} MGraph;

Status visit(int v) {
    printf("%d ",v);
    return OK;
}

typedef struct {
    VexType v, w;  //�ߵĶ˵�
    int info;      //��Ȩ
} ArcInfo;         //����Ϣ

typedef int ElemType;
typedef struct {
    ElemType* base;  // �洢�ռ�Ļ�ַ
    int front;
    int rear;
    int maxSize;
} SqQueue;

Status InitQueue_Sq(SqQueue& Q, int size) {               // ����һ���ն���
    Q.base = (ElemType*)malloc(size * sizeof(ElemType));  // ����洢�ռ�
    if (NULL == Q.base) return OVERFLOW;
    Q.maxSize = size;
    Q.front = Q.rear = 0;  // ��QΪ�ն���
    return OK;
}

Status DeQueue_Sq(SqQueue& Q, ElemType& e) {
    // �����в��գ���ɾ������Q�е�ͷԪ�أ��� e ������ֵ
    if (Q.front == Q.rear) return FALSE;  // �ӿձ���
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % Q.maxSize;  // Q.frontѭ����1
    return TRUE;
}

Status EnQueue_Sq(SqQueue& Q, ElemType e) {
    // ����ǰ���в������ڶ��е�βԪ��֮�󣬲���Ԫ�� e Ϊ�µĶ���βԪ��
    if ((Q.rear + 1) % Q.maxSize == Q.front) return FALSE;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % Q.maxSize;
    return TRUE;
}
Status DestroyQueue_Sq(SqQueue& Q) {  // ���ٶ���Q��Q���ٴ���
    free(Q.base);
    Q.base = NULL;
    Q.front = Q.rear = 0;
    return OK;
}

Status InitGraph_M(MGraph& G, GraphKind kind, VexType* vexs, int n);
//��ʼ���� n���������ޱߵ� kind ���ͼ G//
Status CreateGraph_M(MGraph& G, GraphKind kind, VexType* vexs, int n, ArcInfo* arcs, int e);
//���� n ������� e���ߵ� kind ���ͼ G,vexs Ϊ������Ϣ��arcs Ϊ����Ϣ/
Status DestroyGraph_M(MGraph& G);
//����ͼ G/
int LocateVex_M(MGraph G, VexType v);
//���Ҷ���v��ͼG�е�λ��/
Status GetVex_M(MGraph G, int k, VexType& w);
//ȡͼG��k�����ֵ�� w/
Status PutVex_M(MGraph G, int k, VexType w);
//��ͼG��k���㸳ֵ w/
int FirstAdjVex_M(MGraph G, int k);
//��ͼ G ��k ����ĵ�һ���ڽӶ����λ��/
int NextAdjVex_M(MGraph G, int k, int m);
// m����Ϊ k ������ڽӶ���,��ͼ G��k ���������m �������һ���ڽӶ����λ��/
Status AddArc_M(MGraph& G, int k, int m, int info);
//��ͼG������ k ���㵽m ����ı߻�,��Ϊ��Ȩͼ,nfoΪȨֵ,����Ϊ1/
Status RemoveArc_M(MGraph& G, int k, int m);
//��ͼG ��ɾ��k ���㵽m ����ı߻�
Status DFS_M(MGraph G, int k, Status (*visit)(int));
//������ȱ���ͼG
Status BFS_M(MGraph G, int k, Status (*visit)(int));
//������ȱ���ͼG

Status InitGraph_M(MGraph& G, GraphKind kind, VexType* vexs, int n)
//��ʼ���� n���������ޱߵ� kind ���ͼ G
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
    for (i = 0; i < G.n; i++) {  ///������������
        G.vexs[i] = vexs[i];
    }
    if ((G.arcs = (int**)malloc(n * sizeof(int*))) == NULL)  //����ָ������
        return OVERFLOW;
    for (i = 0; i < n; i++) {
        //����ÿ��ָ����ָ�������
        if ((G.arcs[i] = (int*)malloc(n * sizeof(int))) == NULL)  //�ٸ�ÿ���������
            return OVERFLOW;
    }
    if ((G.tags = (int*)malloc(n * sizeof(int))) == NULL) return OVERFLOW;
    for (i = 0; i < n; i++) {  //��ʼ����־����͹�ϵ����
        G.tags[i] = UNVISITED;
        for (j = 0; j < n; j++)
            G.arcs[i][j] = info;
    }
    return OK;
}
Status CreateGraph_M(MGraph& G, GraphKind kind, VexType* vexs, int n, ArcInfo* arcs, int e) {
    //������n�������e���ߵ�����ͼ G,vexs Ϊ������Ϣ,arcs Ϊ����Ϣ
    int i, j, k;
    VexType v, w;
    if (InitGraph_M(G, G.kind, vexs, n) != OK)
        return ERROR;  //��ʼ��
    G.e = e;                     //����
    for (k = 0; k < G.e; k++) {  //������ϵ����
        v = arcs[k].v;
        w = arcs[k].w;  //�����(v,w)i = LocateVex_M(G,v);j = LocateVex_M(G,w);
       // cout << v << ' ' << w << endl;
        i = LocateVex_M(G, v);
        j = LocateVex_M(G, w);
       // cout << i << ' ' << j << endl;
        //ȷ�� ��w�ڶ��������е�λ�� i��i
        if (i < 0 || j < 0)
            return ERROR;
        G.arcs[i][j] = G.arcs[j][i] = 1;
        //��Ӧ���е�Ԫ�ظ�ֵΪ1
    }
    return OK;
}
int FirstAdjVex_M(MGraph G, int k) {  //��ͼG��k����ĵ�һ���ڽӶ����λ��
    int i;
    if (k < 0 || k >= G.n) return ERROR;  // k ���㲻����
    for (i = 0; i < G.n; i++) {           //���ҵ�һ��ֵ�����ҷ� ��Ԫ��
        // if ((G.kind == UDG || G.kind == DG) && G.arcs[k][i] != 0)
        //     return i;
        // else if ((G.kind == UDN || G.kind == DN) && G.arcs[k][i] != INFINITY)
        //     return i;
        if (G.arcs[k][i] == 1) {
            return i;
        }
    }
    return ERROR;  // k �������ڽӶ���
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
    //ȡͼG��k�����ֵ�� w
    if (k > G.e || k < 0) return ERROR;
    w = G.vexs[k];
    return OK;
}
Status PutVex_M(MGraph G, int k, VexType w) {
    //��ͼG��k���㸳ֵ w
    if (k > G.e || k < 0) return ERROR;
    w = G.vexs[k];
    return OK;
}
Status AddArc_M(MGraph& G, int k, int m, int info) {
    //��ͼG������ k ���㵽m ����ı߻�,��Ϊ��Ȩͼ,nfoΪȨֵ,����Ϊ1
    if (k > G.e || k < 0) return ERROR;
    if (m > G.e || m < 0) return ERROR;
    G.arcs[k][m] = G.arcs[m][k] = 1;
    return OK;
}
Status RemoveArc_M(MGraph& G, int k, int m) {
    //��ͼG ��ɾ��k ���㵽m ����ı߻�
    if (k > G.e || k < 0) return ERROR;
    if (m > G.e || m < 0) return ERROR;
    G.arcs[k][m] = G.arcs[m][k] = 0;
    return OK;
}
Status DFS_M(MGraph G, int k, Status (*visit)(int)) {
    //������ȱ���ͼG
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
    //������ȱ���ͼG
    SqQueue Q;
    InitQueue_Sq(Q, 10);
    if (ERROR == visit(k)) return ERROR;
    printf("%c\n", G.vexs[k]);
    G.tags[k] = VISITED;
    EnQueue_Sq(Q, k);                 // ����i���㣬�����
    while (OK == DeQueue_Sq(Q, k)) {  // ����Ԫ�ص� k
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
    //ͼ��Ϣ
    VexType vexs[5] = {'A', 'B', 'C', 'D', 'E'};
    ArcInfo arcs[5] = { {'A', 'C', 1}, {'B', 'D', 1}, {'D', 'E', 1}, {'C', 'E', 1}, {'B', 'E', 1}};
    int n, e, i;
    MGraph G;
    n = 5;
    e = 5;
    //��ͼ
    if (CreateGraph_M(G, UDG, vexs, n, arcs, e))
        printf("��ͼ�ɹ�\n");
    print(G);
    //����1:���Ҷ���v��ͼG�е�λ��
    printf("����1:���Ҷ���v��ͼG�е�λ��\n");
    for (char a = 'A'; a <= 'E'; a++) {
        printf("%c:%d\n",a,LocateVex_M(G, a));
    }
    printf("����2:��ͼ G ��k ����ĵ�һ���ڽӶ����λ��\n");
    for (int i = 0; i <= 4; i++) {
        printf("%c:", vexs[i]);
        printf("%c\n", vexs[FirstAdjVex_M(G, i)]);
    }
    printf("����3:������ȱ���ͼG\n");
    DFS_M(G,0,visit);
    for (int i = 0; i < G.n;i++){
        G.tags[i] = UNVISITED;
    }
        printf("����4:������ȱ���ͼG\n");
    BFS_M(G, 0, visit);
    printf("����5:��ͼG������ 2:C ���㵽3:D ����ı�\n");
    AddArc_M(G,2,3,1);
    print(G);
    printf("����6:��ͼG��ɾ�� 2:C ���㵽3:D ����ı�\n");
    RemoveArc_M(G, 2, 3);
    print(G);
    return 0;
}
