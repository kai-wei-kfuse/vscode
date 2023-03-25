#include<stdio.h>
int main()
{
    int a[7]={3,4,8,2,78,3,65};
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<6-i;j++)
        {
            if(*(a+j)>*(a+j+1))
            {
                int tmp=*(a+j);
                *(a+j)=*(a+j+1);
                *(a+j+1)=tmp;
            }
        }
    }
    for(int i=0;i<7;i++)
    {
        printf("%d ",*(a+i));
    }
}