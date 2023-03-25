#include<stdio.h>
#include<iostream>
int main()
{
    double sum=0,sum1=1,n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        sum1*=i;
        printf("%f\n",sum1);
        sum+=sum1;
    }
    printf("%f",sum);
}
