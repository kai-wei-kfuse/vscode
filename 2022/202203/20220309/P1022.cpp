#include<iostream>
#include<cstdio>
using namespace std;
char a;
int now=1,f=1,b,k,x;//x是存数的
char s;
int r;//r判断是否输入数字，如果是-x，或者是x，那么前面就没有数字
int main()
{//b是常数，k是未知数的系数
    while(cin>>a){
        if(a=='-'){b+=now*f*x;f=-1;x=0;r=0;}
        if(a=='+'){b+=now*f*x;f=1;x=0;r=0;}
        if(a=='='){b+=now*f*x;now=-1;x=0;f=1;r=0;}
        if(a>='0'&&a<='9'){
            x=x*10+a-'0';
            r=1;
        }
        if(a>='a'&&a<='z'){
            if(r){
                k+=now*f*x;x=0;
            }
            else{
                k+=now*f;
            }
            s=a;//存字符，最后输出
            r=0;
        }
    }
    b+=now*f*x;
    double ans=-(double)b/(double)k;
    if(ans==-0.0)ans=0;
    printf("%c=%.3lf",s,ans);
}