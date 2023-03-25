#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> ve(n + 1),dp(n+1,1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    int maxn = 1;
    for (int i = 2; i <= n;i++){
        for (int j = 1; j < i;j++){
            if(ve[i]>ve[j]){
                dp[i] = max(dp[i], dp[j] + 1);
                maxn = max(dp[i], maxn);
            }
        }
    }
    cout << maxn;
}