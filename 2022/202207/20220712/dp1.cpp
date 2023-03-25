#include <algorithm>//01背包
#include <iostream>
using namespace std;
int a[1005], val[1005], dp[1005];
int main() {
    int n, v;
    cin >> n >> v;  // n:物品数，v：总体积
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> val[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= a[i]; j--) {
            dp[j] = max(dp[j - a[i]] + val[i], dp[j]);
        }
    }
    cout << dp[v];
}