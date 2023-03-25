#include<iostream>
using namespace std;
int m[103];
int x[103][103];
int sum;
int y[102];
int z[102];
int u[102];
int vis[102];
int main()
{
    int n;
    cin>>n;
    int num=n;
    for(int i=1;i<=n;i++){
        cin>>m[i];
        y[i]=m[i]*10;
        u[i]=m[i]*10;
        sum+=m[i];
    }
    int flag=0;
    sum*=10;
    for(int i=0;i<=sum;){
        for(int j=1;j<=n;j++){
            if(!y[j]&&!vis[j]){
                num--;
                //cout<<num<<endl;
                vis[j]=1;
            }
            /*if(num==1){
                flag=1;
                break;
                }*/
            if(num==1){
                int j;
                for(j=1;j<=n;j++)if(y[j]!=0)break;
                while(y[j]){
                    if(i==0)i=1;
                    else i+=2;
                    x[j][++z[j]]=i;
                    y[j]--;
                }
                flag=1;
                break;
            }
            if(y[j]){
            x[j][++z[j]]=++i;
            y[j]--;
            }
        }
        if(flag)break;
    }
    //cout<<num<<endl;

    //for(int i=1;i<=n;i++)cout<<vis[i]<<' ';
    for(int j=1;j<=n;j++){
        cout<<'#'<<j<<endl;
        //cout<<y[j]<<endl;
        for(int i=1;i<=u[j];i++){
            
            cout<<x[j][i];
            if(i%10!=0)
            cout<<' ';
            if(i%10==0&&i<u[j])cout<<endl;
        }
        if(j<n)cout<<endl;
    }
}