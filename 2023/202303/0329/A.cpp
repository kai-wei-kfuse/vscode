#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int ans = 0, num = a;
        for (int i = a; i <= b; i++) {
            int tmp = i;
            int maxn = -1, minn = 10;
            while (tmp) {
                maxn = max(maxn, tmp % 10);
                minn = min(minn, tmp % 10);
                tmp /= 10;
            }
            if (maxn - minn > ans) {
                ans = maxn - minn;
                num = i;
            }
            if (ans == 9)
                break;
        }
        cout << num << endl;
    }
}