#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0)
#define int long long
int n,m,tree[500005];//n数的个数
int lowbit(int x){
    return x&(-x);
}
void add(int i,int a){//单点增加
    while(i<=n){
        tree[i]+=a;
        i+=lowbit(i);
    }
}
int search(int i){//前缀和查询
    int ans=0;
    while(i!=0){
        ans+=tree[i];
        i-=lowbit(i);
    }
    return ans;
}
signed main()
{
/*     add(1,1);
    cout<<search(2)<<endl; */
    int t;
    cin>>t;
    while(t--)
    {
        IOS;
        cin>>n;
        for(int i=0;i<=n;i++) tree[i]=0;
        vector<int>p(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>p[i];
        }
        if(n==1)
        {
            cout<<0<<" "<<1<<endl;
            continue;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=search(n)-search(p[i]);
            add(p[i],1);
        }
        int cur=(1<<(__lg(n)+1))-1;
        if(ans%2==0)
        {
            if(n==2)
            {
                cout<<0<<" "<<1<<endl;
            }else
            {
                cout<<0<<" "<<(cur^2)<<endl;
            }
        }else
        {
            if(n==2)
            {
                cout<<2<<" "<<3<<endl;
            }else
            {   
                cout<<2<<" "<<cur<<endl;
            }
            
        }
        
    }
}