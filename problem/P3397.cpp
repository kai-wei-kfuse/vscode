#include<iostream>//二维差分
using namespace std;
int a[1002][1002];
int b[1002][1002];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x1,y1,x2,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        b[x1][y1]+=1;
        b[x2+1][y2+1]+=1;
        b[x1][y2+1]-=1;
        b[x2+1][y1]-=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[i][j]=b[i][j]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
}