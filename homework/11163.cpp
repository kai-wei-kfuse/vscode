#include<iostream>
#include<string.h>
int main()
{
    char a[1000],b[1000],c[1000],d[3000];
    scanf("%s %s %s",a,b,c);
    int len1=strlen(a),len2=strlen(b),len3=strlen(c);
    for(int i=0;i<len1;i++)
        d[i]=a[i];
    for(int i=len1;i<len1+len2;i++)
        d[i]=b[i-len1];
    for(int i=len1+len2;i<len1+len2+len3;i++)
        d[i]=c[i-len1-len2];
    printf("%s",d);
}
