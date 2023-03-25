#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char* a;
    char s[1000];
    memset(s,0,sizeof(s));
    a=(char*)malloc(sizeof(char));
    while(gets(a)&&strlen(a)!=0)
    {
       // printf("%s",s);
        strcat(s,a);
        a=(char*)malloc(200*sizeof(char));
    }
    //printf("%d",len);
    printf("%s",s);
    return 0;
}