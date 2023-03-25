#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[200][30][3];
signed main() {
    memset(dp, -0x3f, sizeof dp);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> v;
    int cnt = 0;
    while (m) {
        v.push_back(m);
        m = m * 2 / 3;
        cnt++;
    }
/*     cout << cnt << endl; */
    int len = v.size();
    dp[0][0][1] = 0;
    dp[0][0][0] =0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < len; j++) {
                

        }

        
    }
    int maxn = 0;
    for (auto it:v)
    {
        maxn = max(dp[n][it][0],maxn);
        maxn = max(dp[n][it][1],maxn);
        maxn = max(dp[n][it][2],maxn);
    }
    cout << maxn;
}