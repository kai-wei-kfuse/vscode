#include<bits/stdc++.h>
using namespace std;

#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
const int N=1e6+5;
int a[N], b[N];
int next_[N];
int n,m,bx,mod;

inline void kmpnxt(int a[]){//求next数组
    int len =n;
		for (int i = 2, j = 0; i <= len; i++) {
        while (j && a[i] != a[j + 1])
            j = next_[j];
        if (a[i] == a[j + 1])
            j++;
        next_[i] = j;
    }
}

inline int kmp(int a[],int mode[],int len){//做kmp匹配
    int res=0;
    for (int i = 1, j = 0; i <= len; i++) {
        while (j && a[i] != mode[j + 1])
            j = next_[j];
        if (a[i] == mode[j + 1])
            j++;
        if (j == n) {
            j = next_[j];
            res++;
        }
    }
    return res;
}

signed main(){
    ios;
    cin>>n>>m>>bx>>mod;
    int by=bx;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    int lans=0;
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        if(x==1){
            int z,c;
            cin>>z>>c;
            //cout<<z<<'?'<<c<<endl;
            z=(z^ans)%n+1;
            c=(c^ans);
            a[z]=c;
        }else{
            int len;
            cin>>len;
            for(int i=1;i<=len;i++){
                cin>>b[i];
                b[i]^=ans;
            }
            if(len<n){
                by=(by*bx)%mod;
                ans=0;
                continue;
            }
            kmpnxt(a);
            ans=kmp(b,a,len)*next_[n];
            //cout<<ans<<'|'<<next_[n]<<endl;
            lans=(lans+(ans*by)%mod)%mod;
            by=(by*bx)%mod;
        }
        
    }
    //cout<<by<<endl;
    cout<<lans;
}