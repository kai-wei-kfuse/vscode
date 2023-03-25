#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n + 5),dp(n+5,0);
    for (int i = 1;i<=n;i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n;i++){
        dp[i] = max(a[i], a[i] + dp[i-1]);
    }
    int maxn = -0x3f3f3f3f;
    for (int i = 1; i <= n;i++){
        maxn = max(maxn, dp[i]);
    }
    cout << maxn;
}