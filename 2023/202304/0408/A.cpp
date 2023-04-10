#include<bits/stdc++.h>
using namespace std;

#define int long long

int xx[4]={0,0,1,-1};
int yy[4]={1,-1,0,0};

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a1, a2, b1, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        int ans = 0;
        // if(a1==n||a1==1||a2==n||a2==1){
        //     ans--;
        // }
        // if(b1==m||b1==1||b2==m||b2==1){
        //     ans--;
        // }
        int res = 100;
        for(int i=0;i<4;i++){
            int x1=a1+xx[i];
            int y1=b1+yy[i];
            if(x1>=1&&x1<=n&&y1>=1&&y1<=m){
                ans++;
            }
        }
        res=min(res,ans);
        ans=0;
        for(int i=0;i<4;i++){
            int x2=a2+xx[i];
            int y2=b2+yy[i];
            if(x2>=1&&x2<=n&&y2>=1&&y2<=m){
                ans++;
            }
        }
        res=min(res,ans);
        cout<<res<<endl;
    }
}