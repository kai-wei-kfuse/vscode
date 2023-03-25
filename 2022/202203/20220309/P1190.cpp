#include<iostream>
#include<algorithm>
using namespace std;
int b[200];
int st[100005];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>st[i];
    }
    int i=0,j=0;
    int time=0;
    while(j<m)b[++j]=st[++i];
    while(i<=n){//i代表同学
        sort(b+1,b+m+1);
        //for(int i=1;i<=m;i++)cout<<b[i]<<' ';
        //cout<<endl;
        time+=b[1];
        for(int k=m;k>=1;k--){
            b[k]=b[k]-b[1];
        }
        //for(int i=1;i<=m;i++)cout<<b[i]<<' ';
        //cout<<endl;
        b[1]=st[++i];
        if(i>=n)break;
    }
    sort(b+1,b+m+1,greater<int >());
    time+=b[1];
    cout<<time;
}