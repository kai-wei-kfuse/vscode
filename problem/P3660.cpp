#include<iostream>//FLYOD
#include<cstring>
using namespace std;
//const int inf=0x3f3f3f;
int mp[110][110];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    memset(mp,0,sizeof(mp));
    for(int i=1;i<=n;i++)mp[i][i]=1;
        int a,b;
        for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);//a->b
        mp[a][b]=1;//1代表有路()
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++){
                    if(mp[i][k]&&mp[k][j]){
                        mp[i][j]=1;
                    }
                }
        int ans=0;
        for(int i=1;i<=n;i++){
            int ins=0;
            for(int j=1;j<=n;j++){
                ins+=mp[i][j];
                if(i==j)continue;
                ins+=mp[j][i];
            }
            if(ins==n)ans++;
        }
        printf("%d\n",ans);
}