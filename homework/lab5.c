#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h>
#include <windows.h>
struct strings{
        char s[100];
        struct strings* next;
    };
char MenuText[7][40]={
    "|[A]  Create a List       |",
    "|[B]  Display the List    |",
    "|[C]  Find the Word       |",
    "|[D]  Save to File        |",
    "|[E]  Read to List        |",
    "|[F]  Add to List         |",
    "|[Q]  Exit                |"
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
struct strings* head=NULL;//设置头指针，指向NULL;

struct strings * create()//创建链表
{
    int n=0;
    struct strings *head=NULL,*node=NULL,*end=NULL;
    node=(struct strings*)malloc(sizeof(struct strings));
    end=node;//初始链表只有一个头指针，所以尾等于头
    while(gets(node->s)&&strlen(node->s)!=0)
    {
        n++;
        if(n==1)head=node;
        else 
        end->next=node;
        end=node;
        node=(struct strings*)malloc(sizeof(struct strings));
    }
    end->next=NULL;
    return (head);
}
void print(struct strings* p)//打印
{
    int i=1;
    while(p!=NULL)
    {
        printf("%s\n",p->s);
        p=p->next;
        i++;
    }
}
void find(struct strings *head)//查找
{
    char* word;
    gets(word);
    struct strings *p=head;
    int i=1;
    //p=p->next;
    while(p!=NULL)
    {
        if(strcmp(p->s,word)==0)
        {
            printf("Search successfully\n");
            return ;
        }
        p=p->next;
    }
    printf("Search unsuccessfully!\n");
    return ;
}
void save(struct strings *p,char *filename)//保存到文件
{
    FILE *fp=fopen(filename,"w");
    if (fp==NULL)
    {
        printf("Error\n");
        return;
    }   
    while(p!=NULL)
    {
      fprintf(fp,"%s\n",p->s);
      p=p->next;
    }
    fclose(fp);
}
struct strings *readfile(char *data)//读取文件并且创建链表
{
    FILE *fp=fopen(data,"r");
    if(fp==NULL)
    {
        printf("Error\n");
        return NULL;
    }
    struct strings *head,*node,*end;
    node=(struct strings*)malloc(sizeof(struct strings));
    end=node;
    int n=0;
    while(fscanf(fp,"%s",node->s)!=EOF)//和前面不同的是这里
    {
        n++;
        if(n==1)
            head=node;
        else 
            end->next=node;
        end=node;
        node=(struct strings*)malloc(sizeof(struct strings));
    }
    end->next=NULL;
    return head;
}
struct strings *addtolist(struct strings *head,struct strings* news)//添加节点
{
    struct strings* p=head;
    if (head==NULL){
        head=news;
        news->next=NULL;
        return head;
    }
    while (p->next!=NULL){
        p=p->next;
    }
    p->next=news;
    news->next=NULL;
    return head;
}
struct strings *addtofile(struct strings *head)//添加节点
{
    struct strings *ne;
    for (;;){
        ne=(struct strings *) malloc(sizeof(struct strings));
        gets(ne->s);
        if (strlen(ne->s)!=0)
        {
            head=addtolist(head,ne);
        }
        else{
            free(ne);
            break;
        }
    }
    return head;
}
struct strings *addinlist(struct strings *head,char* data)
{
    struct strings *ne;
    FILE *fp=fopen(data,"r");
    if(fp==NULL)
    {
        printf("Error\n");
        return NULL;
    }
    for (;;){
        ne=(struct strings *) malloc(sizeof(struct strings));
        if (fscanf(fp,"%s",ne->s)!=EOF)
        {
            head=addtolist(head,ne);
        }
        else{
            free(ne);
            break;
        }
    }
    return head;
}
int main()
{
    char c;
    int high=1;
    coutmenu(high);
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
    if (c<='z'&& c>='a')c=c-('a'-'A');
            if (c<='F' && c>='A'){
                //对应处理的程序段
                high=c-'A'+1;
                system("cls");
                coutmenu(high);
                printf("command [%c] ",c);
            }
            else if (c=='\r'){
            switch (high)
            {
                system("cls");
                coutmenu(high);
            case 1:
                printf("Add strings:\n");
                head=create();
                break;
            case 2:
                print(head);
                break;
            case 3:
                printf("Input your word which you want to find:");
                find(head);
                break;
            case 4:
                save(head,"data.txt");
                break;
            case 5:
                //head=readfile("data.txt");
                head=addinlist(head,"data.txt");
                break;
            case 6:
                printf("Add strings:");
                addtofile(head);
                break;
            case 7:
                return 0;
                break;
            }
                //对应处理的程序段
                printf("command %c finished",'A'+high-1);
            }
            else if (c=='Q') return 0;
    /*printf("read file:\n");
    head=readfile("data.txt");//读取文件并创建链表
    print(head);//打印
    printf("add:\n");
    addtofile(head);
    printf("display:\n");
    print(head);
    save(head,"data.txt");
    */
    //head=create();
        }
    }
}