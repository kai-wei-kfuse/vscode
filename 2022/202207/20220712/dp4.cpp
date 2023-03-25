#include <algorithm>  //多重背包二进制优化
#include <iostream>
#include <vector>
using namespace std;
int a, s, val, dp[2005];
int main() {
    int n, v;
    cin >> n >> v;
    vector<pair<int, int> > ve;
    for (int i = 1; i <= n; i++) {
        cin >> a >> val >> s;
        for (int k = 1; k <= s; k *= 2) {
            ve.push_back({k * a, k * val});
            s -= k;
        }
        if (s > 0)
            ve.push_back({s * a, val * s});
    }
    for (auto i : ve) {
        for (int j = v; j >= i.first; j--) {
            dp[j] = max(dp[j], dp[j - i.first] + i.second);
        }
    }
    cout << dp[v];
}