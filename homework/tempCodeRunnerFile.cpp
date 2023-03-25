#include<iostream>
#include<string.h>
int main()
{
    //char a[]="123 a34 a342    a432   aaaa aaa";
    char b[100];
    char a[100];
    gets(a);
    int s=0,len=strlen(a);
    for(int i=0;i<=len;i++)
    {
        if(a[i]!=' ')
        b[s++]=a[i];
    }
    printf("%s",b);
}