#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct strings{
        char s[100];
        struct strings* next;
    };

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
struct strings *find(char *a)//查找
{
    struct strings *p=head;
    int i=1;
    p=p->next;
    while(p!=NULL)
    {
        if(p->s==a)
        {
            printf("Search successfully");
            return p;
        }
    }
    printf("Search unsuccessfully");
    return NULL;
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
int main()
{
    printf("read file:\n");
    head=readfile("data.txt");//读取文件并创建链表
    print(head);//打印
    printf("add:\n");
    addtofile(head);
    printf("display:\n");
    print(head);
    save(head,"data.txt");
    
    //head=create();
}