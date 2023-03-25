#include <iostream>
using namespace std;

int dp[1005], num[1005];
const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        dp[i] = -0x3f3f3f;
    }
    dp[0] = 0;
    num[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (dp[j] < dp[j - i] + i) {
                dp[j] = dp[j - i] + i;
                num[j] = num[j - i];
            } else if (dp[j] == dp[j - i] + i) {
                num[j] = (num[j] + num[j - i]) % mod;
            }
        }
    }
    cout << num[n];
}