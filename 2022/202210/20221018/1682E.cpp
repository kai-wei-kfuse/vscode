//记录前缀和
//二分答案
// chack：滑动窗口，遍历是否达到要求
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, su;
        cin >> n >> su;
        vector<int> ve(n + 1), sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            sum[i] = sum[i - 1] + ve[i];
        }
        if (sum[n] < su)
            cout << "-1" << endl;
        else {
            int ans = 0;
            int l = 1, r = 1;
            while (r <= n) {
                if (sum[r] - sum[l - 1] < su) {
                    r++;
                } else if (sum[r] - sum[l - 1] > su) {
                    l++;
                } else {
                    ans = max(ans, r - l + 1);
                    r++;
                }
            }
            cout << n - ans << endl;
        }
    }
}