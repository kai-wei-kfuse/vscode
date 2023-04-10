#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long maxn=0x3f3f3f3f,minn=0;
    for(int i=1;i<=n;i++){
        long long a,b;
        cin>>a>>b;
        if(a%b==0){
            maxn=min(a/b,maxn);
            minn=max(minn,a/(b+1LL)+1LL);
        }else{
            long long x=(b+1LL)-a%(b+1LL);
            minn=max(minn,(a+x)/(b+1LL));
            maxn=min(a/b,maxn);
        }
    }
    cout<<minn<<' '<<maxn;
}
