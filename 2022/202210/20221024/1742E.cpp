#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<pair<int, int>> q(k);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < k; i++) {
            cin >> q[i].first;
            q[i].second = i;
        }
        sort(q.begin(),q.end());
        int x = 0, y = 1;
        vector<pair<int, int>> ans(k);
        int sum = 0;
        for (y = 0; y < k; y++) {
            for (; x < n; x++) {
                if (a[x] <= q[y].first) {
                    sum += a[x];
                } else {
                    break;
                }
            }
            ans[y].second = sum;
            ans[y].first = q[y].second;
        }
        sort(ans.begin(), ans.end());
        for (auto [f, s] : ans) {
            cout << s << ' ';
        }
        cout << endl;
    }
}