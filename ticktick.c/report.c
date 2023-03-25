#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
typedef struct inf
{
    char name[20];    //����
    char time1[20];   //��ʼʱ��
    char time2[20];   //����ʱ��
    char address[50]; //�ص�
    char word[200];   //����
    long long tt;
    struct inf *next;
} inf;
inf *List;
inf *head;
int x = 0;
struct tm *lt;
char MenuText[7][40] = {
    "|[A]  �½��ճ�         |",
    "|[B]  ��ѯ�ճ�         |",
    "|[C]  �޸��ճ�         |",
    "|[D]  ɾ���ճ�         |",
    "|[E]  �鿴�ճ�         |",
    "|[F]  ��������         |",
    "|[Q]  �� ��            |"};

char MenuText2[6][40] = {
    "|[A]  �ճ�����         |",
    "|[B]  ��ʼʱ��         |",
    "|[C]  ����ʱ��         |",
    "|[D]  ִ�еص�         |",
    "|[E]  ��ϸ��Ϣ         |",
    "|[F]  ��   ��         |"};

char MenuText3[2][40] = {
    "|[A]  ����         |",
    "|[B]  �ر�         |",
};

void gotoxy(int x, int y)
{
    COORD pos = {x, y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); // ��ȡ��׼����豸���
    SetConsoleCursorPosition(hOut, pos);           //���������ֱ���ָ���ĸ����壬����λ��
}

