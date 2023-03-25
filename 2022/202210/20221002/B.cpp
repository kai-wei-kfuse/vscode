#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        int minn = 0x3f3f3f;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            minn = min(minn, a[i]);
        }
        minn *= 2;
        minn -= 1;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += (a[i] + minn - 1) / minn;
            // if (minn == a[i])
            //     ans--;
            // if (a[i] > minn && a[i] % minn != 0)
            //     ans++;
        }
        cout << ans << endl;
    }
}