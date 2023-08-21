#include<bits/stdc++.h>
using namespace std;


#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

inline char nc(){
    #define SIZE 1000000+5
    static char buf[SIZE],*p1 = buf+SIZE,*p2 = buf+SIZE;
    if(p1 == p2){
        p1 = buf;p2 = buf+fread(buf,1,SIZE,stdin);
        if(p1 == p2) return -1;
    }
    return *p1++;
}
inline int read(){
    int x = 0;char ch = nc();int flag = 0;
    while(!isdigit(ch)){
        if(ch == '-') flag = -1;
        ch = nc();
    }
    while(isdigit(ch)){
        x = (x<<1) + (x<<3) + (ch^'0');
        ch = nc();
    }
    if(flag) x = -x;
    return x;
}

struct xx{
    int x,y,f,id;
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
int tree[10000005];

//vector<xx>ve;
xx ve[1000005];
//vector<int >yyy;
int ans[1000005];
int n,m;

inline int lowbit(int x){
    return x&(-x);
}
inline void add(int i,int a){//单点增加
    while(i<=n){
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

int  main(){
    //ios;
    //cin>>n>>m;
    n=read(),m=read();
    int cnt=0;
    for(int i=1;i<=n;i++){
        int x,y;
        x=read(),y=read();
        
        //cin>>x>>y;
        x++,y++;
        //ve.push_back({x,y,0,0});
        ve[++cnt]={x,y,0,0};
        //yyy.push_back(y);
    }
    for(int i=1;i<=m;i++){
        int a1,b1,a2,b2;
        //cin>>a1>>b1>>a2>>b2;
        
        a1=read(),b1=read(),a2=read(),b2=read();
        a1++,b1++,a2++,b2++;
        // ve.push_back({a1-1,b1-1,1,i});
        // ve.push_back({a2,b2,1,i});
        // ve.push_back({a1-1,b2,-1,i});
        // ve.push_back({a2,b1-1,-1,i});
        ve[++cnt]={a1-1,b1-1,1,i};
        ve[++cnt]={a2,b2,1,i};
        ve[++cnt]={a1-1,b2,-1,i};
        ve[++cnt]={a2,b1-1,-1,i};
    
        // yyy.push_back(b1-1);
        // yyy.push_back(b2);
    }
    sort(ve.begin(),ve.begin()+cnt);
    //sort(yyy.begin(),yyy.end());
    //yyy.erase(unique(yyy.begin(),yyy.end()),yyy.end());
    
    for(int i=1;i<=cnt;i++){
        //int y_=lower_bound(yyy.begin(),yyy.end(),y)-yyy.begin()+1;
        int y=ve[i].y;
        int f=ve[i].f;
        int id=ve[i].id;
        if(f==0){
            add(y,1);
        }else{
            ans[id]+=f*search(y);
        }
    }
    for(int i=1;i<=m;i++){
        //cout<<ans[i]<<'\n';
        printf("%d\n",ans[i]);
    }
}