#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, k, e;
    // for (int n = 1; n <= 10; n++) {
    //     for (int k = 1; k <= 10; k++) {
    //         for (int e = 0; e <= n - k; e++) {
    cin >> n >> k >> e;
    int a = e, b = k, c = n - a - b;
    // cout << a << ' ' << b << ' ' << c <<' ';
    vector<int> vis(n + 1, 0);
    priority_queue<int> q;
    // q.push(a), q.push(c);
    vis[b] = 1;
    int ans = 0x3f3f3f3f;
    for (int m = n; m >= 1; m--) {
        for (int i = 1; i <= m; i++) {
            vis[i] = 0;
        }
        q.push(a), q.push(c);
        vis[b] = 1;
        for (int i = m; i >= 1; i--) {
            if (q.top() >= i && !vis[i]) {
                int p = q.top();
                q.pop();
                p -= i;
                vis[i] = 1;
                q.push(p);
                /*             cout<<p<<endl; */
            }
        }
        int sum = 0;
        while (q.size()) {
            sum += q.top();
            q.pop();
        }
        // cout << sum << endl;
        ans = min(ans, sum);
    }
    cout << ans << endl;
    // }
    //     }
    // }
}