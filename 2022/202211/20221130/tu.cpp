

typedef char VexType;

typedef enum { DG, DN, UDG, UDN } GraphKind;//图的四种类型：有向图，有向带权图，无向图和无向带权图

 

typedef struct {
    VexType* vexs; // 顶点数组，VexType是顶点类型，可由用户定义
    int** arcs;    // 关系数组，对无权图，用0或1表示相邻否；对带权图，则为权值或INFINITY
    int n, e;      // 顶点数和边（弧）数
    GraphKind kind;// 图的类型
    int* tags;     // 标志数组，遍历时可用于标记顶点访问与否
} MGraph;

typedef struct {
    VexType v, w;
    int info;
} ArcInfo;