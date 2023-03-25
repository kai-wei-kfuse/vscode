#include<stdio.h>
int main()
{
    int a[4][5]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int *p1,**p2;
    int (*p3)[5];
    int *p4[4];
    //printf("*p1\n");
    p3=a;
    p1=&a[0][0];
    for(int i=0;i<4;i++)
    {
        p1=a[i];
        //*p2=*(a+i);
        p4[i]=a[i];
        p2=p4;
        for(int j=0;j<5;j++)
        {
            printf("%d ",*(p1+j));
            printf("%d ",*(*(p2+i)+j));
            printf("%d ",*(*(p3+i)+j));
            printf("%d \n",*(p4[i]+j));
        }
    }
    /*printf("**p2\n");
    for(int i=0;i<4;i++)
    {
        *p2=*(a+i);
        for(int j=0;j<5;j++)
        {
            printf("%d ",*(*p2+j));
        }
        printf("\n");
    }
    printf("(*p3)[5]\n");
     for(int i=0;i<4;i++)
    {
        p3=a;
        for(int j=0;j<5;j++)
        {
            printf("%d ",*(*(p3+i)+j));
        }
        printf("\n");
    }
    printf("*p4[4]\n");
     for(int i=0;i<4;i++)
    {
        p4[i]=a[i];
        for(int j=0;j<5;j++)
        {
            printf("%d ",*(p4[i]+j));
        }
        printf("\n");
    }*/
}