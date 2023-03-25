#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > ve;
    vector<int> dp(m + 5, 0);
    for (int i = 1; i <= n;i++){
        int v, w, s;
        cin >> v >> w >> s;
        for (int j = 1; j <= s;j*=2){
            if(j<=s){
                ve.push_back({v * j, w * j});
            }
            s -= j;
        }
        if(s>0){
            ve.push_back({s * v, w * s});
        }
    }
    for(auto i:ve){
        for (int j = m; j >= i.first;j--){
            dp[j] = max(dp[j], dp[j - i.first] + i.second);
        }
    }
    cout << dp[m];
}