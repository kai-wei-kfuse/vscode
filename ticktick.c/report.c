#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
typedef struct inf
{
    char name[20];    //名字
    char time1[20];   //开始时间
    char time2[20];   //结束时间
    char address[50]; //地点
    char word[200];   //描述
    long long tt;
    struct inf *next;
} inf;
inf *List;
inf *head;
int x = 0;
struct tm *lt;
char MenuText[7][40] = {
    "|[A]  新建日程         |",
    "|[B]  查询日程         |",
    "|[C]  修改日程         |",
    "|[D]  删除日程         |",
    "|[E]  查看日程         |",
    "|[F]  提醒设置         |",
    "|[Q]  退 出            |"};

char MenuText2[6][40] = {
    "|[A]  日程名称         |",
    "|[B]  开始时间         |",
    "|[C]  结束时间         |",
    "|[D]  执行地点         |",
    "|[E]  详细信息         |",
    "|[F]  退   出         |"};

char MenuText3[2][40] = {
    "|[A]  开启         |",
    "|[B]  关闭         |",
};

void gotoxy(int x, int y)
{
    COORD pos = {x, y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); // 获取标准输出设备句柄
    SetConsoleCursorPosition(hOut, pos);           //两个参数分别是指定哪个窗体，具体位置
}

void coutmenu(int highlight) //输出主菜单
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

void coutpoint(int highlight) //输出修改菜单
{
    int i;
    printf("选择你要修改的项目");
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

void coutyesno(int highlight) //输出是否菜单
{
    int i;
    printf("现在的提醒状态是：");
    if (x == 1)
        printf("开启\n");
    else
        printf("关闭\n");
    printf("请选择开启或关闭提醒");
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

void sorts(inf *List) //排序
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
    if(List==NULL)//链表为空
    {
        return List;
    }
    if(List->next==NULL)//链表有1个节点
    {
        return List;
    }
    while(pf->next!=NULL)//以pf指向的节点为基准节点
    {
        pb=pf->next;//pb从基准点的下一个节点开始
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

void creadfile(char *file) //读取文件创建链表
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

inf *find(inf *List) //查找名字
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
            printf("查找成功!\n");
            // printf("%s %s %s %s %s\n",p->name,p->time1,p->time2,p->address,p->word);
            return p;
        }
        p = p->next;
    }
    printf("\n");
    return NULL;
}

void print(inf *p) //输出
{
    //p = p->next;
    printf(" |日程  |开始时间|结束时间|  地点  | 详细信息|\n");
    while (p->next!= NULL)
    {
        printf("%8s|%8s|%8s|%8s|%8s|\n", p->name, p->time1, p->time2, p->address, p->word);
        p = p->next;
        // printf("%8s|%8s|%8s|%8s|%8s %d\n", p->name, p->time1, p->time2, p->address, p->word, p->tt);
        // p = p->next;
    }
    return;
}

void printone(inf *p) //输出单个日程
{
    printf(" |日程  |开始时间|结束时间| 地点 | 详细信息 |\n");
    printf("%8s|%8s|%8s|%8s|%8s\n", p->name, p->time1, p->time2, p->address, p->word);
}

