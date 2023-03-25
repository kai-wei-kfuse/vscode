#include<iostream>
#include<string.h>
int main()
{
    char a[100],b[100];
    scanf("%s %s",a,b);
    if(strcmp(a,b)==0)printf("same");
    else printf("not same");
    return 0;
} 
