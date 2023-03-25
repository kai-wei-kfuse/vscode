#include<stdio.h>
int main()
{
    int a[3][4][5]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60};
    int *p1,**p2;
    int (*p3)[5];
    int *p4[4];
    p1=&a[0][0][0];
    /*int l=1;
    while(l<=60)
    {
        printf("%d ",*p1);
        p1++;
        l++;
    }*/
    for(int i=0;i<3;i++)
    {
        p3=a[i];
        for(int j=0;j<4;j++)
        {
            p1=a[i][j];
            //*p2=*(a+i);
            p4[j]=a[i][j];
            p2=p4;
            for(int k=0;k<5;k++)
            {
                //printf("%d ",a[i][j][k]);
                //printf("%d ",p2[j][k]);
                //printf("%d ",p3[j][k]);
                //printf("%d ",p4[j][k]);
                printf("%d %d  ",a[i][j][k],*(p1+k));
                printf("%d %d  ",p2[j][k],(*(p2+j))[k]);
                printf("%d %d  ",p3[j][k],*(*(p3+j)+k));
                printf("%d %d | ",p4[j][k],*(p4[j]+k));
            }
            printf("\n");
        }
        printf("\n");
    }
}