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
    printf("������ѧ������\n");
    scanf("%d", &g);
    printf("�������ѧ����ѧ�ţ����������ųɼ���\n");
    for (i = 0; i < g; i++) {
        scanf("%d%s%f%f%f", &xs[i].xuehao, xs[i].name, &xs[i].chengji[0],
              &xs[i].chengji[1], &xs[i].chengji[2]);
        xs[i].pjfen =
            (xs[i].chengji[0] + xs[i].chengji[1] + xs[i].chengji[2]) / 3.0;
        xs[i].zfen = xs[i].chengji[0] + xs[i].chengji[1] + xs[i].chengji[2];
    }
    printf("ѧ����Ϣ�������\n");
}

void pjfen(student xs[]) {
    int i;
    for (i = 0; i < g; i++)
        printf("��ѧ����ƽ����\n%d  ����%s  ƽ����%f\n", xs[i].xuehao,
               xs[i].name, xs[i].pjfen);
}

void zfen(student xs[]) {
    int i;
    for (i = 0; i < g; i++) {
        printf("��ѧ����ѧ��\n%d  ����%s  �ܷ�%f\n", xs[i].xuehao, xs[i].name,
               xs[i].zfen);
    }
}

void find(student xs[]) {
    int i, num;
    printf("������ѧ����ѧ��\n");
    scanf("%d", &num);
    for (i = 0; i < g; i++) {
        if (num == xs[i].xuehao) {
            printf("��ѧ����ѧ��\n%d  ����%s  �ܷ�%f\n", xs[i].xuehao,
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
    printf("�ܷ��ɸߵ����������ܱ����£�\n");
    for (i = 0; i < g; i++) {
        printf("��ѧ����ѧ��\n%d  ����%s  �ܷ�%f\n", xs[i].xuehao, xs[i].name,
               xs[i].zfen);
    }
}

int main() {
    int x;

    while (1) {
        printf("ѧ����Ϣ����ϵͳ\n");
        printf("1.����ѧ����Ϣ\n");
        printf("2.����ѧ���ܷ�\n");
        printf("3.����ѧ��ƽ����\n");
        printf("4.����ѧ����Ϣ\n");
        printf("5.���ܷ�����\n");
        printf("6.�˳�\n");
        printf("���������ѡ��\n");
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