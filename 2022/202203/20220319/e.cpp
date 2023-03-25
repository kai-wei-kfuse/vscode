#include<iostream>
using namespace std;
int a[500005];
int visa[500005];
int visb[500005];
int b[500005];
int dp[3][500005];
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=n;i++){
        b[i]=read();
    }
    dp[1][1]=1;
    dp[2][1]=1;
    visa[a[1]]=1;
    visb[b[1]]=1;
    for(int i=1;i<=2;i++){
        
    }
}