#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct FreeSpace {
    int num;    // 分区号
    int start;  // 起始地址
    int size;   // 分区大小
    int state;
    int wordname;
    struct FreeSpace* next;
} FreeSpace;
typedef struct Word {
    int wordname;     // 作业名称
    int run_time;     // 作业运行时间
    char wordstate;   // 作业状态
    int papernumber;  // 作业请求空间
    int size;         // 作业请求空间
    struct Word* next;

} Word;
enum ProcessState { word_wait = 'W', word_run = 'R', word_finish = 'F' };
int Word_Number = 20;
int time_slice = 5;
int totalsize = 1024;
int papersize = 8;

// 函数声明
void Create_word(Word* wait_queue);

FreeSpace* initspace(FreeSpace* p);

void set_num(FreeSpace* space);

FreeSpace* sort_start(FreeSpace* space);

bool First_Fit(Word* word, FreeSpace* space);

void Recycle_Word(int wordname, FreeSpace* space);

void RoundRobin(Word* wait_queue,
                Word* run_queue,
                Word* finish_queue,
                FreeSpace* space);

void show(FreeSpace* space,
          Word* wait_queue,
          Word* finish_queue,
          Word* run_queue);

void set_finish(Word* run_queue, Word* finish_queue);

void set_run(Word* wait_queue, Word* run_queue);
// 函数定义

