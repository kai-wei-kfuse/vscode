#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
string x,y;
int a[100005],b[100005],c[100005],lena,lenb;
int main()
{
    cin >> x >> y;
    lena = x.length();
    lenb = y.length();
    if(lena < lenb || lena == lenb && x < y){
        swap(x ,y);
        swap(lena ,lenb);
        cout<<'-';
    }   
    for(int i=0;i<lena;i++){
        a[lena-i]=x[i]-'0';
    }
    for(int i=0;i<lenb;i++){
        b[lenb-i]=y[i]-'0';
    }
    for(int i=1;i<=lena;i++){
        if(a[i]<b[i]){
            a[i+1]--;
            a[i]+=10;
        }
        c[i]=a[i]-b[i];
    }
    while(c[lena]==0 && lena>1)lena--;
    for(int i=lena;i>=1;i--){
        cout<<c[i];
    }
}