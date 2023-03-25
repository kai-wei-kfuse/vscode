#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> a(105);
vector<vector<ll>> dp(205, vector<ll>(205));
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        dp[1][i] = (a[i] - a[1]) * (a[i] - a[1])+(a[n] - a[i]) * (a[n] - a[i]);
        cout << dp[1][i] << ' ';
    }
    cout << endl;
    for (int i = 1; i <= n ; i++) {
        cout << i << ':' << endl;
        for (int j = 1; j < n; j++) {
            cout << j << ':';
            for (int k = 1; k < j; k++) {
                dp[i][j] =
                    max(dp[i][j], dp[i - 1][k] + (a[j] - a[k]) * (a[j] - a[k]) +
                                      (a[n] - a[j]) * (a[n] - a[j]) -
                                      (a[n] - a[k]) * (a[n] - a[k]));
            }
            // for (int k = j + 1; k < n; k++) {
            //     dp[i][j] =
            //         max(dp[i][j], dp[i - 1][k] + (a[j] - a[k]) * (a[j] - a[k]) +
            //                           (a[n] - a[k]) * (a[n] - a[k]) -
            //                           (a[n] - a[j]) * (a[n] - a[j]));
            // }
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
    for (int i = 0; i <= n;i++){
        for (int j = 0; j <= n;j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }

    vector<int> ans;
    for (int i = n - 1; i >= 0;i-=2)
        ans.push_back(dp[i][n]);
    while(ans.size()!=n){
        ans.push_back(dp[0][n]);
    }
    for(auto i:ans){
        cout << i << endl;
    }
}