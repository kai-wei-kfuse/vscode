#include <algorithm>
#include <iostream>
using namespace std;

int a[305], dp[305][305];
int s[305];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int len = 2; len <= n;
         len++) {  //区间遍历，枚举区间大小，枚举区间左端点
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = 0x3f3f3f3f;
            for (int k = i; k < j; k++) {
                dp[i][j] =
                    min(dp[i][j], dp[i][k] + dp[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }
    cout << dp[1][n];
}