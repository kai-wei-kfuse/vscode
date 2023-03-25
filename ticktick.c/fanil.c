#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
typedef struct inf{
    char name[20];//名字
    char time1[20];//开始时间
    char time2[20];//结束时间
    char address[50];//地点
    char word[200];//描述
    struct inf* next;
}inf;
inf* List;
inf* head;
char MenuText[7][40]={
    "|[A]  新建日程         |",
    "|[B]  查询日程         |",
    "|[C]  修改日程         |",
    "|[D]  删除日程         |",
    "|[E]  查看日程         |",
    "|[F]  提醒设置         |",
    "|[Q]  退 出            |"
};

char MenuText2[6][40]={
    "|[A]  日程名称         |",
    "|[B]  开始时间         |",
    "|[C]  结束时间         |",
    "|[D]  执行地点         |",
    "|[E]  详细信息         |",
    "|[F]  退   出         |"
};

void coutmenu(int highlight)
{
    int i;
    printf("\n---------------------------\n");
    for (i=0;i<7;i++){
        if (i==highlight-1)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
        else
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
        printf("%s\n",MenuText[i]);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("---------------------------\n");
    
}

void coutpoint(int highlight)
{
    int i;
    printf("选择你要修改的项目");
    printf("\n---------------------------\n");
    for (i=0;i<6;i++){
        if (i==highlight-1)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70);
        else
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
        printf("%s\n",MenuText2[i]);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    printf("---------------------------\n");
    
}

int creadfiles(inf* List,char* file)//读取文件创建链表
{
    FILE *fp=fopen(file,"r");
    inf l;
    inf *node=NULL;
    inf *end=List;
    
    if(fp==NULL)
    {
        printf("ERROR\n");
        return 0;
    }
    else
    while(fscanf(fp,"%s %s %s %s %s",l.name,l.time1,l.time2,l.address,l.word)!=EOF)
    {
        node=(inf*)malloc(sizeof(inf));
        *node=l;
        end->next=node;
        end=node;
        end->next=NULL;
        //printf("%s %s %s %s %s",node->name,node->time1,node->time2,node->address,node->word);
    }
    fclose(fp);
    return 1;
}

void creadfile(char* file)//读取文件创建链表
{
    List=(inf *)malloc(sizeof(inf));
    FILE *fp=fopen(file,"r");
    inf l;
    inf *node=NULL;
    inf *end=List;
    if(fp==NULL)
    {
        printf("ERROR\n");
        return;
    }
    else
    while(fscanf(fp,"%s %s %s %s %s",l.name,l.time1,l.time2,l.address,l.word)!=EOF)
    {
        node=(inf*)malloc(sizeof(inf));
        *node=l;
        end->next=node;
        end=node;
        end->next=NULL;
        //printf("%s %s %s %s %s",node->name,node->time1,node->time2,node->address,node->word);
    }
    fclose(fp);
    return ;
}

inf* find(inf *List)//查找
{
    char* name;
    gets(name);
    int i=1;
    inf *p=List;
    //p=p->next;
    while(p!=NULL)
    {
        if(strcmp(p->name,name)==0)
        {
            printf("查找成功!\n");
            //printf("%s %s %s %s %s\n",p->name,p->time1,p->time2,p->address,p->word);
            return p;
        }
        p=p->next;
    }
    printf("没有这个日程!\n");
    return NULL;
}

void print(inf* p)//输出
{
    //p=p->next;
    while(p!=NULL)
    {
        printf("%s %s %s %s %s\n",p->name,p->time1,p->time2,p->address,p->word);
        p=p->next;
    }
}

inf* addinf()//添加节点
{
    inf* news;
    news=(inf*)malloc(sizeof(inf));
    scanf("%s %s %s %s %s",news->name,news->time1,news->time2,news->address,news->word);
    news->next=List;
    List=news;
}

void save(inf* p,char* file)//保存文件
{
    FILE *fp=fopen(file,"w");
    if(fp==NULL)
    {
        printf("Error\n");
        return ;
    }
    //p=p->next;
    while(p!=NULL)
    {
        fprintf(fp,"%s %s %s %s %s\n",p->name,p->time1,p->time2,p->address,p->word);
        p=p->next;
    }
    fclose(fp);
}

void modify(inf* List)//修改
{
    system("cls");
    printf("输入你需要修改的日程:");
    inf* p=find(List);
    char c;
    int high=1;
    system("cls");
    coutpoint(high);
    for(;;){
        if (kbhit()){
            c=getch();
            if (GetAsyncKeyState(VK_UP)){
                high=(high>1)?high-1:6;
                Sleep(140);
                system("cls");
                coutpoint(high);
            }
            if (GetAsyncKeyState(VK_DOWN)){
                high=(high<6)?high+1:1;
                Sleep(140);
                system("cls");
                coutpoint(high);
            }
            else if (c=='\r')
            switch (high)
            {
                system("cls");
                coutpoint(high);
            case 1:
            printf("输入新名称:");
            scanf("%s",p->name);
            save(List,"information.txt");
                break;
            case 2:
            printf("输入新开始时间:");
            scanf("%s",p->time1);
            save(List,"information.txt");
                break;
            case 3:
            printf("输入新结束时间:");
            scanf("%s",p->time2);
            save(List,"information.txt");
                break;
            case 4:
            printf("输入新地点:");
            scanf("%s",p->address);
            save(List,"information.txt");
                break;
            case 5:
            printf("输入新详细信息:");
            scanf("%s",p->word);
            save(List,"information.txt");
                break;
            case 6:
                return 0;
                break;
            }
        }
    }
}

void deletefind(inf* List)
{
    print(List);
    inf* p=List;
    printf("输入想删除的日程名称:");
    p=find(List);
    deletes(p);
}
void deletes(inf* p)
{
    inf* pp=p->next;
    p->next=pp->next;
    pp->next=NULL;
    free(pp);
}
int main()
{
    char c;
    int high=1;
    coutmenu(high);
    creadfile("information.txt");
    for(;;){
        if (kbhit()){
            c=getch();
            if (GetAsyncKeyState(VK_UP)){
                high=(high>1)?high-1:7;
                Sleep(140);
                system("cls");
                coutmenu(high);
            }
            if (GetAsyncKeyState(VK_DOWN)){
                high=(high<7)?high+1:1;
                Sleep(140);
                system("cls");
                coutmenu(high);
            }
            else if (c=='\r'){
            switch (high)
            {
                system("cls");
                coutmenu(high);
            case 1:
                printf("新建日程:");
                addinf();
                save(List,"information.txt");
                break;
            case 2:
                printf("输入你想查找的日程名称:");
                inf* result=find(List);
                printf("%s %s %s %s %s\n",result->name,result->time1,result->time2,result->address,result->word);
                break;
            case 3:
                modify(List);
                system("cls");
                coutmenu(high);
                break;
            case 4:
                deletefind(List);
                break;
            case 5:
                print(List);
                break;
            case 6:
                break;
            case 7:
                return 0;
                break;
            }
                printf("command %c finished",'A'+high-1);
            }
        }
    }
}
