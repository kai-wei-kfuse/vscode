#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> ve(n + 1), vis(10005, 0);
        int maxn = 0;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            maxn = max(maxn, ve[i]);
            vis[ve[i]] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= maxn; i++) {
            if (vis[i] == 0) {
                ans += i;
            }
        }
        int flag = 0;
        if (ans > k) {
            flag = 1;
        } else {
            for (int i = maxn + 1; i <= 1000; i++) {
                if (ans < k) {
                    ans += i;
                } else if (ans == k) {
                    flag = 0;
                    break;
                } else {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}