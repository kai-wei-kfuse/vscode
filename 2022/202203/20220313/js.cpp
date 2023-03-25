#include<iostream>
#include<map>
using namespace std;
int vis[10005];
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map<int,int >mp;
        int cmp;
        for(int i=1;i<=n;i++){
            cin>>cmp;
            mp[cmp]++;
        }
        int maxn=0;
        for(map<int ,int >::iterator i=mp.begin(),j=i++;i!=mp.end();i++){
            if((*j).second+(*i).second>maxn)maxn=(*j).second+(*i).second;
        }
        cout<<maxn<<endl;
    }
}