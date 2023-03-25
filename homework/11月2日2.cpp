#include<stdio.h>
int main()
{
    int sum=0;
    for(int i=1;i<=200;i++)
    {
        if(i%3==0 && i%5)sum+=i;
    }
    printf("%d",sum);
}