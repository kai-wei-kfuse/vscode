/*��ĩ����ҵ
���һ�������˹���ϵͳ���ȿȣ���Ȼ���ǹ���ϵͳ������ʵ�ֵĹ��ܿ���Ҫ�Ѻࣩܶ
��������һ�������˲��ȣ����Ǿ�ֻ��һ�������ˣ����ܽ����κβ�����������Ҫ���Ǳ��ȥʵ������һЩ���ܣ�
��������������һ������Ա������ϣ������������������ݴ��롣�����������ʵ�ֵĹ���Ҳ�Ǻ��ٵģ������ճ���ʾʲô��
�� ����һ���¼����ţ������¼���ʱ�ڡ�����ʱ�䣨ʱ���룩���¼����� ����һ���ṹ��ʵ�֣�
�� �����е��¼�����һ����ʱ����Ⱥ�����
�� ɾ��һ���¼�������ʱ������¼�����ɾ��������ɾ����Ҫʵ�֣�
�� ���Ҿ����¼�����Ҫ����ɵ��¼�
�� �޸�һ���¼��ľ���ʱ��
�� �������ѣ���ȷ�е�ʱ��������������ȥ���Ǽ����飨��ȡϵͳ��ǰʱ�伴�ɣ�
��ҵҪ�󣺲�������c++�Ŀ⺯��������ʹ�ýṹ��Ͷ�̬������ɣ����򲻿��Ե���sort������ ����˵������������ҵ��ֻ����c���Ե�ͷ
�ļ������ܳ���c++��ͷ�ļ���*/
/*#include <stdio.h>
#include <time.h>
int main ()
{
    time_t t;
    struct tm * lt;
    time (&t);//��ȡUnixʱ�����
    lt = localtime (&t);//תΪʱ��ṹ��
    printf ( "%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);//������
    return 0;
}*/
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<pthread.h>
#include<time.h>
#include<string.h>
 
pthread_t ntid;
pthread_t tid;
struct node
{
    char s[200];
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    struct node *next;
};
struct node *head;
 
struct node *stusort()
{
    struct node *pre,*p,*temp;
    pre=head;
    while(pre->next->next!=NULL)
    {
        p=head->next;
        pre=head;
        while(p->next!=NULL)
        {
            if(p->year>p->next->year)
            {
                pre->next=p->next;
                temp=p->next->next;
                p->next->next=p;
                p->next=temp;
                p=pre->next;
            }
            else if(p->year==p->next->year)
            {
                if(p->month>p->next->month)
                {
                    pre->next=p->next;
                    temp=p->next->next;
                    p->next->next=p;
                    p->next=temp;
                    p=pre->next;
                }
                else if(p->month==p->next->month)
                {
                    if(p->day>p->next->day)
                    {
                        pre->next=p->next;
                        temp=p->next->next;
                        p->next->next=p;
                        p->next=temp;
                        p=pre->next;
                    }
                    else if(p->day==p->next->day)
                    {
                        if(p->hour>p->next->hour)
                        {
                            pre->next=p->next;
                        temp=p->next->next;
                        p->next->next=p;
                        p->next=temp;
                        p=pre->next;
                        }
                        else if(p->hour==p->next->hour)
                        {
                            if(p->minute>p->next->minute)
                            {
                                pre->next=p->next;
                        temp=p->next->next;
                        p->next->next=p;
                        p->next=temp;
                        p=pre->next;
                            }
                            else if(p->minute==p->next->minute)
                            {
                                if(p->second>p->next->second)
                                {
                                    pre->next=p->next;
                        temp=p->next->next;
                        p->next->next=p;
                        p->next=temp;
                        p=pre->next;
                                }
                            }
                        }
                    }
                }
            }
 
        p=p->next;
        pre=pre->next;
        }
    }
    return head;
}
void show()
{
    struct node *tail;
    tail=head->next;
    while(tail)
    {
        printf("%s\n",tail->s);
        tail=tail->next;
    }
}
void *threadone(void*)
{
    struct node *p;
    p=(node*)malloc(sizeof(node));
    Sleep(1000);
    while(1)
    {
        p=head->next;
       while(p)
       {
           time_t t;
           struct tm *lt;
           time(&t);
           lt=localtime(&t);
           if(lt->tm_year+1900==p->year&&lt->tm_mon+1==p->month&&lt->tm_mday==p->day&&lt->tm_min==p->minute&&lt->tm_sec==p->second) {
                printf("%s\n",p->s);
                Sleep(1000);
           }
            p=p->next;
       }
    }
    return NULL;
}
    /*struct node *p;
    p=head->next;
        time_t t;
        struct tm *lt;
        time(&t);
        lt=localtime(&t);
        for(;p!=NULL;p=p->next)
        {
            if(lt->tm_year+1900==p->year&&lt->tm_mon+1==p->month&&lt->tm_mday==p->day&&lt->tm_min==p->minute&&lt->tm_sec==p->second)
                printf("%s\n",p->s);
        }
    return NULL;
    struct node *p;
    p=head->next;
    while(1)
    {
        time_t t;
        struct tm *lt;
        time(&t);
        lt=localtime(&t);
        if(lt->tm_year+1900==p->year&&lt->tm_mon+1==p->month&&lt->tm_mday==p->day&&lt->tm_min==p->minute&&lt->tm_sec==p->second)
                printf("%s\n",p->s);
        if(lt->tm_year+1900!=p->year)
            {
                Sleep(1000000);
            }
        else if(lt->tm_year+1900==p->year)
        {
            if(lt->tm_mon+1!=p->month)
            {
                Sleep(1000000);
            }
            else if(lt->tm_mon==p->month)
            {
                if(lt->tm_mday!=p->day)
                {
                    Sleep(1000000000);
                }
                else if(lt->tm_mday==p->day)
                {
                    if(lt->tm_hour!=p->hour)
                    {
                        Sleep(100000000);
                    }
                    else if(lt->tm_hour==p->hour)
                    {
                        if(lt->tm_min-p->minute>1)
                        {
                            Sleep(1000);
                        }
                        else if(lt->tm_min==p->minute&&lt->tm_sec==p->second)
                        {
                            printf("%s\n",p->s);
                            p=p->next;
                        }
                    }
                }
            }
        }*/
