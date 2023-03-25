#include<iostream>//二维前缀和
#include<algorithm>
using namespace std;
int a[102][102];
int b[102][102];
int main()
{
    int n,m;
    int ans=1;
    int len=2;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];//求前缀和
        }
    }
    while(len<=min(n,m))
    {
        for(int i=len;i<=n;i++){
            for(int j=len;j<=m;j++){
                if(b[i][j]-b[i-len][j]-b[i][j-len]+b[i-len][j-len]==len*len)//判断子矩阵里面是否全是1
                    ans=len;
            }
        }
        len++;
    }
    cout<<ans;
}