void set_finish(Word* run_queue, Word* finish_queue) {
    Word* i = run_queue->next;
    Word* j = finish_queue->next;
    Word* z = finish_queue;
    if (run_queue->next == NULL) {
        return;
    }
    i->wordstate = word_finish;
    while (j != NULL) {
        z = j;
        j = j->next;
    }
    z->next = i;
    run_queue->next = i->next;
    i->next = NULL;
}
void set_run(Word* wait_queue, Word* run_queue) {
    Word* i = wait_queue->next;
    Word* j = run_queue->next;
    Word* z = run_queue;
    if (wait_queue->next == NULL) {
        return;
    }
    i->wordstate = word_run;
    while (j != NULL) {
        z = j;
        j = j->next;
    }
    z->next = i;
    wait_queue->next = i->next;
    i->next = NULL;
}
void show(FreeSpace* space,
          Word* wait_queue,
          Word* finish_queue,
          Word* run_queue) {
    system("cls");
    FreeSpace* p = space;
    printf("内存分配情况:\n");
    printf("分区号\t起始地址\t分区大小\t分区状态\t分区作业名称\n");
    while (p != NULL) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d \n", p->num, p->start, p->size,
               p->state, p->wordname);
        p = p->next;
    }
    printf("\n");
    printf("作业运行情况：\n");
    Word* w = wait_queue->next;
    Word* r = run_queue->next;
    Word* f = finish_queue->next;
    printf("等待队列:\n");
    if (w == NULL) {
        printf("当前运行队列中没有进程\n");
    } else {
        printf("作业名称\t作业运行时间\t作业请求空间\t作业状态\n");
    }
    while (w != NULL) {
        printf("%d\t\t%d\t\t%d\t\t%c\n", w->wordname, w->run_time, w->size,
               w->wordstate);
        w = w->next;
    }
    printf("运行队列\n");
    if (r == NULL) {
        printf("当前运行队列中没有进程\n");
    } else {
        printf("作业名称\t作业运行时间\t作业请求空间\t作业状态\n");
    }
    while (r != NULL) {
        printf("%d\t\t%d\t\t%d\t\t%c\n", r->wordname, r->run_time, r->size,
               r->wordstate);
        r = r->next;
    }
    printf("完成队列\n");
    if (f == NULL) {
        printf("当前运行队列中没有进程\n");
    } else {
        printf("作业名称\t作业运行时间\t作业请求空间\t作业状态\n");
    }
    while (f != NULL) {
        printf("%d\t\t%d\t\t%d\t\t%c\n", f->wordname, f->run_time, f->size,
               f->wordstate);
        f = f->next;
    }
    printf("\n");
    system("pause");
}
void Create_word(Word* wait_queue) {
    for (int number = 1; number <= Word_Number; number++) {
        Word* p = (Word*)malloc(sizeof(Word));
        if (p == NULL) {
            printf("分配动态内存失败");
        }
        p->wordstate = 'W';
        p->wordname = number;
        p->papernumber = rand() % 10 + 1;
        p->size = (p->papernumber) * papersize;
        p->next = NULL;
        p->run_time = 0;
        if (wait_queue->next == NULL) {
            wait_queue->next = p;
        } else {
            Word* j = wait_queue;
            while (j->next != NULL) {
                j = j->next;
            }
            j->next = p;
        }
    }
}
FreeSpace* initspace(FreeSpace* p) {
    int i = totalsize / papersize;
    for (int a = 1; a <= i; a++) {
        // 如果为空则新创建一个
        FreeSpace* j = (FreeSpace*)malloc(sizeof(FreeSpace));
        // 分区号
        j->num = a;
        // 起始地址
        j->start = (a - 1) * 8;
        // 分区大小
        j->size = papersize;
        // 状态：0代表空闲，1代表占用
        j->state = 0;
        // 作业id
        j->wordname = -1;
        // 后向指针
        j->next = NULL;
        if (p == NULL) {
            p = j;
        } else {
            FreeSpace* w = p;
            while (w->next != NULL) {
                w = w->next;
            }
            w->next = j;
        }
    }
    return p;
}
void set_num(FreeSpace* space) {
    FreeSpace* p = space;
    int i = 1;
    while (p != NULL) {
        p->num = i++;
        p = p->next;
    }
}
FreeSpace* sort_start(FreeSpace* space) {
    // 定位原链表起始地址最小的结点
    FreeSpace* firstest = space;
    // 移动指针
    FreeSpace* p = space;
    // 从原链表拆下来的起始地址最小的结点
    FreeSpace* newlastone = NULL;
    // 新链表
    FreeSpace* newspace = NULL;
    // 定位新链表的最后一个结点
    FreeSpace* lastone = NULL;
    // 直到原链表为空结束
    while (space != NULL) {
        // 找出原链表起始地址最小的结点
        int first = p->start;
        while (p != NULL) {
            if (p->start < first) {
                firstest = p;
                first = p->start;
            }
            p = p->next;
        }
        // 当起始地址最小的结点为原链表的第一个节点
        if (firstest == space) {
            newlastone = firstest;
            // 修改原链表
            space = space->next;
        } else {
            newlastone = firstest;
            // 修改原链表
            FreeSpace* move = space;
            // 定位分区最小的结点前一个节点
            while (move->next != firstest) {
                move = move->next;
            }
            move->next = firstest->next;
        }
        // 将从原链表拆下来的分区最小的结点接入新链表末尾
        if (newspace == NULL) {
            // 新链表第一个节点
            newspace = newlastone;
            lastone = newlastone;
        } else {
            lastone->next = newlastone;
            lastone = newlastone;
        }
        // 更新shortest和p指向node的第一个节点
        firstest = space;
        p = space;
    }
    return newspace;
}
bool First_Fit(Word* word, FreeSpace* space) {
    int flag = 0;
    FreeSpace* move = space;
    Word* i = word;
    int paper_number = i->papernumber;
    // 空闲内存分区链不为空
    while (move != NULL) {
        // 空闲的空间
        if (move->state == 0) {
            // 剩余空间大于作业需要的内存空间，可分配
            if (paper_number != 0) {
                // 分配后剩余的空间
                move->state = 1;
                move->wordname = word->wordname;
                paper_number--;
                if (paper_number == 0) {
                    flag = 1;
                    break;
                }
            }
        }
        // 已到空闲内存分区链末尾
        if (move->next == NULL) {
            flag = 0;
            break;
        }
        move = move->next;
    }
    set_num(space);
    if (flag == 1)
        return true;
    else {
        return false;
    }
}
void Recycle_Word(int wordname, FreeSpace* space) {
    FreeSpace* move = space;
    if (move->next == NULL && move->wordname == -1) {
        printf("还没有分配任何作业！\n");
    }
    while (move != NULL) {
        // 当move指向需释放空间的前移结点
        // 需释放空间的上一块空间空闲时
        if (move->state == 1 && move->wordname == wordname) {
            // 合并需释放空间上一块空间与需释放空间
            move->wordname = -1;
            move->state = 0;
        }
        move = move->next;
    }
    set_num(space);
}
void RoundRobin(Word* wait_queue,
                Word* run_queue,
                Word* finish_queue,
                FreeSpace* space) {
    int number = 0;
    Word* j;
    Word* p = wait_queue->next;
    show(space, wait_queue, finish_queue, run_queue);
    while ((wait_queue->next != NULL || run_queue->next != NULL) &&
           number <= 5) {
        for (int i = 0; i < 5 && number < 5 && p != NULL; i++) {
            if (First_Fit(p, space) && wait_queue->next != NULL) {
                set_run(wait_queue, run_queue);
                show(space, wait_queue, finish_queue, run_queue);
                number++;
            } else {
                wait_queue->next = p->next;
                Word* k = wait_queue;
                while (k->next != NULL) {
                    k = k->next;
                }
                k->next = p;
                k->next->next = NULL;
            }
            p = wait_queue->next;
        }
        j = run_queue->next;
        for (; j != NULL;) {
            Recycle_Word(j->wordname, space);
            j->run_time = time_slice;
            set_finish(run_queue, finish_queue);
            show(space, wait_queue, finish_queue, run_queue);
            number--;
            j = run_queue->next;
        }
    }
}
int main() {
    Word* wait_queue = (Word*)malloc(sizeof(Word));
    Word* run_queue = (Word*)malloc(sizeof(Word));
    Word* finish_queue = (Word*)malloc(sizeof(Word));
    FreeSpace* space = NULL;
    srand((int)time(NULL));
    if (wait_queue == NULL && run_queue == NULL && finish_queue == NULL) {
        printf("动态分配内存失败！");
    }
    wait_queue->next = NULL;
    run_queue->next = NULL;
    finish_queue->next = NULL;
    Create_word(wait_queue);
    space = initspace(space);
    RoundRobin(wait_queue, run_queue, finish_queue, space);
}
