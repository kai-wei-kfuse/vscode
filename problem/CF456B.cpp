#include<iostream>
#include<cstring>
using namespace std;
//Q : 如何判断一个数是否为 4 的倍数？ A : 看末两位是否为 4 的倍数即可。
//Q : 如何判断一个数是否为 2 的倍数？ A : 看末尾是否为 2 的倍数即可。
int three[]={1,2,4,3};
int two[]={1,3,4,2};
int four[]={1,4};
char a[1000000];
int main()
{
    cin>>a;
    int n;
    int len=strlen(a);
    if(len>=2)
        n=a[len-1]-'0'+(a[len-2]-'0')*10;
    else
        n=a[len-1]-'0';
    cout<<(1+two[n%4]+three[n%4]+four[n%2])%5;
    return 0;
}