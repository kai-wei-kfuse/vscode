#include <algorithm>  //多重背包
#include <iostream>
using namespace std;
int a, s, val, dp[105];
int main() {
    int n, v;
    cin >> n >> v;
    for (int i = 1; i <= n; i++) {
        cin >> a >> val >> s;
        for (int j = v; j >= a; j--) {
            for (int k = 1; k <= s && k * a <= j; k++) {
                dp[j] = max(dp[j], dp[j - k * a] + k * val);
            }
        }
    }
    cout << dp[v];
}