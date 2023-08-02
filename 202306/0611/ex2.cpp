#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIME_SLICE 2

// 进程状态：就绪 等待 阻塞 完成
enum process_type{
    process_type_wait = 'W',
    process_type_run = 'R',
    process_type_block = 'B',
    process_type_finish = 'F'
};

typedef struct PCB{ 
    // 进程名 
    char name;
    // 最大需求资源数
    int Max[100]; 
    // 还需要的资源数
    int Need[100];
    // 已分配的资源数 
    int Allocate[100]; 
    // 进程已运行时间 
    int run_time; 
    // 进程状态
    char state;
    // 指向下一个进程
    PCB *next; 
}PCB; 

// 系统资源的名称
char Name[100]={0};
// 系统可用资源向量 
int Available[100];
// 进程请求资源向量 
int Request[100];
// 存放系统可提供资源量
int Work[100];  
// 标记系统是否有足够的资源分配给各个进程
bool Finish[100];
// 存放安全序列
char Security[100];

// 进程的最大数
int M = 100;
// 资源的最大数
int N = 100;
// 标志是否输出
bool flag = true; 
// 函数声明
// 初始化数据
void init(PCB *list);
// 创建进程 
void create_process(PCB *list);
// 显示资源分配和进程运行情况 
void print(PCB *list);
// 试探性分配资源
void test(PCB *list);
// 试探性分配资源作废
void Retest(PCB *list);
// 利用银行家算法对申请资源进行试分
bool bank(PCB *list);
// 安全性算法
bool safe(PCB *list);
// 时间片轮转调度算法 
void round_robin(PCB *list);
// 主函数
int main(){ 
    printf("-----------------------------------------------------------------------\n");
    printf("||                        银行家算法的实现                           ||\n");
    printf("-----------------------------------------------------------------------\n\n");
    PCB *list = (PCB *)malloc(sizeof(PCB));
    if(list == NULL){
        printf("动态分配内存失败！");
    }
    list->next = NULL;
    
    srand((int)time(NULL));
    // 初始化数据
    init(list);
    // 显示资源分配和进程运行情况 
    printf("***********************************************************************\n");
    print(list);
    // 用银行家算法判定系统当前时刻是否安全，不安全就不再继续分配资源 
    if(!safe(list)) {
        exit(0);
    }
    printf("\n***********************************************************************\n");
    // 使用时间片轮转法进行进程调度 
    round_robin(list); 
}
// 初始化数据
void init(PCB *list){
    // m为进程数，n为系统资源种类
    int m,n;
    // 初始化系统资源种类数及各资源数 
    printf("系统可用资源种类数为：");
    scanf("%d",&n);
    // 系统资源种类数，赋给全局变量N，方便后续方法使用 
    N = n;
    // 资源名称
    char name;
    // 资源数 
    int number; 
    for(int i = 1;i <= n;i++){
        printf("\t资源%d的名称：",i);
        getchar();
        scanf("%c",&name);
        Name[i] = name;
        printf("\t资源%c的初始个数为：",name); 
        scanf("%d",&number);
        Available[i] = number;
    }
    // 初始化进程数及各进程的最大需求资源数 
    printf("\n请输入进程的数量：");    
    scanf("%d",&m);
    // 进程数，赋给全局变量M，方便后续方法使用 
    M = m;
    create_process(list);
}
// 创建进程 
void create_process(PCB *list){
    // 统计已分配的系统资源
    int temp[100] = {0};
    int number = 1; 
    while(number <= M){
        // 进程节点 
        PCB *p = (PCB *)malloc(sizeof(PCB));
        if(p == NULL){
            printf("动态分配内存失败！");
        }
        // 进程名 
        printf("\t请输入第%d进程的进程名：",number); 
        getchar();
        scanf("%c",&p->name);
        // 标志变量 
        bool flag;
        // 初始化各进程最大需求资源数、仍需资源数和已分配资源数
        do{
            flag = false; 
            for(int i = 1;i <= N;i++){ 
                p->Max[i] = rand()%10;
                if(p->Max[i] > Available[i]){ 
                    flag = true;
                    // printf("资源最大需求量大于系统中资源最大数，请重新输入!\n");
                    break;  
                }
                p->Need[i] = p->Max[i];
                p->Allocate[i] = 0;     
            }               
        }while(flag);
        // 进程已运行时间 
        p->run_time = 0; 
        // 进程状态
        p->state = process_type_wait;
        // 指向下一个进程
        p->next = NULL;
        if(list->next == NULL){
            list->next = p;
        }else{
            PCB *move = list->next;
            while(move->next != NULL){
                move = move->next;
            }
            move->next = p;     
        }
        number++;
    }
    printf("\n");
} 
// 显示资源分配和进程运行情况 
void print(PCB *list){
    printf("\n系统目前可用的资源(Available):\n");
    for(int i = 1;i <= N;i++){
        printf("%c  ",Name[i]);
    }
    printf("\n");
    for(int i = 1;i <= N;i++){
        printf("%d  ",Available[i]);
    }
    printf("\n\n");
    printf("系统当前的资源分配情况及进程运行情况如下：\n");
    printf("          Max        Allocate        Need\n");
    printf("进程名  ");
    //输出与进程名同行的资源名，Max、Allocate、Need下分别对应 
    for(int i = 1;i <= 3;i++){
        for(int j = 1;j <= N;j++){
            printf("%c  ",Name[j]);
        }
        printf("     "); 
    }
    printf("已运行时间   进程状态\n");
    
    // 遍历链表 
    PCB *p = list->next;
    while(p != NULL){
        //输出每个进程的Max、Allocation、Need 
        printf("  %c\t",p->name);
        for(int j = 1;j <= N;j++)
            printf("%d  ",p->Max[j]);
        printf("     "); 
        for(int j = 1;j <= N;j++)
            printf("%d  ",p->Allocate[j]);
        printf("     ");
        for(int j = 1;j <= N;j++)
            printf("%d  ",p->Need[j]);
        printf("        ");
        printf("  %d\t  ",p->run_time); 
        printf("%c\n",p->state); 
        p = p->next;
    }
}
// 试探性分配资源
void test(PCB *list){ 
    // 请求资源的进程 
    PCB *p = list->next;
    // 更改进程信息 
    for(int i = 1;i <= N;i++){
        Available[i] -= Request[i];
        p->Allocate[i] += Request[i];
        p->Need[i] -= Request[i];
    }
}
// 试探性分配资源作废
void Retest(PCB *list){
    // 请求资源的进程 
    PCB *p = list->next;
    // 与test操作相反 
    for(int i = 1;i <= N;i++){
        Available[i] += Request[i];
        p->Allocate[i] -= Request[i];
        p->Need[i] += Request[i];
    }
}
// 利用银行家算法对申请资源进行试分
bool bank(PCB *list){
    PCB *p = list->next;
    // 随机生成请求向量
    for(int i = 1;i <= N;++i){
        Request[i] = rand()%(p->Need[i]+1);
    }
    // 随机产生的请求资源数均为0，表示不理会 
    int n = 0;
    for(int i = 1;i <= N;++i){
        if(Request[i] == 0){
            n++;
        }
    }
    if(n == N){
        flag = false;
        return false;
    }
    printf("\n%c进程请求 —— ",p->name);
    for(int i = 1;i <= N;i++){
        printf("资源%c：",Name[i]);
        printf("%d   ",Request[i]); 
    }
    printf("\n\n"); 
    // 定位要求的资源数组下标 
    int num = 1;
    // 判断银行家算法的前两条件是否成立 
    for(int i = 1;i <= N;++i){
        // 判断申请是否大于需求，若大于则出错
        if(Request[i] > p->Need[i]){ 
            printf("%c进程申请的资源大于它需要的资源\n",p->name);
            printf("分配不合理，不予分配！\n");
            return false;
        }else{
            // 判断申请是否大于当前可分配资源，若大于则出错
            if(Request[i] > Available[i]){                         
                printf("%c进程申请的资源大于系统现可利用的资源\n",p->name);
                printf("系统尚无足够资源，不予分配!\n");
                return false;
            }
        }
    }
    // 前两个条件成立，试分配资源，寻找安全序列 
    // 根据进程需求量,试分配资源
    test(list); 
    // 判断系统是否安全 
    if(!safe(list)){
        Retest(list);
        return false;
    }
    return true;
}
// 安全性算法
bool safe(PCB *list){
    // 统计未完成进程数 
    int m = 0;
    PCB *move = list->next;
    while(move != NULL && move->state != process_type_finish){
        move = move->next;
        ++m;
    }
    // 初始化Work数组 
    for(int i = 1;i <= N;i++){
        Work[i] = Available[i];
    }
    // 初始化Finish数组 
    for(int i = 1;i <= M;i++){
        if(i <= m){
            Finish[i] = false;
        }else{
            Finish[i] = true;
        }
    } 
    // 节点位置，判断进程运行 
    int pnum = 1,apply;
    int num = 1;
    // 求安全序列 
    PCB *p = list->next; 
    while(p != NULL && pnum <= m){
        apply = 0;
        for(int i = 1;i <= N;i++){
            // 当前进程未完成并且各类资源小于或等于系统资源数 
            if(Finish[pnum] == false && p->Need[i] <= Work[i]){   
                apply++;
                // 直到每类资源尚需数都小于系统可利用资源数才可分配
                if(apply == N){  
                    for(int x = 1;x <= N;x++){
                        // 更新当前系统可分配资源
                        Work[x] += p->Allocate[x];
                    } 
                    // 更新标记数组 
                    Finish[pnum] = true;
                    // 更新安全序列数组 
                    Security[num++] = p->name;
                    // 保证每次查询均从第一个进程开始    
                    pnum = 0; 
                    p = list; 
                }
            }
        }
        // 查询下一进程 
        pnum++; 
        p = p->next;
    }
    for(int i = 1;i <= M;i++){
        if(Finish[i] == false){
            // 系统处于不安全状态 
            printf("系统不安全！\n");
            return false;
        }
    }
    // 如果安全，输出安全序列 
    printf("系统是安全的！\n");
    printf("存在一个安全序列:");
    for(int i = 1;i <= m;i++){
        // 输出进程运行顺序数组
        printf(" %c ",Security[i]);
        if(i < m){
            printf("->");
        } 
    }
    printf("\n");
    return true;
}
// 时间片轮转调度算法 
void round_robin(PCB *list){
    // 记录第一个结点的位置
    PCB *index = list->next;
    while (index != NULL && index->state != process_type_finish) {
        // 判断调度后是否输出 
        flag = true; 
        // 系统安全，进程分配到资源并运行 
        if(bank(list)){
            // 更新已运行时间
            index->run_time += TIME_SLICE;
            // 判断该进程是否完成 
            int num = 0;
            for(int i = 1;i <= N;++i){
                if(index->Max[i] == index->Allocate[i]){
                    num++;
                }   
            }
            // 该进程已完成 
            if (num == N) {
                // 修改进程状态
                index->state = process_type_finish;
                // 回收分配的资源
                for(int i = 1;i <= N;i++){
                    Available[i] += index->Allocate[i];
                }
                printf("%c进程完成\n",index->name);
            }else{
                // 进程未完成，进入等待 
                index->state = process_type_wait;
            }
            // 当前进程已完成 
            if (index->state == process_type_finish){
                // 将已完成进程调整到已完成队列末尾 
                // 1.头指针指向首元结点的下一个结点
                list->next = index->next;
                // 2.遍历整个链表，将其插入到已完成队列的最尾端
                PCB *p = list;
                while (p->next != NULL) {
                    p = p->next;
                }
                p->next = index;
                index->next = NULL;
            } else {
                // 当前进程未完成 
                // 1.头指针指向首元结点的下一个结点
                list->next = index->next;
                // 2.遍历整个链表，将其插入到等待队列的最尾端(其后是已完成队列)
                PCB *p = list;
                // 2.1寻找插入位置
                while (p->next != NULL && p->next->state != process_type_finish) {
                    p = p->next;
                }
                // 2.2判断插入位置
                if (p->next == NULL) {
                    // 最后一个
                    p->next = index;
                    p->next->next = NULL;
                }else{
                    // 不是最后一个，其后仍有结点
                    index->next = p->next;
                    p->next = index;
                }
            }   
        }else{
            // 该进程请求资源分配会导致系统不安全或请求资源不合理 
            // 将该进程阻塞并调整到等待队列和已完成队列中间，且是阻塞队列的最后一个 
            index->state = process_type_block;
            // 当前进程未完成并处于阻塞状态 
            // 1.头指针指向首元结点的下一个结点
            list->next = index->next;
            // 2.遍历整个链表，将其插入到未完成队列后阻塞队列的最后一个
            PCB *p = list;
            // 2.1寻找插入位置
            while (p->next != NULL && p->next->state != process_type_finish) {
                p = p->next;
            }
            // 2.2判断插入位置
            if (p->next == NULL) {
                // 最后一个
                p->next = index;
                p->next->next = NULL;
            }else{
                // 不是最后一个，其后仍有结点
                index->next = p->next;
                p->next = index;
            }
        }
        // 展示当前队列状况
        if(list->next->state != process_type_finish){
            list->next->state = process_type_run;           
        }
        if(flag){
            print(list);            
            printf("\n***********************************************************************\n");  
        }
        index = list->next;
    }
}
