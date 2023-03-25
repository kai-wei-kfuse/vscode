#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
int main() {
    int t;
    IOS;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1), sum(n + 1);
        sum[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            sum[i] = sum[i - 1] + ve[i];
            // cout << sum[i] << ' ';
        }
        int now, ans = n, res = n;
        for (int i = 1; i <= n; i++) {
            now = sum[i];
            ans = i;
            int l = i, r = l + 1;
            for (; r <= n; r++) {
                if (r == n && sum[r] - sum[l] != now) {
                    ans = n;
                    break;
                }
                if (sum[r] - sum[l] == now) {
                    ans = max(ans, r - l);
                    l = r, r = l + 1;
                } else if (sum[r] - sum[l] > now) {
                    ans = n;
                    break;
                }
            }

            res = min(res, ans);
        }
        cout << res << endl;
    }
}