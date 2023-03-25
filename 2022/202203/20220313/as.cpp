#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<vector>
using namespace std;
int a[100105];
//int vis[1000000002];
//vector<int >vis;
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x*f;
}
map<int,int>mp;
int main()
{
    int n;
    n=read();
    while(n--){
        int l,m;
        int sum=0;
        l=read();m=read();
        memset(a,0,sizeof(a));
        for(int i=1;i<=l;i++){
            a[i]=read();
            if(a[i]!=0 && mp[a[i]]==0)sum++;
            mp[a[i]]++;
        }
        int x;
        for(int i=1;i<=m;i++){
            x=read();
            if(x==1){
                int f,s;
                f=read();
                s=read();
                if(a[f]!=s){
                    //cout<<' '<<sum;
                    if(mp[s]==0)sum++;
                    //cout<<' '<<sum;
                    mp[a[f]]--;
                    int tmp=a[f];
                    a[f]=s;
                if(mp[tmp]==0)sum--;
                    mp[a[f]]++;
                    //cout<<' '<<sum;
                }
            }
            else {
                //int ans=0;
                //mp.clear();
                //set<int > se;
                //memset(vis,0,sizeof(vis));
                //for(int i=1;i<=l;i++){
                    /*if(vis[a[i]]==0){
                        vis[a[i]]=1;
                        ans++;
                    }*/
                    //if(a[i]!=0)
                    //if(mp.find(a[i])==mp.end())
                    //mp.insert(make_pair(a[i],1));
                    //mp[a[i]]=1;
                    //mp.(a[i],1);
                    //if(se.find(a[i])==se.end())
                    //se.insert(a[i]);
                //}
                //cout<<ans<<endl;
                printf("%d\n",sum);
                //cout<<se.size()<<endl;
            }
        }
    }
}