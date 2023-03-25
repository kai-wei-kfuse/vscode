#include<iostream>//一维差分模板
using namespace std;
int a[100010];
int b[100010];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i]-a[i-1];
    }
    while(m--){
        int l,r,c;
        scanf("%d %d %d",&l,&r,&c);
        b[l]+=c;
        b[r+1]-=c;
    }
    for(int i=1;i<=n;i++){
        a[i]=a[i-1]+b[i];
    }
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
}