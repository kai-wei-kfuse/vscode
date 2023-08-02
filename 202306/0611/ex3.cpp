#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct FreeSpace {
    int num;    // ������
    int start;  // ��ʼ��ַ
    int size;   // ������С
    int state;
    int wordname;
    struct FreeSpace* next;
} FreeSpace;
typedef struct Word {
    int wordname;     // ��ҵ����
    int run_time;     // ��ҵ����ʱ��
    char wordstate;   // ��ҵ״̬
    int papernumber;  // ��ҵ����ռ�
    int size;         // ��ҵ����ռ�
    struct Word* next;

} Word;
enum ProcessState { word_wait = 'W', word_run = 'R', word_finish = 'F' };
int Word_Number = 20;
int time_slice = 5;
int totalsize = 1024;
int papersize = 8;

// ��������
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
// ��������

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
    printf("�ڴ�������:\n");
    printf("������\t��ʼ��ַ\t������С\t����״̬\t������ҵ����\n");
    while (p != NULL) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d \n", p->num, p->start, p->size,
               p->state, p->wordname);
        p = p->next;
    }
    printf("\n");
    printf("��ҵ���������\n");
    Word* w = wait_queue->next;
    Word* r = run_queue->next;
    Word* f = finish_queue->next;
    printf("�ȴ�����:\n");
    if (w == NULL) {
        printf("��ǰ���ж�����û�н���\n");
    } else {
        printf("��ҵ����\t��ҵ����ʱ��\t��ҵ����ռ�\t��ҵ״̬\n");
    }
    while (w != NULL) {
        printf("%d\t\t%d\t\t%d\t\t%c\n", w->wordname, w->run_time, w->size,
               w->wordstate);
        w = w->next;
    }
    printf("���ж���\n");
    if (r == NULL) {
        printf("��ǰ���ж�����û�н���\n");
    } else {
        printf("��ҵ����\t��ҵ����ʱ��\t��ҵ����ռ�\t��ҵ״̬\n");
    }
    while (r != NULL) {
        printf("%d\t\t%d\t\t%d\t\t%c\n", r->wordname, r->run_time, r->size,
               r->wordstate);
        r = r->next;
    }
    printf("��ɶ���\n");
    if (f == NULL) {
        printf("��ǰ���ж�����û�н���\n");
    } else {
        printf("��ҵ����\t��ҵ����ʱ��\t��ҵ����ռ�\t��ҵ״̬\n");
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
            printf("���䶯̬�ڴ�ʧ��");
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
        // ���Ϊ�����´���һ��
        FreeSpace* j = (FreeSpace*)malloc(sizeof(FreeSpace));
        // ������
        j->num = a;
        // ��ʼ��ַ
        j->start = (a - 1) * 8;
        // ������С
        j->size = papersize;
        // ״̬��0������У�1����ռ��
        j->state = 0;
        // ��ҵid
        j->wordname = -1;
        // ����ָ��
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
    // ��λԭ������ʼ��ַ��С�Ľ��
    FreeSpace* firstest = space;
    // �ƶ�ָ��
    FreeSpace* p = space;
    // ��ԭ�������������ʼ��ַ��С�Ľ��
    FreeSpace* newlastone = NULL;
    // ������
    FreeSpace* newspace = NULL;
    // ��λ����������һ�����
    FreeSpace* lastone = NULL;
    // ֱ��ԭ����Ϊ�ս���
    while (space != NULL) {
        // �ҳ�ԭ������ʼ��ַ��С�Ľ��
        int first = p->start;
        while (p != NULL) {
            if (p->start < first) {
                firstest = p;
                first = p->start;
            }
            p = p->next;
        }
        // ����ʼ��ַ��С�Ľ��Ϊԭ����ĵ�һ���ڵ�
        if (firstest == space) {
            newlastone = firstest;
            // �޸�ԭ����
            space = space->next;
        } else {
            newlastone = firstest;
            // �޸�ԭ����
            FreeSpace* move = space;
            // ��λ������С�Ľ��ǰһ���ڵ�
            while (move->next != firstest) {
                move = move->next;
            }
            move->next = firstest->next;
        }
        // ����ԭ����������ķ�����С�Ľ�����������ĩβ
        if (newspace == NULL) {
            // �������һ���ڵ�
            newspace = newlastone;
            lastone = newlastone;
        } else {
            lastone->next = newlastone;
            lastone = newlastone;
        }
        // ����shortest��pָ��node�ĵ�һ���ڵ�
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
    // �����ڴ��������Ϊ��
    while (move != NULL) {
        // ���еĿռ�
        if (move->state == 0) {
            // ʣ��ռ������ҵ��Ҫ���ڴ�ռ䣬�ɷ���
            if (paper_number != 0) {
                // �����ʣ��Ŀռ�
                move->state = 1;
                move->wordname = word->wordname;
                paper_number--;
                if (paper_number == 0) {
                    flag = 1;
                    break;
                }
            }
        }
        // �ѵ������ڴ������ĩβ
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
        printf("��û�з����κ���ҵ��\n");
    }
    while (move != NULL) {
        // ��moveָ�����ͷſռ��ǰ�ƽ��
        // ���ͷſռ����һ��ռ����ʱ
        if (move->state == 1 && move->wordname == wordname) {
            // �ϲ����ͷſռ���һ��ռ������ͷſռ�
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
        printf("��̬�����ڴ�ʧ�ܣ�");
    }
    wait_queue->next = NULL;
    run_queue->next = NULL;
    finish_queue->next = NULL;
    Create_word(wait_queue);
    space = initspace(space);
    RoundRobin(wait_queue, run_queue, finish_queue, space);
}
