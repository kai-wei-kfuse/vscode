#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

char a[1005][15], tmp[15];
int dp[1005][1005];

int main() {
    IOS;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] + 1;
    }
    int num;
    for (int i = 1; i <= m; i++) {
        cin >> tmp + 1 >> num;
        int sum = 0;
        int lenb = strlen(tmp + 1);
        for (int j = 1; j <= n; j++) {
            int lena = strlen(a[j] + 1);
            // vector<vector<int> > dp(lena + 3, vector<int>(lenb + 3));
            for (int k = 1; k <= lena; k++)
                dp[k][0] = k;
            for (int k = 1; k <= lenb; k++)
                dp[0][k] = k;
            for (int k = 1; k <= lena; k++) {
                for (int l = 1; l <= lenb; l++) {
                    dp[k][l] = min(dp[k - 1][l] + 1, dp[k][l - 1] + 1);
                    if (tmp[l] == a[j][k])
                        dp[k][l] = min(dp[k][l], dp[k - 1][l - 1]);
                    else
                        dp[k][l] = min(dp[k][l], dp[k - 1][l - 1] + 1);
                }
            }
            // cout << dp[lena][lenb] << ' ';
            if (dp[lena][lenb] <= num)
                sum++;
        }
        cout << sum << '\n';
    }
}