#include<iostream>
using namespace std;
#define mod 998244353
typedef unsigned long long ll;
ll a[504];
int main()
{
    int n;
    cin>>n;
    int tmp;
    a[1]=1;
    for(int i=2;i<=500;i++){
        a[i]=a[i-1]*i%mod;
    }
    while(n--){
        cin>>tmp;
        if(tmp%2!=0)cout<<"0"<<endl;
        else cout<<a[tmp/2]*a[tmp/2]%mod<<endl;
    }
}