void remain(inf *p) //提醒
{
    time_t t;
    time(&t); //获取时间戳,是一个整型
    p = p->next;
    while (p != NULL)
    {
        if (p->tt == time(&t) && x == 1)
        {
            printf("日程时间到了！\n");
            printf("要进行的是%s,输入回车停止闹钟！", p->name);
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

long long gettimes(char *times1) //由日程转化时间截
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
    sttm.tm_year = years; // 注意，要减1900
    sttm.tm_mon = mon;    // 注意，要减1
    sttm.tm_mday = days;
    sttm.tm_hour = hours;
    sttm.tm_min = min;
    sttm.tm_sec = sec;
    sttm.tm_isdst = 0;
    // printf("%d %d %d %d %d\n",years,mon,days,hours,min);
    long long times = mktime(&sttm); //得到时间截
    return times;
}

inf *addinf() //添加节点
{
    inf *news;
    news = (inf *)malloc(sizeof(inf));
    scanf("%s %s %s %s %s", news->name, news->time1, news->time2, news->address, news->word);
    news->tt = gettimes(news->time1);
    //printf("时间截为%d", gettimes(news->time1));
    sleep(1);
    news->next = List->next;
    List->next = news;
    save(List, "information.txt");
}

void save(inf *p, char *file) //保存文件
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

void modify(inf *List) //修改
{
    system("cls");
    print(List);
    printf("输入你需要修改的日程:");
    inf *p = find(List);
    if (p == NULL)
    {
        system("cls");
        print(List);
        printf("没有这个日程!输入任意键以退出返回主菜单.\n");
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
                    printf("输入新名称:");
                    scanf("%s", p->name);
                    save(List, "information.txt");
                    printf("修改成功！输入任意键以继续");
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
                    printf("输入新开始时间:");
                    scanf("%s", p->time1);
                    save(List, "information.txt");
                    printf("修改成功！输入任意键以继续");
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
                    printf("输入新结束时间:");
                    scanf("%s", p->time2);
                    save(List, "information.txt");
                    printf("修改成功！输入任意键以继续");
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
                    printf("输入新地点:");
                    scanf("%s", p->address);
                    save(List, "information.txt");
                    printf("修改成功！输入任意键以继续");
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
                    printf("输入新详细信息:");
                    scanf("%s", p->word);
                    save(List, "information.txt");
                    printf("修改成功！输入任意键以继续");
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

void deletefind(inf *List) //删除
{
    print(List);
    inf *p = List;
    printf("输入想删除的日程名称:");
    p = find(List);
    if (p == NULL)
    {
        system("cls");
        print(List);
        printf("没有这个日程!输入任意键以退出返回主菜单.\n");
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

void remainchoose() //选择开启关闭提醒
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

int hourtoint(char *time) //小时的char转int
{
    int hours = (time[0] - '0') * 10 + time[1] - '0';
    return hours;
}

int mintoint(char *time) //分钟的char转int
{
    int mins = (time[3] - '0') * 10 + time[4] - '0';
    return mins;
}

void couttime() //输出实时时间
{               /*
                   time_t t;
                   struct tm *l;
                   time(&t);           //获取时间戳。
                   l = localtime(&t); //转为时间结构。
                   printf("现在是北京时间：%d/%d/%d %d:%d:%d\n", l->tm_year + 1900, l->tm_mon + 1,
                           l->tm_mday, l->tm_hour,l->tm_min, l->tm_sec);
                   Sleep(500);
               */
    time_t tt_;
    struct tm *tm_;
    time(&tt_);
    tm_ = localtime(&tt_);
    // system("color 2");
    gotoxy(70, 28);
    printf("现在是北京时间：%d年%d月%d日 %02d:%02d:%02d\r", 1900 + tm_->tm_year,
           tm_->tm_mon + 1, tm_->tm_mday, tm_->tm_hour, tm_->tm_min, tm_->tm_sec);
    // system("color 7");
    Sleep(200);
}

void HideCursor() // 用于隐藏光标
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};                            // 第二个值为0表示隐藏光标
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info); //函数和结构体都在windows.h中定义。
}
void showCursor() // 用于显示光标
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 1};                            // 第二个值为0表示隐藏光标
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info); //函数和结构体都在windows.h中定义。
}

int main()
{
    char c;
    int high = 1;
    time_t t;
    time(&t);           //获取时间戳,是一个整型
    lt = localtime(&t); //转为时间结构。
    creadfile("information.txt");
    sorts(List);
    // couttime(high);
    coutmenu(high);
    HideCursor(); //隐藏光标
    while (1)     //主循环体
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
                    printf("今天是%d月%d日\n", lt->tm_mon + 1, lt->tm_mday);
                    printf("新建日程(格式如：高数课 01:00 03:00 教2-222 带kindle):");
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
                    printf("输入你想查找的日程名称:");
                    inf *result = find(List);
                    if (result != NULL)
                    {
                        result = result->next;
                        // printf("%s %s %s %s %s\n", result->name, result->time1, result->time2, result->address, result->word);
                        while (!kbhit())
                        {
                            system("cls");
                            printf("查找成功！按任意键返回主菜单\n");
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
                        printf("没有这个日程!输入任意键以退出返回主菜单.\n");
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
                    printf("程序执行完毕");
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
                    printf("\n感谢您的使用\n");
                    return 0;
                    break;
                }
                printf("程序执行完毕");
                system("cls");
                coutmenu(high);
            }
        }
        remain(List);
    }
}
