#include<iostream>
typedef unsigned long long ll;
using namespace std;
ll gcd(ll a, ll b)
{
    return b==0?a:gcd(b, a % b);
}
int main()
{
    int t;
    cin>>t;
    ll a,b,l,r;
    while(t--){
        cin>>a>>b>>l>>r;
        ll gcds=gcd(a,b);
        ll tmp=(a*b)/gcds;
         if(l==0) 
        {
            printf("0\n");
            continue;
        }
        /*int flag=1;
        for(int i=l/tmp;i<=r/tmp;i++){
            if(i*tmp>=l&&i*tmp<=r){
                cout<<i*tmp<<endl;
                flag=0;
                break;
            }
        }
        if(flag)cout<<"-1"<<endl;*/
        if(tmp<=r && tmp>=l)cout<<tmp<<endl;
        else if(tmp>r)cout<<"-1"<<endl;
        else {
            ll x=(l/tmp)*tmp;
            if(x==l)cout<<x<<endl;
            else if(x+tmp>=l&&x+tmp<=r)cout<<x+tmp<<endl;
            else
            cout<<"-1"<<endl;
        }
        //solve(tmp,l,r);  
    }
}