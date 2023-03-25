#include<iostream>
using namespace std;
int f[22];
int anum[22];
int xnum[22];
int main()
{
    int a,n,m,x;
    cin>>a>>n>>m>>x;
    f[1]=1;f[2]=1;
    if(x==1||x==2){
        cout<<a;
        return 0;
    }
    for(int i=3;i<n;i++){
        f[i]=f[i-1]+f[i-2];
        anum[i]=f[i-2]+1;
        xnum[i]=xnum[i-1]+f[i-3];
        //cout<<anum[i]<<' '<<xnum[i]<<endl;
    }
    int y=(m-a*anum[n-1])/xnum[n-1];
    cout<<a*anum[x]+y*xnum[x];
}