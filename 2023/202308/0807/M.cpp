#include<bits/stdc++.h>
using namespace std;

#define int long long

int cnt[15],pre[15];

signed main(){
    int t;
    cin>>t;
    cnt[1] = 9;
    pre[1] = 9;
    for(int i=2;i<=10;i++){
        cnt[i] = cnt[i-1]*10;
        pre[i]=pre[i-1]+cnt[i];
    }
    while(t--){
        int n;
        cin >> n;
        int maxn = 1,x;
        for (int i = 1; i <= 10;i++){
            if(maxn*10>n){
                x= i;
                break;
            }
            maxn *= 10;
        }
        int ans = 0;
        for (int i = 1; i < x;i++){
            ans += i * cnt[i];
        }
        ans+=(n-pre[x-1])*x;
        cout << ans << endl;
    }
}