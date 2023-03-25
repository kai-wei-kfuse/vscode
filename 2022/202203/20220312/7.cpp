#include<iostream>
using namespace std;
int main()
{
    int a,b;
    int f,s,t;
    cin>>a>>b;
    cin>>f>>s>>t;
    int ans=3-(f+s+t);
    int bns=f+s+t;
    if((a>b && f+s+t<=2)||(a<b)&& f+s+t==0)cout<<"The winner is a: "<<a<<" + "<<ans;
    if((b>a && f+s+t>=1)||(a>b)&& f+s+t==3)cout<<"The winner is b: "<<b<<" + "<<bns;
}