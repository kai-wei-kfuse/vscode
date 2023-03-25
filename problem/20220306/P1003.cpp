#include<iostream>
using namespace std;
int a[100005],b[100005],g[100005],k[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&a[i],&b[i],&g[i],&k[i]);
    }
    int x,y;
    scanf("%d%d",&x,&y); 
    for(int i=n;i>=1;i--){
        if(x>=a[i] && x<=a[i]+g[i] && y>=b[i] && y<=b[i]+k[i]){cout<<i;return 0;}
    }
    cout<<"-1";
}