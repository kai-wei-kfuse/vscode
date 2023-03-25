#include<iostream>
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f*=-1;ch=getchar();}
    while('0'<=ch && ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*f;
}
int main()
{
    int n;
    scanf("%d",&n);
    int res=0;
    for(int i=1;i<=n;i++){
        int k;
        k=read();
        if(i==1)res=k;
        else res^=k;
    }
    cout<<res<<endl;
}