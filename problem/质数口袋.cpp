#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    char s[1000];
    int sum=0;
    gets(s);
    for(int i=0;s[i];i++)
    {
        if(s[i] ==' ')continue;
        sum++;
    }
    cout<<sum;
}