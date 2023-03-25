#include<iostream>
using namespace std;
long long x;
long long y;
void exgcd(long long a,long long b){
    if(!b){
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b);
    int tmp=x;
    x=y;
    y=tmp-(a/b)*y;
}
int main()
{
    long long a,b;
    cin>>a>>b;
    exgcd(a,b);
    cout<<(x%b+b)%b;
}