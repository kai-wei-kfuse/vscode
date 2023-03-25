#include<iostream>//FLYOD
#include<cstring>
using namespace std;
//const int inf= 0x3f3f3f;
int mp[110][110];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    memset(mp,0,sizeof(mp));
    for(int i=1;i<=n;i++)mp[i][i]=1;//对角设1，算作自己到自己连通（0也可以）
        int a,b;
        for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);//a->b
        mp[a][b]=1;//1代表有路()
        }
        for(int k=1;k<=n;k++)//Floyd
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++){
                    if(mp[i][k]&&mp[k][j]){
                        mp[i][j]=1;//只要有路，就设1
                    }
                }
        int ans=0;
        for(int i=1;i<=n;i++){
            int ins=0;//计算出入度
            for(int j=1;j<=n;j++){
                ins+=mp[i][j];//遍历矩阵，需要遍历第i行和第i列
                if(i==j)continue;//不重复加(初始化对角为0可以不判断）
                ins+=mp[j][i];
            }
            if(ins==n)ans++;//如果初始化对角为0，这里就是n-1
        }
        printf("%d\n",ans);
}
