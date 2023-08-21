#include<bits/stdc++.h>
using namespace std;


#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long

struct xx{
    int x,y,f,id,val;
    bool operator < (const xx &a)const{
        if(x==a.x){
            if(y==a.y){
                return id<a.id;
            }
            return y<a.y;
        }
        return x<a.x;
    }
};
int tree[1000005];

vector<xx >ve;
vector<int >yyy;
int n,m;
int len;

inline int lowbit(int x){
    return x&(-x);
}
inline void add(int i,int a){//单点增加
    while(i<=len){
        tree[i]+=a;
        i+=lowbit(i);
    }
}
inline int search(int i){//前缀和查询
    int ans=0;
    while(i!=0){
        ans+=tree[i];
        i-=lowbit(i);
    }
    return ans;
}

signed main(){
   // ios;
    cin>>n>>m;
    //n=read(),m=read();
    for(int i=1;i<=n;i++){
        int x,y,val;
        //x=read(),y=read();
        
        cin>>x>>y>>val;
        ve.push_back({x,y,0,0,val});
        yyy.push_back(y);
    }
    for(int i=1;i<=m;i++){
        int a1,b1,a2,b2;
        cin>>a1>>b1>>a2>>b2;
        //a1=read(),b1=read(),a2=read(),b2=read();
        ve.push_back({a1-1,b1-1,1,i});
        ve.push_back({a2,b2,1,i});
        ve.push_back({a1-1,b2,-1,i});
        ve.push_back({a2,b1-1,-1,i});
        yyy.push_back(b1-1);
        yyy.push_back(b2);
    }
    sort(ve.begin(),ve.end());
    sort(yyy.begin(),yyy.end());
    yyy.erase(unique(yyy.begin(),yyy.end()),yyy.end());
    len=yyy.size();
    vector<int >ans(m+1);
    for(auto [x,y,f,id,val]:ve){
        int y_=lower_bound(yyy.begin(),yyy.end(),y)-yyy.begin()+1;
        
        if(f==0){
           // cout<<y_<<'\n';
            add(y_,val);
        }else{
            //cout<<y_<<' '<<search(y_)<<'\n';
            ans[id]+=f*search(y_);
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<'\n';
        //printf("%d\n",ans[i]);
    }
}