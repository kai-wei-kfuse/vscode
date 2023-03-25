#include<stdio.h>
int main()
{
    int sum=0,sum1=0,n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        sum1=i;
        for(int j=1;j<i;j++)
        {
            sum1*=10;
            sum1+=i;
        }
        sum+=sum1;
    }
    printf("%d",sum);
}