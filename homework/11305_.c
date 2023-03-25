#include<stdio.h>
#include<string.h>
int s=0;
int string_int(char *str)
{
    int i,n; 
    for (i=0,n=0;str[i]!=0; i++)
        n=n*10+(str[i]-'0'); 
    return n;
}
int main()
{
    char a[100];
    char b[100],c[100],d[100];
    gets(a);
    int len=strlen(a);
    for(int i=0;i<len;i++)
    {
        if(a[i]!=' ')b[s++]=a[i];
    }
    //printf("%s",b);
    s=0;
    while(b[s]-'0'<=9&&b[s]-'0'>=0)
    {
        s++;
    }
    //printf("%d ",s);
    for(int i=0;i<s;i++)
    {
        c[i]=b[i];
    }
    int j=0,lenb=strlen(b);
    for(int i=s+1;i<lenb;i++)
    {
        d[j++]=b[i];
    }
    int A=string_int(c);
    int B=string_int(d);
    //printf("%s %s %s ",b,c,d);
    //int B=string_n(b);
    if(b[s]=='+')printf("%d",A+B);
    else if(b[s]=='-')printf("%d",A-B);
    else if(b[s]=='*'||b[s]=='x'||b[s]=='X')printf("%d",A*B);
    else if(b[s]=='/')printf("%d",A/B);
    else printf("error!!");
}