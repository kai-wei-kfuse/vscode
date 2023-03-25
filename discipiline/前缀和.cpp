#include<iostream>
using namespace std;
int a[100010];
long long b[100010];
int main()
{
    int len,q;
    cin>>len>>q;
    for(int i=1;i<=len;i++)
    {
        cin>>a[i];
        b[i]=a[i]+b[i-1];
    }
    while(q--){
        int f,t;
        cin>>f>>t;
        cout<<b[t]-b[f-1]<<endl;
    }
}