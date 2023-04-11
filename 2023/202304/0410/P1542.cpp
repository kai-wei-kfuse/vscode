#include <bits/stdc++.h>
using namespace std;

int dp[45][45][45][45];

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> ve(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    vector<int> a(5, 0);
    for (int i = 1; i <= m; i++) {
        int tmp;
        cin >> tmp;
        a[tmp]++;
    }
    memset(dp, -0x3f3f3f3f, sizeof(dp));
    dp[0][0][0][0] = ve[1];
    for (int i = 0; i <= a[4];i++){
        for (int j = 0; j <= a[3];j++){
            for (int k = 0; k <= a[2];k++){
                for (int l = 0; l <= a[1];l++){
                    int tmp = i * 4 + j * 3 + k * 2 + l + 1;
                    if (i) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l] + ve[tmp]);
                    if (j) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j - 1][k][l] + ve[tmp]);
                    if (k) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k - 1][l] + ve[tmp]);
                    if (l) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k][l - 1] + ve[tmp]);
                }
            }
        }
    }
    cout << dp[a[4]][a[3]][a[2]][a[1]] << endl;
}