void* threadtwo(void *)
{
    printf("����ʼ����\n");
    head->next=NULL;
    while(1)
    {
    printf("��ѡ��һ��Ҫִ�еĹ���\n");
    printf("1     ����һ���¼�����\n");
    printf("2     ���Ѳ�����¼������������\n");
    printf("3     ��ʱ��ɾ��һ���¼������ʣ�µ��¼�\n");
    printf("4     ���¼�����ɾ��һ���¼������ʣ�µ��¼�\n");
    printf("5     ����һ�������¼��������ʱ��\n");
    printf("6     �޸�һ���¼��ľ���ʱ�䲢���\n");
    printf("7     ��������\n");
    int  ch;
    scanf("%d",&ch);
    if(ch==1)
    {
        struct node *p;
        p=(struct node *)malloc(sizeof(struct node));
        printf("�������¼���ʱ������ݣ���ʽ��2018 2 2 18 20 15 �Ͽ�,�м���һ���ո����\n");
        scanf("%d %d %d %d %d %d %s",&p->year,&p->month,&p->day,&p->hour,&p->minute,&p->second,p->s);
        p->next=head->next;
        head->next=p;
    }
    else if(ch==2)
    {
        head=stusort();
        struct node *q;
        q=head->next;
        while(q)
        {
            printf("%s\n",q->s);
            q=q->next;
        }
    }
    else if(ch==3)
    {
        printf("������Ҫɾ���¼��ľ���ʱ��,�� �� �� ʱ �� �룬��2018 2 2 18 20 15���м���һ���ո����\n");
        int y,m,d,h,minu,sd;
        scanf("%d %d %d %d %d %d",&y,&m,&d,&h,&minu,&sd);
        struct node *p1;
        struct node *p2;
        p1=head;
        while(p1->next!=NULL)
        {
            if(p1->year!=y||p1->month!=m||p1->day!=d||p1->hour!=h||p1->minute!=minu||p1->second!=sd)
            {
                p2=p1;
                p1=p1->next;
            }
            if(p1->year==y&&p1->month==m&&p1->day==d&&p1->hour==h&&p1->minute==minu)
            {
                p2->next=p1->next;
                free(p1);
                if(p2->next)
                {
                    p1=p2->next;
                }
            }
        }
            printf("�¼��ѳɹ�ɾ��������Ϊʣ�µ��¼�\n");
            show();
    }
    else if(ch==4)
    {
        printf("������Ҫɾ���¼��ľ�������\n");
        char s1[200];
        scanf("%s",s1);
        struct node *p1;
        struct node *p2;
        p1=head;
        while(p1->next!=NULL)
        {
            if(strcmp(p1->s,s1)!=0)
            {
                p2=p1;
                p1=p1->next;
            }
            if(strcmp(p1->s,s1)==0)
            {
                p2->next=p1->next;
                free(p1);
                p1=p2->next;
            }
        }
            printf("�¼��ѳɹ�ɾ��������Ϊʣ�µ��¼�\n");
            show();
    }
    else if(ch==5)
    {
        printf("������Ҫ���ҵľ����¼�\n");
        char s2[100];
        scanf("%s",s2);
        struct node *p1;
        p1=head->next;
        while(p1)
        {
            if(strcmp(p1->s,s2)!=0)
            {
                p1=p1->next;
            }
            else
            {
                printf("���¼���ʱ��Ϊ%d��%d��%d��%dʱ%d��%d��\n",p1->year,p1->month,p1->day,p1->hour,p1->minute,p1->second);
                break;
            }
        }
    }
    else if(ch==6)
    {
        printf("������Ҫ�޸ĵ��¼����������޸�֮���ʱ�䣬ʱ���ʽ���� �� �� ʱ �� ������\n");
        char s_after[200];
        int y_a,mon_a,day_a,hour_a,minute_a,sec_a;
        scanf("%s %d %d %d %d %d %d",s_after,&y_a,&mon_a,&day_a,&hour_a,&minute_a,&sec_a);
        struct node *p5;
        p5=head->next;
        while(p5)
        {
            if(strcmp(p5->s,s_after)!=0)
            {
                p5=p5->next;
            }
            else
            {
                p5->year=y_a;
                p5->month=mon_a;
                p5->day=day_a;
                p5->hour=hour_a;
                p5->minute=minute_a;
                p5->second=sec_a;
                printf("�¼�ʱ���޸ĳɹ�����Ϊ%d��%d��%d��%dʱ%d��%d��\n",y_a,mon_a,day_a,hour_a,minute_a,sec_a);
                break;
            }
        }
    }
    else if(ch==7)
        {
            struct node *q,*r;
            q=head;
            r=q;
            while(q)
            {
                r=q->next;
                free(q);
                q=r;
            }
            exit(0);
        }
    }
    return NULL;
}
int main()
{
    head=(struct node*)malloc(sizeof(struct node));
    pthread_create(&ntid,NULL,threadtwo,NULL);
    pthread_create(&tid,NULL,threadone,NULL);
    Sleep(1000000000);
}