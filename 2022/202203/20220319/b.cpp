#include<iostream>
using namespace std;
int d[112][112];
int main()
{
    int n,m;
    cin>>n>>m;
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        x+=1;y+=1;
        d[x-1][y-1]+=1;
        d[x+2][y+2]+=1;
        d[x-1][y+2]-=1;
        d[x+2][y-1]-=1;
    }
    int sum=0;
    //for(int i=0;i<=m;i++)d[0][i]=0;
    //for(int i=0;i<=n;i++)d[i][0]=0;
    for(int i=1;i<=n+2;i++){
        for(int j=1;j<=m+2;j++){
            //cout<<d[i][j]<<' ';
            
            d[i][j]=d[i-1][j]+d[i][j-1]-d[i-1][j-1]+d[i][j];
            //cout<<d[i][j]<<' ';
            
        }
        //cout<<endl;
    }
    for(int i=2;i<=n+1;i++){
        for(int j=2;j<=m+1;j++){
    if(d[i][j]>0)sum++;
        }}
    cout<<sum;
}