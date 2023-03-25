#include<iostream>
typedef long long ll;
using namespace std;
ll x,y;
ll exgcd(ll a, ll b){
    if(!b){
        x=1;
        y=0;
        return a;
    }
    ll res=exgcd(b,a%b);
    ll tmp=x;
    x=y;
    y=tmp-(a/b)*y;
    return res;
}
int main()
{
    ll xx,yy,n,m,l;
    cin>>xx>>yy>>m>>n>>l;
    ll a=m-n<0?n-m:m-n;
    ll c=m-n<0?xx-yy:yy-xx;
    ll b=l;
    ll gcd=exgcd(a,b);
    //cout<<a<<' '<<b<<' '<<c<<' '<<x<<' '<<gcd<<' ';
    if(c%gcd!=0)cout<<"Impossible";
    else {
        //x=x*(c/gcd);
        cout<<(x*(c/gcd)%(b/gcd)+b/gcd)%(b/gcd);
    }
}