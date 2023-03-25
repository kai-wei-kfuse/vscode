#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct xx{
    string a;
    int b;
}c[100005];
int main()
{
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>c[i].a>>c[i].b;
        sum+=c[i].b;
    }
    int p=(sum/n)/2;
    int mins=0x3f3f3f;
    int cmp;
    for(int i=1;i<=n;i++){
        if(mins>abs(p-c[i].b)){
            cmp=i;
            mins=abs(p-c[i].b);
        }
    }
    cout<<p<<' '<<c[cmp].a;
}