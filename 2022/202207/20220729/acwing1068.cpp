#include <algorithm>
#include <iostream>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

int a[605], dp[405][305], dp2[405][405];  //处理环形问题
int s[605];

int main() {
    IOS;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = n + 1; i <= 2 * n; i++)
        s[i] = s[i - 1] + a[i];
    int ansmin = 0x3f3f3f3f, ansmax = -0x3f3f3f;
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= 2 * n; i++) {
            int j = i + len - 1;
            dp[i][j] = 0x3f3f3f3f;
            for (int k = i; k < j; k++) {
                dp[i][j] =
                    min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
                dp2[i][j] =
                    max(dp2[i][j], dp2[i][k] + dp2[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ansmin = min(ansmin, dp[i][n + i - 1]);
        ansmax = max(ansmax, dp2[i][n + i - 1]);
    }
    cout << ansmin << '\n' << ansmax;
}