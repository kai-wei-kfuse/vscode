#include<iostream>
using namespace std;
int a[105];
int vis[10005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }   
    int sum=0;
    for(int i= n;i >= 1; i--){
        for(int j=1;j <= n ;j++){
            if(a[j]==a[i])continue;
            for(int k=1;k<=n;k++){
                if(a[k]==a[i]||a[j]==a[i]||a[k]==a[j])continue;
                if(a[j]+a[k]==a[i] && vis[a[i]]==0){
                    sum++;
                    vis[a[i]]=1;
                    //cout<<a[j]<<' '<<a[k]<<' '<<a[i]<<endl;    
                }   
            }
        }
    }
    cout<<sum;
}