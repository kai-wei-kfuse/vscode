#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int a[20][20];
int sum[5];

int main()
{
    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
            }
        }

        int ans=0;
        for(int i=1;i<=4;i++){
            //cout<<sum[i]<<' ';
            if(ans<sum[i])ans=sum[i];
        }
        //cout<<endl;
        cout<<ans;
        if(n>=1)cout<<endl;
   }
}