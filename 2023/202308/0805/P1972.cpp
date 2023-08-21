#include<bits/stdc++.h>
using namespace std;

const int N=3e6+5;
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int tree[N];
int n,m;
vector<int >vis(N);
struct xx{
    int x,y,id,f;
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

int lowbit(int x){
    return x&-x;
}

void add(int x,int val){
    while(x<=n){
        tree[x]+=val;
        x+=lowbit(x);
    }
}

int search(int x){
    int ans=0;
    while(x!=0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}

int main(){
    ios;
    cin>>n;
    vector<xx >ve;
    
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        ve.push_back({i,vis[tmp]+1,0,0});
        vis[tmp]=i;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        ve.push_back({r,l,i,1});
        ve.push_back({l-1,l,i,-1});
    }
    sort(ve.begin(),ve.end());
    vector<int >ans(m+1);
    for(auto [x,y,id,f]:ve){
        if(f==0){
            add(y,1);
            //cout<<y<<' ';
        }else{
            ans[id]+=f*search(y);
        }
    }
    //cout<<endl;
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<'\n';
    }
}