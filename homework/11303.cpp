#include<stdio.h>
int function()
{
    static int sum=0;
    for(int i=1;i<=30;i++)
    {
        sum+=i;
        printf("%d\n",sum);
    }
    return sum;
}
int main()
{
    static int sum;
    printf("%d",function());
    return 0;
}