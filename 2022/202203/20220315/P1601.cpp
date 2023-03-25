#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
string x,y;
int a[100005],b[100005],c[100005],lena,lenb,lenc;
int main()
{
    cin>>x>>y;
    lena=x.length();
    lenb=y.length();
    for(int i=0;i<lena;i++){
        a[lena-i]=x[i]-'0';
    }
    for(int i=0;i<lenb;i++){
        b[lenb-i]=y[i]-'0';
    }
    lenc=max(lena,lenb);
    for(int i=1;i<=lenc;i++){
        c[i]+=b[i]+a[i];
        c[i+1]=c[i]/10;
        c[i]%=10;
    }
    if(c[lenc+1])lenc++;
    for(int i=lenc;i>=1;i--){
        cout<<c[i];
    }
}