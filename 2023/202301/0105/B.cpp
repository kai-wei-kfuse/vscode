#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 2);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int tmp = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == tmp + 1) {
                tmp++;
            }
        }
        // cout << tmp << ' ';
        int ans = (n - tmp) / k;
        if ((n - tmp) % k)
            ans++;
        cout << ans << endl;
    }
}