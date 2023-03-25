#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[1000002];
int a[1000002];
int path[1000002];
int main()
{
    int n,s;
    while(scanf("%d %d",&n,&s)!=EOF){
        memset(dp,0,sizeof(dp));
        memset(path,0,sizeof(path));
        for(int i=1;i<=s;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=s;i++){
            for(int j=n;j>=a[i];j--){
                //dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
                if(dp[j]<dp[j-a[i]]+a[i]){//如果dp[j]=dp[j-a[i]]+a[i]成立，就是选了第i张cd，path记录j时长时i张cd最优解的最后一张cd
                    dp[j]=dp[j-a[i]]+a[i];
                    path[j]=a[i];
                    //cout<<j<<' '<<a[i]<<' '<<path[j]<<'|';
                }
            }
        }
        int paths=dp[n];
        int ans[25],k=0;
        while(path[paths]!=0){//不等于0代表选了，等于0就是没选那张cd
            ans[++k]=path[paths];
            paths-=path[paths];//开始找前面的cd
        }
        for(int i=k;i>=1;i--){
            cout<<ans[i]<<' ';
        }
        cout<<"sum:"<<dp[n]<<endl;
    }
}