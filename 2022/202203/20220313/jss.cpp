#include<iostream>
#include<map>
#include<cstring>
using namespace std;
int vis[10005];
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        //map<int,int >mp;
        memset(vis,0,sizeof(vis));
        int cmp;
        for(int i=1;i<=n;i++){
            cin>>cmp;
            vis[cmp]++;
        }
        int maxn=0;
        /*for(int i=1;i<=5;i++){
            cout<<vis[i]<<' ';
        }*/
        //cout<<endl;
        for(int i=2;i<=10000;i++){
            if(vis[i]+vis[i-1]>maxn)maxn=vis[i]+vis[i-1];
            //cout<<maxn<<endl;
        }
        cout<<maxn<<endl;
        //cout<<mp[2];
        }
    }
