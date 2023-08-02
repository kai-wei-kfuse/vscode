#include <conio.h>
#include <stdio.h>
typedef struct student {
    int xuehao;
    char name[10];
    float chengji[2];
    float pjfen;
    float zfen;
} student;
student xs[10];
int g;

void input(student xs[]);
void zfen(student xs[]);
void pjfen(student xs[]);
void find(student xs[]);
void pmzb(student xs[]);

void input(student xs[]) {
    int i;
    printf("请输入学生人数\n");
    scanf("%d", &g);
    printf("请输入各学生的学号，姓名，三门成绩：\n");
    for (i = 0; i < g; i++) {
        scanf("%d%s%f%f%f", &xs[i].xuehao, xs[i].name, &xs[i].chengji[0],
              &xs[i].chengji[1], &xs[i].chengji[2]);
        xs[i].pjfen =
            (xs[i].chengji[0] + xs[i].chengji[1] + xs[i].chengji[2]) / 3.0;
        xs[i].zfen = xs[i].chengji[0] + xs[i].chengji[1] + xs[i].chengji[2];
    }
    printf("学生信息输入完毕\n");
}

void pjfen(student xs[]) {
    int i;
    for (i = 0; i < g; i++)
        printf("该学生的平均分\n%d  姓名%s  平均分%f\n", xs[i].xuehao,
               xs[i].name, xs[i].pjfen);
}

void zfen(student xs[]) {
    int i;
    for (i = 0; i < g; i++) {
        printf("该学生的学号\n%d  姓名%s  总分%f\n", xs[i].xuehao, xs[i].name,
               xs[i].zfen);
    }
}

void find(student xs[]) {
    int i, num;
    printf("请输入学生的学号\n");
    scanf("%d", &num);
    for (i = 0; i < g; i++) {
        if (num == xs[i].xuehao) {
            printf("该学生的学号\n%d  姓名%s  总分%f\n", xs[i].xuehao,
                   xs[i].name, xs[i].zfen);
            break;
        }
    }
}

void pmzb(student xs[]) {
    student linshi;
    int i, j;
    for (j = 0; j < 2; j++)
        for (i = 1; i < 3; i++)
            if (xs[i].zfen < xs[i + 1].zfen) {
                linshi = xs[j];
                xs[j] = xs[i];
                xs[j] = linshi;
            }
    printf("总分由高到低排序后的总表如下：\n");
    for (i = 0; i < g; i++) {
        printf("该学生的学号\n%d  姓名%s  总分%f\n", xs[i].xuehao, xs[i].name,
               xs[i].zfen);
    }
}

int main() {
    int x;

    while (1) {
        printf("学生信息管理系统\n");
        printf("1.输入学生信息\n");
        printf("2.计算学生总分\n");
        printf("3.计算学生平均分\n");
        printf("4.查找学生信息\n");
        printf("5.按总分排序\n");
        printf("6.退出\n");
        printf("请输入你的选择\n");
        scanf("%d", &x);
        switch (x) {
            case 1:
                input(xs);
                break;
            case 2:
                zfen(xs);
                break;
            case 3:
                pjfen(xs);
                break;
            case 4:
                find(xs);
                break;
            case 5:
                pmzb(xs);
                break;
            case 6:
                break;
        }
    }
    getch();
    return 0;
}