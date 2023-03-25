#include<stdio.h>
int sum=0;
int function()
{
    //static int sum;
    for(int i=1;i<=30;i++)
    {
        sum+=i;
    }
    return sum;
}
int main()
{
    //static int sum=0;
    //function();
    printf("%d",function());
    return 0;
}