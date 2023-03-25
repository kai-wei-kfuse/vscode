#include<stdio.h>
int sum=0;
void digui(int a)
{ 
    if(a>30){
        printf("%d",sum);
        return ;
    }
    sum+=a;
    printf("%d\n",sum);
    return digui(a+1);
}
int main()
{
    digui(1);
    return 0;
}