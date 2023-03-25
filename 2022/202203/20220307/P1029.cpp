#include<iostream>//28mins
typedef long long ll;
using namespace std;
ll gcds(ll a, ll b)
{
    return b==0?a:gcds(b, a % b);
}
int main()
{
    int gcd,lcm;
    cin>>gcd>>lcm;
    ll num=gcd*lcm;
    ll p,q,sum=0,Gcd;
    for(p=gcd;p<=lcm;p++)
    {
        if(num%p==0){
            q=num/p;
            if(p>=q)
            Gcd=gcds(p,q);
            else if(p<q)
            Gcd=gcds(q,p);
            if(p*q/Gcd==lcm && Gcd==gcd){
                //cout<<p<<' '<<q<<endl;
            sum++;
            }
        }
    }
    cout<<sum;
}