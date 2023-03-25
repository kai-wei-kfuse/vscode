#include <algorithm>//完全背包
#include <iostream>
using namespace std;
int a[1005], val[1005], dp[1005];
int main() {
    int n, v;
    cin >> n >> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> val[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = a[i]; j <= v; j++) {
            dp[j] = max(dp[j], dp[j - a[i]] + val[i]);
        }
    }
    cout << dp[v];
}