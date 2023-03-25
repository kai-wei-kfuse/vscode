#include<iostream>
#include<string.h>
using namespace std;
char a[200];
int main()
{
    scanf("%s",a);
    int len=strlen(a);
    for(int i=len-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if((int)a[j]>(int)a[j+1])
            {
                char tmp=a[j+1];
                a[j+1]=a[j];
                a[j]=tmp;
            }
        }
    }
    printf("%s",a);
}