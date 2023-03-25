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
        if(mp.size()==1){
            map<int ,int >::iterator i=mp.begin();
            cout<<(*i).second<<endl;
            }
        else{
        for(map<int ,int >::iterator i=mp.begin(),j=i++;j!=mp.end();i++){
            
            if((*j).second+(*i).second>maxn)maxn=(*j).second+(*i).second;
        }
        cout<<maxn<<endl;
        //cout<<mp[2];
        }
    }
}
