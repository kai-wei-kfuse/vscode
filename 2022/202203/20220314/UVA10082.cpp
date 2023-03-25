#include<iostream>
#include<cstring>
using namespace std;
char a[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main()
{
    char c;int i;
    while((c=getchar())!=EOF){
        if(c==' ')putchar(c);
        else
        for(i=1; a[i] && a[i]!=c; i++)
            if(a[i])putchar(a[i-1]);
}