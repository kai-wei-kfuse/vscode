#include<iostream>
#include<cstring>
#define maxn 4000015
using namespace std;
int kmp[maxn],lena,lenb;
char a[maxn],b[maxn];
int main()
{
    int n;
    cin>>n;
    cin>>b+1>>a+1;
    kmp[1]=0;
    for(int i=n+1;i<=n*2+1;i++)b[i]=b[i-n];
    for(int i = 2, len = 0; i <= n ;i ++){
        while(len > 0 && a[i] != a[len + 1])len = kmp[len];
        if(a[i] == a[len + 1])len ++;
        kmp[i] = len;
    }
    for(int i = 1,len = 0;i <= 2*n;i ++){
        while(len > 0 &&(b[i] != a[len + 1] || len == n))len = kmp[len];
        if(b[i] == a[len + 1])len ++;
        if(len == n){
            cout<<"wow";
            return 0;
        }
    }
    cout<<"TAT";
    return 0;
}