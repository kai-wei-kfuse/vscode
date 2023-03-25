#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<long long> a(n + 2);
        priority_queue<int> q;
        priority_queue<int> qq;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        if (a[m] > 0 && m != n) {
            ans++;
            a[m] = -a[m];
        }
        long long tmp = 0;

        for (int i = m + 1; i <= n; i++) {
            if (a[i] + tmp < 0) {
                ans++;
                // a[i] = -a[i];
                if (!q.empty() && q.top() < a[i]) {
                    tmp -= 2 * q.top();
                    q.pop();
                } else {
                    tmp -= a[i];
                }
            } else {
                if (a[i] < 0)
                    q.push(a[i]);
                tmp += a[i];
            }
        }
        tmp = 0;
        for (int i = m; i >= 2; i--) {
            if (a[i] + tmp > 0) {
                ans++;
                // a[i] = -a[i];
                if (!qq.empty() && qq.top() > a[i]) {
                    tmp -= 2 * qq.top();
                    qq.pop();
                } else {
                    tmp -= a[i];
                }
            } else {
                if (a[i] > 0)
                    qq.push(a[i]);
                tmp += a[i];
            }
        }
        cout << ans << endl;
    }
}