void coutmenu(int highlight) //������˵�
{
    int i;
    gotoxy(0, 0);
    print(List);
    // system("color 7");
    printf("\n-------------------------\n");
    for (i = 0; i < 7; i++)
    {
        if (i == highlight - 1)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
        else
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
        printf("%s\n", MenuText[i]);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("-------------------------\n");
}

void coutpoint(int highlight) //����޸Ĳ˵�
{
    int i;
    printf("ѡ����Ҫ�޸ĵ���Ŀ");
    printf("\n-------------------------\n");
    for (i = 0; i < 6; i++)
    {
        if (i == highlight - 1)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
        else
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
        printf("%s\n", MenuText2[i]);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("-------------------------\n");
}

void coutyesno(int highlight) //����Ƿ�˵�
{
    int i;
    printf("���ڵ�����״̬�ǣ�");
    if (x == 1)
        printf("����\n");
    else
        printf("�ر�\n");
    printf("��ѡ������ر�����");
    printf("\n-------------------------\n");
    for (i = 0; i < 2; i++)
    {
        if (i == highlight - 1)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
        else
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
        printf("%s\n", MenuText3[i]);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("-------------------------\n");
}

void sorts(inf *List) //����
{
/*
    for (inf *p = List->next; p != NULL; p = p->next)
        for (inf *q = p->next; q != NULL; q = q->next)
        {
            if (p->tt > q->tt)
            {
                inf k = *p;
                *p = *q;
                *q = k;
                k.next = p;
                p->next = q->next;
                q->next = k.next;
            }
        }*/
    inf *pb,*pf,temp;
    pf=List;
    if(List==NULL)//����Ϊ��
    {
        return List;
    }
    if(List->next==NULL)//������1���ڵ�
    {
        return List;
    }
    while(pf->next!=NULL)//��pfָ��Ľڵ�Ϊ��׼�ڵ�
    {
        pb=pf->next;//pb�ӻ�׼�����һ���ڵ㿪ʼ
        while(pb!=NULL)
        {
            if(pf->tt>pb->tt)
            {
                temp=*pf;
                *pf=*pb;
                *pb=temp;
                temp.next=pf->next;
                pf->next=pb->next;
                pb->next=temp.next;
            }
            pb=pb->next;
        }
        pf=pf->next;
    }
    return List;
}

void creadfile(char *file) //��ȡ�ļ���������
{
    List = (inf *)malloc(sizeof(inf));
    FILE *fp = fopen(file, "r");
    inf l;
    inf *node = NULL;
    inf *end = List;
    if (fp == NULL)
    {
        printf("ERROR\n");
        return;
    }
    else
        while (fscanf(fp, "%s %s %s %s %s %d", l.name, l.time1, l.time2, l.address, l.word, &l.tt) != EOF)
        {
            node = (inf *)malloc(sizeof(inf));
            *node = l;
            end->next = node;
            end = node;
            end->next = NULL;
            // printf("%s %s %s %s %s",node->name,node->time1,node->time2,node->address,node->word);
        }
    // end->next = NULL;
    fclose(fp);
    return;
}

inf *find(inf *List) //��������
{
    char *name;
    gets(name);
    int i = 1;
    inf *p = List;
    // p=p->next;
    while (p->next != NULL)
    {
        if (strcmp(p->next->name, name) == 0)
        {
            printf("���ҳɹ�!\n");
            // printf("%s %s %s %s %s\n",p->name,p->time1,p->time2,p->address,p->word);
            return p;
        }
        p = p->next;
    }
    printf("\n");
    return NULL;
}

void print(inf *p) //���
{
    //p = p->next;
    printf(" |�ճ�  |��ʼʱ��|����ʱ��|  �ص�  | ��ϸ��Ϣ|\n");
    while (p->next!= NULL)
    {
        printf("%8s|%8s|%8s|%8s|%8s|\n", p->name, p->time1, p->time2, p->address, p->word);
        p = p->next;
        // printf("%8s|%8s|%8s|%8s|%8s %d\n", p->name, p->time1, p->time2, p->address, p->word, p->tt);
        // p = p->next;
    }
    return;
}

void printone(inf *p) //��������ճ�
{
    printf(" |�ճ�  |��ʼʱ��|����ʱ��| �ص� | ��ϸ��Ϣ |\n");
    printf("%8s|%8s|%8s|%8s|%8s\n", p->name, p->time1, p->time2, p->address, p->word);
}

void remain(inf *p) //����
{
    time_t t;
    time(&t); //��ȡʱ���,��һ������
    p = p->next;
    while (p != NULL)
    {
        if (p->tt == time(&t) && x == 1)
        {
            printf("�ճ�ʱ�䵽�ˣ�\n");
            printf("Ҫ���е���%s,����س�ֹͣ���ӣ�", p->name);
            Beep(2000, 500);
            char c;
            c = getch();
            if (c == 'r')
                return;
        }
        p = p->next;
        // printf("d");
    }
    return;
}

long long gettimes(char *times1) //���ճ�ת��ʱ���
{
    time_t t;
    time(&t);
    lt = localtime(&t);
    struct tm sttm;
    int hours = hourtoint(times1);
    int mon = lt->tm_mon;
    int years = lt->tm_year;
    int days = lt->tm_mday;
    int min = mintoint(times1);
    int sec = 0;
    sttm.tm_year = years; // ע�⣬Ҫ��1900
    sttm.tm_mon = mon;    // ע�⣬Ҫ��1
    sttm.tm_mday = days;
    sttm.tm_hour = hours;
    sttm.tm_min = min;
    sttm.tm_sec = sec;
    sttm.tm_isdst = 0;
    // printf("%d %d %d %d %d\n",years,mon,days,hours,min);
    long long times = mktime(&sttm); //�õ�ʱ���
    return times;
}

inf *addinf() //��ӽڵ�
{
    inf *news;
    news = (inf *)malloc(sizeof(inf));
    scanf("%s %s %s %s %s", news->name, news->time1, news->time2, news->address, news->word);
    news->tt = gettimes(news->time1);
    //printf("ʱ���Ϊ%d", gettimes(news->time1));
    sleep(1);
    news->next = List->next;
    List->next = news;
    save(List, "information.txt");
}

void save(inf *p, char *file) //�����ļ�
{
    FILE *fp = fopen(file, "w");
    if (fp == NULL)
    {
        printf("Error\n");
        return;
    }
    p = p->next;
    while (p != NULL)
    {
        p->tt = gettimes(p->time1);
        fprintf(fp, "%s %s %s %s %s %d\n", p->name, p->time1, p->time2, p->address, p->word, p->tt);
        p = p->next;
    }
    fclose(fp);
}

void modify(inf *List) //�޸�
{
    system("cls");
    print(List);
    printf("��������Ҫ�޸ĵ��ճ�:");
    inf *p = find(List);
    if (p == NULL)
    {
        system("cls");
        print(List);
        printf("û������ճ�!������������˳��������˵�.\n");
        while (!kbhit()){}
        char a = getch();
        Sleep(140);
        HideCursor();
        return;
    }
    p = p->next;
    char c;
    int high = 1;
    system("cls");
    printone(p);
    coutpoint(high);
    HideCursor();
    while (1)
    {
        if (kbhit())
        {
            usleep(100);
            c = getch();
            if (GetAsyncKeyState(VK_UP))
            {
                high = (high > 1) ? high - 1 : 6;
                Sleep(140);
                system("cls");
                printone(p);
                coutpoint(high);
            }
            if (GetAsyncKeyState(VK_DOWN))
            {
                high = (high < 6) ? high + 1 : 1;
                Sleep(140);
                system("cls");
                printone(p);
                coutpoint(high);
            }
            else if (c == '\r')
                switch (high)
                {
                    char a;
                    system("cls");
                    coutpoint(high);
                case 1:
                    showCursor();
                    printf("����������:");
                    scanf("%s", p->name);
                    save(List, "information.txt");
                    printf("�޸ĳɹ�������������Լ���");
                     while (!kbhit()){}
                        a = getch();
                    Sleep(140);
                    HideCursor();
                    system("cls");
                    printone(p);
                    coutpoint(high);
                    break;
                case 2:
                    showCursor();
                    printf("�����¿�ʼʱ��:");
                    scanf("%s", p->time1);
                    save(List, "information.txt");
                    printf("�޸ĳɹ�������������Լ���");
                     while (!kbhit()){}
                        a = getch();
                        Sleep(140);
                        HideCursor();
                        system("cls");
                    printone(p);
                    coutpoint(high);
                    break;
                case 3:
                    showCursor();
                    printf("�����½���ʱ��:");
                    scanf("%s", p->time2);
                    save(List, "information.txt");
                    printf("�޸ĳɹ�������������Լ���");
                     while (!kbhit()){}
                        a = getch();
                        Sleep(140);
                        HideCursor();
                        system("cls");
                    printone(p);
                    coutpoint(high);
                    break;
                case 4:
                    showCursor();
                    printf("�����µص�:");
                    scanf("%s", p->address);
                    save(List, "information.txt");
                    printf("�޸ĳɹ�������������Լ���");
                     while (!kbhit()){}
                        a = getch();
                        Sleep(140);
                        HideCursor();
                        system("cls");
                    printone(p);
                    coutpoint(high);
                    break;
                case 5:
                    showCursor();
                    printf("��������ϸ��Ϣ:");
                    scanf("%s", p->word);
                    save(List, "information.txt");
                    printf("�޸ĳɹ�������������Լ���");
                     while (!kbhit()){}
                        a = getch();
                        Sleep(140);
                        HideCursor();
                        system("cls");
                    printone(p);
                    coutpoint(high);
                    break;
                case 6:
                    return 0;
                    break;
                }
        }
    }
}

void deletefind(inf *List) //ɾ��
{
    print(List);
    inf *p = List;
    printf("������ɾ�����ճ�����:");
    p = find(List);
    if (p == NULL)
    {
        system("cls");
        print(List);
        printf("û������ճ�!������������˳��������˵�.\n");
        while (!kbhit()){}
        char a = getch();
        Sleep(140);
        HideCursor();
        return;
    }
    deletes(p);
    save(List, "information.txt");
}
void deletes(inf *p)
{
    inf *pp = p->next;
    p->next = pp->next;
    pp->next = NULL;
    free(pp);
}

void remainchoose() //ѡ�����ر�����
{
    char c;
    int high = 1;
    system("cls");
    coutyesno(high);
    while (1)
    {
        if (kbhit())
        {
            c = getch();
            if (GetAsyncKeyState(VK_UP))
            {
                high = (high > 1) ? high - 1 : 2;
                Sleep(140);
                system("cls");
                coutyesno(high);
            }
            if (GetAsyncKeyState(VK_DOWN))
            {
                high = (high < 2) ? high + 1 : 1;
                Sleep(140);
                system("cls");
                coutyesno(high);
            }
            else if (c == '\r')
                switch (high)
                {
                case 1:
                    x = 1;
                    return;
                case 2:
                    x = 0;
                    return;
                }
        }
    }
}

int hourtoint(char *time) //Сʱ��charתint
{
    int hours = (time[0] - '0') * 10 + time[1] - '0';
    return hours;
}

int mintoint(char *time) //���ӵ�charתint
{
    int mins = (time[3] - '0') * 10 + time[4] - '0';
    return mins;
}

void couttime() //���ʵʱʱ��
{               /*
                   time_t t;
                   struct tm *l;
                   time(&t);           //��ȡʱ�����
                   l = localtime(&t); //תΪʱ��ṹ��
                   printf("�����Ǳ���ʱ�䣺%d/%d/%d %d:%d:%d\n", l->tm_year + 1900, l->tm_mon + 1,
                           l->tm_mday, l->tm_hour,l->tm_min, l->tm_sec);
                   Sleep(500);
               */
    time_t tt_;
    struct tm *tm_;
    time(&tt_);
    tm_ = localtime(&tt_);
    // system("color 2");
    gotoxy(70, 28);
    printf("�����Ǳ���ʱ�䣺%d��%d��%d�� %02d:%02d:%02d\r", 1900 + tm_->tm_year,
           tm_->tm_mon + 1, tm_->tm_mday, tm_->tm_hour, tm_->tm_min, tm_->tm_sec);
    // system("color 7");
    Sleep(200);
}

void HideCursor() // �������ع��
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};                            // �ڶ���ֵΪ0��ʾ���ع��
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info); //�����ͽṹ�嶼��windows.h�ж��塣
}
void showCursor() // ������ʾ���
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 1};                            // �ڶ���ֵΪ0��ʾ���ع��
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info); //�����ͽṹ�嶼��windows.h�ж��塣
}

