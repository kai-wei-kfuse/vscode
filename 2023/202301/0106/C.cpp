#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = "?" + s;
        vector<int> a;
        priority_queue<int> q;
        int ans = 0;
        for (int i = 1; i <= n / 2; i++) {
            if (s[i] == 'R') {
                ans += n - i;
            }
            if (s[i] == 'L') {
                ans += i - 1;
                q.push(n - i - (i - 1));
            }
        }
        // cout << ans << " 1 ";
        int tmp = n / 2 + 1;
        if (n & 1) {
            tmp++;
            ans += n / 2;
        }
        // cout << ans << " m" << endl;
        // cout << "tmp=" << tmp << ' ';
        for (int i = n; i >= tmp; i--) {
            if (s[i] == 'R') {
                ans += n - i;
                q.push(i - 1 - (n - i));
            }
            if (s[i] == 'L') {
                ans += i - 1;
            }
        }
        // cout << ans << "|";
        for (int i = 1; i <= n; i++) {
            if (!q.empty()) {
                ans += q.top();
                q.pop();
            }
            cout << ans << ' ';
        }
        cout << '\n';
    }
}