#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int n,m,k,t;
    cin>>n>>m>>k>>t;
    int ans=0;
    for(int l=1;l<=k;l++){
        int x,y;
        cin>>x>>y;
        int sum=0;
        for(int i=max(1,x-t);i<=min(x+t,n);i++){
            for(int j=max(1,y-t);j<=min(y+t,m);j++){
                if(hypot(x-i,y-j)<=t)sum++;
            }
        }
        ans=max(ans,sum);
    }
    cout<<ans;
}