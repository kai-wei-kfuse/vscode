#include <stdio.h>  //银行家算法
#include <stdlib.h>
#include <time.h>
int time_slice = 5;
enum ProcessState {
    Process_wait = 'W',
    Process_run = 'R',
    Process_block = 'B',
    Process_finish = 'F'
};
typedef struct process {
    int id;
    int Max[3];
    int Need[3];
    int Allocate[3];
    int run_time;
    char Process_state;
    process* next;

} process;
char Name[3] = {'A', 'B', 'C'};
int Available[3] = {10, 15, 8};
int Request[50];               // 请求资源数组
int Work[50];                  // 工作数组
bool Finish[100];              // 标记数组
int Security_queue[50];        // 安全序列
int Process_run_number = 5;    // 进程数
int Resources_number = 3;      // 资源数
int Process_wait_number = 10;  // 进程数
bool flag;

// 函数声明
void set_finish(process* run_queue, process* finish_queue);

void set_block(process* run_queue, process* block_queue);

void set_run(process* wair_queue, process* run_queue);

void print(process* run_queue, process* finish_queue, process* block_queue);

void init(process* wair_queue);

void soundout(process* run_queue);

void non_soundout(process* run_queue);

bool safe(process* run_queue);

bool banker(process* run_queue);

void RoundRobin(process* wair_queue,
                process* block_queue,
                process* run_queue,
                process* finish_queue);

// 函数定义
void set_finish(process* run_queue, process* finish_queue) {
    process* i = run_queue->next;
    process* j = finish_queue->next;
    process* z = finish_queue;
    if (run_queue == NULL) {
        return;
    }
    i->Process_state = Process_finish;
    while (j != NULL) {
        z = j;
        j = j->next;
    }
    z->next = i;
    run_queue->next = i->next;
    i->next = NULL;
}

