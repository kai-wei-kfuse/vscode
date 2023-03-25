#include<stdio.h>
#include<iostream>
int main()
{
    double sum=0,sum1=1;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        sum1*=i;
        printf("%.0f\n",sum1);
        sum+=sum1;
    }
    printf("%.0f",sum);
}