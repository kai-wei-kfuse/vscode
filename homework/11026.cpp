#include<stdio.h>
int main()
{
    for(int i=10000;i<=99999;i++)
        for(int j=2;j<=9;j++)
        {
            int m=(i%10)*10000+((i/10)%10)*1000+((i/100)%10)*100+((i/1000)%10)*10+i/10000;
            if(i*j==m)printf("5:%d N=%d\n",i,j);
        }
}