void set_run(process* wair_queue, process* run_queue) {
    process* i = wair_queue->next;
    process* j = run_queue->next;
    process* z = run_queue;
    if (wair_queue->next == NULL) {
        return;
    }
    i->Process_state = Process_run;
    while (j != NULL) {
        z = j;
        j = j->next;
    }
    z->next = i;
    wair_queue->next = i->next;
    i->next = NULL;
}
void set_block(process* run_queue, process* block_queue) {
    process* i = run_queue->next;
    process* j = block_queue->next;
    process* z = block_queue;
    if (run_queue == NULL) {
        return;
    }
    i->Process_state = Process_block;
    while (j != NULL) {
        z = j;
        j = j->next;
    }
    z->next = i;
    run_queue->next = i->next;
    i->next = NULL;
}
void print(process* run_queue, process* finish_queue, process* block_queue) {
    system("cls");
    process* b = block_queue->next;
    process* r = run_queue->next;
    process* f = finish_queue->next;
    printf("运行队列:\n");
    if (r == NULL) {
        printf("无\n");
    } else {
        printf(
            " 资源名称\t最大需求资源\t需求资源\t已分配资源\t进程运行时间\t进程"
            "状态\t剩余资源\n");
    }
    while (r != NULL) {
        printf("进程id：%4d\n", r->id);
        for (int i = 0; i < Resources_number; i++) {
            if (i == 0)
                printf("%4c\t\t%4d\t\t%4d\t\t%4d\t\t%4d\t\t%4c\t\t%4d\n",
                       Name[i], r->Max[i], r->Need[i], r->Allocate[i],
                       r->run_time, r->Process_state, Available[i]);
            else {
                printf("%4c\t\t%4d\t\t%4d\t\t%4d\t\t%4d\t\t%4c\t\t%4d\n",
                       Name[i], r->Max[i], r->Need[i], r->Allocate[i],
                       r->run_time, r->Process_state, Available[i]);
            }
        }
        r = r->next;
    }
    printf("\n");
    printf("阻塞队列\n");
    if (b == NULL) {
        printf("无\n");
    } else {
        printf(
            " 资源名称\t最大需求资源\t需求资源\t已分配资源\t进程运行时间\t进程"
            "状态\t剩余资源\n");
    }
    while (b != NULL) {
        printf("进程id：%4d\n", b->id);
        for (int i = 0; i < Resources_number; i++) {
            if (i == 0)
                printf("%4c\t\t%4d\t\t%4d\t\t%4d\t\t%4d\t\t%4c\t\t%4d\n",
                       Name[i], b->Max[i], b->Need[i], b->Allocate[i],
                       b->run_time, b->Process_state, Available[i]);
            else {
                printf("%4c\t\t%4d\t\t%4d\t\t%4d\t\t%4d\t\t%4c\t\t%4d\n",
                       Name[i], b->Max[i], b->Need[i], b->Allocate[i],
                       b->run_time, b->Process_state, Available[i]);
            }
        }
        b = b->next;
    }
    printf("\n");
    printf("完成队列\n");
    if (f == NULL) {
        printf("无\n");
    } else {
        printf(
            " 资源名称\t最大需求资源\t需求资源\t已分配资源\t进程运行时间\t进程"
            "状态\t剩余资源\n");
    }
    while (f != NULL) {
        printf("进程名称：%4d\n", f->id);
        for (int i = 0; i < Resources_number; i++) {
            if (i == 0) {
                printf("%4c\t\t%4d\t\t%4d\t\t%4d\t\t%4d\t\t%4c\t\t%4d\n",
                       Name[i], f->Max[i], f->Need[i], f->Allocate[i],
                       f->run_time, f->Process_state, Available[i]);
            } else {
                printf("%4c\t\t%4d\t\t%4d\t\t%4d\t\t%4d\t\t%4c\t\t%4d\n",
                       Name[i], f->Max[i], f->Need[i], f->Allocate[i],
                       f->run_time, f->Process_state, Available[i]);
            }
        }
        f = f->next;
    }
    printf("\n");
    system("pause");
}
void init(process* wair_queue) {
    for (int number = 1; number <= Process_wait_number; number++) {
        bool flag = true;
        process* j;
        process* p = (process*)malloc(sizeof(process));
        if (p == NULL) {
            printf("分配动态内存失败");
        }
        p->id = number;
        while (flag) {
            flag = false;
            for (int i = 0; i < Resources_number; i++) {
                p->Max[i] = rand() % 4;
                if (p->Max[i] > Available[i]) {
                    flag = true;
                    break;
                }
                p->Need[i] = p->Max[i];
                p->Allocate[i] = 0;
            }
        }
        p->run_time = 0;
        p->Process_state = Process_wait;
        p->next = NULL;
        if (wair_queue->next == NULL) {
            wair_queue->next = p;
        } else {
            j = wair_queue->next;
            while (j->next != NULL) {
                j = j->next;
            }
            j->next = p;
        }
    }
}
void soundout(process* run_queue) {  // 安全状态
    process* i = run_queue->next;
    for (int j = 0; j < Resources_number; j++) {
        Available[j] = Available[j] - Request[j];
        i->Allocate[j] = i->Allocate[j] + Request[j];
        i->Need[j] = i->Need[j] - Request[j];
    }
}
void non_soundout(process* run_queue) {  // 不安全状态
    process* i = run_queue->next;
    for (int j = 0; j < Resources_number; j++) {
        Available[j] = Available[j] + Request[j];
        i->Allocate[j] = i->Allocate[j] - Request[j];
        i->Need[j] = i->Need[j] + Request[j];
    }
}
bool safe(process* run_queue) {  // 安全性算法
    // 统计进程数
    int m = 0;
    process* w = run_queue->next;
    while (w != NULL) {
        w = w->next;
        m++;
    }
    // 初始化Work数组
    for (int i = 0; i < Resources_number; i++) {
        Work[i] = Available[i];
    }
    // 初始化Finish数组
    for (int i = 0; i < Process_run_number; i++) {
        Finish[i] = false;
    }
    // 节点位置，判断进程运行
    int pnum = 0;
    int apply;
    int num = 0;
    // 求安全序列
    process* p = run_queue->next;
    while (p != NULL && pnum <= m) {
        apply = 1;
        for (int i = 0; i < Resources_number; i++) {
            // 当前进程未完成并且各类资源小于或等于系统资源数
            if (Finish[pnum] == false && p->Need[i] <= Work[i]) {
                apply++;
                // 直到每类资源尚需数都小于系统可利用资源数才可分配
                if (apply == Resources_number) {
                    for (int x = 0; x < Resources_number; x++) {
                        // 更新当前系统可分配资源
                        Work[x] += p->Allocate[x];
                    }
                    // 更新标记数组
                    Finish[pnum] = true;
                    // 更新安全序列数组
                    Security_queue[num++] = p->id;
                    // 保证每次查询均从第一个进程开始
                    pnum = 0;
                    p = run_queue;
                }
            }
        }
        // 查询下一进程
        pnum++;
        p = p->next;
    }
    for (int i = 0; i < m; i++) {
        if (Finish[i] == false) {
            // 系统处于不安全状态
            return false;
        }
    }
    return true;
}
bool banker(process* run_queue) {
    process* p = run_queue->next;
    srand((int)time(NULL));
    for (int i = 0; i < Resources_number; i++) {
        Request[i] = rand() % (p->Need[i] + 1);
    }
    int n = 0;
    for (int i = 0; i < Resources_number; i++) {
        if (Request[i] == 0) {
            n++;
        }
    }
    if (n == Resources_number) {
        flag = false;
        return false;
    }
    int num = 1;
    for (int i = 0; i < Resources_number; i++) {
        if (Request[i] > p->Need[i]) {
            return false;
        } else {
            if (Request[i] > Available[i]) {
                return false;
            }
        }
    }
    soundout(run_queue);
    if (!safe(run_queue)) {
        non_soundout(run_queue);
        return false;
    }
    return true;
}
void RoundRobin(process* wair_queue,
                process* block_queue,
                process* run_queue,
                process* finish_queue) {  // 轮转调度算法
    int number = 0;
    int judge = 0;
    for (int i = 0; i < Process_run_number; i++) {
        set_run(wair_queue, run_queue);
        number++;
    }
    int judge2 = 0;
    print(run_queue, finish_queue, block_queue);
    process* index = run_queue->next;
    while ((wair_queue->next != NULL || block_queue->next != NULL ||
            run_queue->next != NULL) &&
           number <= Process_run_number) {
        index->run_time = time_slice + index->run_time;
        index->Process_state = Process_run;
        if (banker(run_queue)) {
            int num = 0;
            for (int i = 0; i < Resources_number; i++) {
                if (index->Max[i] == index->Allocate[i]) {
                    num++;
                }
            }
            if (num == Resources_number) {
                set_finish(run_queue, finish_queue);
                print(run_queue, finish_queue, block_queue);
                for (int i = 0; i < Resources_number; i++) {
                    Available[i] += index->Allocate[i];
                }
                number--;
                judge = 1;
            } else {
                index->Process_state = Process_wait;
                run_queue->next = index->next;
                process* p = run_queue;
                while (p->next != NULL) {
                    p = p->next;
                }
                p->next = index;
                p->next->next = NULL;
                print(run_queue, finish_queue, block_queue);
            }
        } else {
            set_block(run_queue, block_queue);
            for (int i = 0; i < Resources_number; i++) {
                Available[i] += index->Allocate[i];
                index->Allocate[i] = 0;
                index->Need[i] = index->Max[i];
            }
            number--;
            print(run_queue, finish_queue, block_queue);
            judge2 = 1;
        }
        if (number < 5 && judge == 1) {
            if (block_queue->next != NULL)
                set_run(block_queue, run_queue);
            else {
                set_run(wair_queue, run_queue);
            }
            print(run_queue, finish_queue, block_queue);
            number++;
            judge = 0;
        }
        if (number < 5 && judge2 == 1) {
            if (wair_queue->next != NULL)
                set_run(wair_queue, run_queue);
            else {
                set_run(block_queue, run_queue);
            }
            number++;
            judge2 = 0;
        }
        index = run_queue->next;
    }
}
int main() {
    process* wair_queue = (process*)malloc(sizeof(process));
    process* run_queue = (process*)malloc(sizeof(process));
    process* block_queue = (process*)malloc(sizeof(process));
    process* finish_queue = (process*)malloc(sizeof(process));
    srand((int)time(NULL));
    if (wair_queue == NULL && run_queue == NULL && block_queue == NULL &&
        finish_queue) {
        printf("动态分配内存失败");
    }
    wair_queue->next = NULL;
    run_queue->next = NULL;
    block_queue->next = NULL;
    finish_queue->next = NULL;
    init(wair_queue);
    RoundRobin(wair_queue, block_queue, run_queue, finish_queue);
}
