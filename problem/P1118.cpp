#include<iostream>
#include<algorithm>
using namespace std;
int n,sum,flag=0;
int y[20][20],vis[20],ans[20];
void dfs(int p, int s){
    if(flag)
        return;
    if(p>n && s==sum){
            flag=1;
            for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
            return;
        }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]&&s+y[n][p]*i<=sum)
        {
            ans[p]=i;
            vis[i]=1;
            dfs(p+1,s+y[n][p]*i);
            vis[i]=0;
        }
    }
}
int main()
{
    cin>>n>>sum;
    y[1][1]=1;
    for(int i=2;i<13;i++)
        for(int j=1;j<=i;j++)
            y[i][j]=y[i-1][j]+y[i-1][j-1];
    dfs(1,0);
    
    /*for(int i=1;i<13;i++){
        for(int j=1;j<i;j++)
        printf("%d ",y[i][j]);
        printf("\n");
    }*/
}