int main()
{
    char c;
    int high = 1;
    time_t t;
    time(&t);           //��ȡʱ���,��һ������
    lt = localtime(&t); //תΪʱ��ṹ��
    creadfile("information.txt");
    sorts(List);
    // couttime(high);
    coutmenu(high);
    HideCursor(); //���ع��
    while (1)     //��ѭ����
    {
        couttime();
        if (kbhit())
        {
            c = getch();
            if (GetAsyncKeyState(VK_UP))
            {
                high = (high > 1) ? high - 1 : 7;
                Sleep(150);
                // system("cls");
                gotoxy(0, 0);
                coutmenu(high);
            }
            if (GetAsyncKeyState(VK_DOWN))
            {
                high = (high < 7) ? high + 1 : 1;
                usleep(4000);
                // system("cls");
                gotoxy(0, 0);
                coutmenu(high);
            }
            else if (c == '\r')
            {
                switch (high)
                {
                    system("cls");
                    coutmenu(high);
                    couttime(high);
                case 1:
                    system("cls");
                    showCursor();
                    printf("������%d��%d��\n", lt->tm_mon + 1, lt->tm_mday);
                    printf("�½��ճ�(��ʽ�磺������ 01:00 03:00 ��2-222 ��kindle):");
                    addinf();
                    sorts(List);
                    HideCursor();
                    //sorts(List);
                    //printf("d");
                    break;
                case 2:
                    system("cls");
                    showCursor();
                    system("cls");
                    coutmenu(high);
                    printf("����������ҵ��ճ�����:");
                    inf *result = find(List);
                    if (result != NULL)
                    {
                        result = result->next;
                        // printf("%s %s %s %s %s\n", result->name, result->time1, result->time2, result->address, result->word);
                        while (!kbhit())
                        {
                            system("cls");
                            printf("���ҳɹ�����������������˵�\n");
                            printone(result);
                            sleep(1);
                            while (!kbhit())
                            {
                            }
                            char a = getch();
                            Sleep(140);
                            HideCursor();
                            break;
                        }
                    }
                    if (result == NULL)
                    {
                        system("cls");
                        print(List);
                        printf("û������ճ�!������������˳��������˵�.\n");
                        while (!kbhit())
                        {
                        }
                        char a = getch();
                        Sleep(140);
                        HideCursor();
                        break;
                    }
                    HideCursor();
                    break;
                case 3:
                    showCursor();
                    modify(List);
                    system("cls");
                    coutmenu(high);
                    HideCursor();
                    sorts(List);
                    break;
                case 4:
                    showCursor();
                    system("cls");
                    deletefind(List);
                    printf("����ִ�����");
                    HideCursor();
                    break;
                case 5:
                    system("cls");
                    print(List);
                    while (!kbhit()){}
                        char a = getch();
                        Sleep(140);
                        HideCursor();
                        sorts(List);
                    break;
                case 6:
                    remainchoose();
                    break;
                case 7:
                    system("cls");
                    printf("\n��л����ʹ��\n");
                    return 0;
                    break;
                }
                printf("����ִ�����");
                system("cls");
                coutmenu(high);
            }
        }
        remain(List);
    }
}
