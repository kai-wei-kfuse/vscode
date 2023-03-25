#include<iostream>
using namespace std;
int f[50][50];
int dfs(int i,int j){
    if(i==0){
        return f[i][j]=1;
    }
    if(f[i][j])return f[i][j];
    else{
        if(j==0){
            return f[i][j]=dfs(i-1,j+1);
        }
        if(j>0){
            return f[i][j]=dfs(i-1,j+1)+dfs(i,j-1);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    dfs(n,0);
    cout<<f[n][0];
}