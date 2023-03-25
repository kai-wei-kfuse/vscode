#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
    IOS int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> edg[n + 1];
        vector<int> ins(n + 1, 0);
        for (int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            edg[x].push_back(y);
            edg[y].push_back(x);
            ins[x]++;
            ins[y]++;
        }
        int ans = 0;
        queue<int> q;
        int num = 0;
        for (int j = 1; j <= n; j++) {
            if (ins[j] == 1) {
                ins[j] = 0;
                q.push(j);
                num++;
            }
        }
        int res = 0, cnt = 1;
        if (num == 0) cnt = 0;
        while (!q.empty()) {
            int u = q.front();
            ans++, res++;
            q.pop();
            for (auto v : edg[u]) {
                ins[v]--;
                if (ins[v] == 1) {
                    q.push(v);
                }
            }
            if (res == num) {
                if (cnt < k)
                    cnt++;
                else {
                    break;
                }
                res = 0;
                num = q.size();
                // cout << ans << endl;
            }
        }
        // cout << cnt << endl;
        if (cnt < k && ans == n - 1) {
            cout << "0" << '\n';
        } else
            cout << n - ans << '\n';
    }
}