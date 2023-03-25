#include <algorithm>  //多重背包单调队列优化
#include <cstring>
#include <iostream>
using namespace std;
int dp[20005], dps[20005], Q[20005];
int main() {
    int n, m;
    cin >> n >> m;  // n物品种类，m背包体积
    for (int i = 1; i <= n; i++) {
        int v, val, s;
        cin >> v >> val >> s;
        // a每个物品的体积，val每个物品的价值，s同种物品的个数
        memcpy(dps, dp, sizeof dp);
        for (int j = 0; j < v; j++) {
            int head = 0, tail = -1;
            for (int k = j; k <= m; k += v) {
                // k：类比01背包，k代表在k体积取物品的最大值。
                if (head <= tail && Q[head] < k - s * v)
                    head++;
                if (head <= tail)
                    dp[k] = max(dps[k], dps[Q[head]] + (k - Q[head]) / v * val);
                //因为dp[k]通过前面的旧值dps[Q[h]]来更新，所以窗口在dps数组上滑动。
                while (head <= tail &&
                       dps[k] >= dps[Q[tail]] + (k - Q[tail]) / v * val)
                    tail--;
                Q[++tail] = k;
            }
        }
    }
    cout << dp[m];
}