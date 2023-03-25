#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

ll a[1000005];

int main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ll ans1 = 0, ans2 = 0, ans3 = 0x3f3f3f3f;
        // a[0] = 0x3f3f3f3f, a[n + 1] = 0x3f3f3f3f;
        if (n % 2 == 0) {
            for (int i = 2; i <= n; i += 2) {
                if (i != n) {
                    if (a[i] <= max(a[i - 1], a[i + 1])) {
                        ans1 += max(a[i - 1], a[i + 1]) - a[i] + 1LL;
                    }
                    if (a[i] >= min(a[i - 1], a[i + 1])) {
                        if (a[i] == 1)
                            ans2 = 0x3f3f3f3f;
                        ans2 += a[i] - min(a[i - 1], a[i + 1]) + 1LL;
                    }
                } else {
                    if (a[i] <= a[i - 1]) {
                        ans1 += a[i - 1] - a[i] + 1LL;
                    }
                    if (a[i] >= a[i - 1]) {
                        ans2 += a[i] - a[i - 1] + 1LL;
                        if (a[i] == 1)
                            ans2 = 0x3f3f3f3f;
                    }
                }
            }
            // cout << ans1 << ' ' << ans2 << endl;
            ans3 = min(ans1, ans2);
            ans1 = 0, ans2 = 0;
            for (int i = 1; i <= n; i += 2) {
                if (i != 1) {
                    if (a[i] <= max(a[i - 1], a[i + 1])) {
                        ans1 += max(a[i - 1], a[i + 1]) - a[i] + 1LL;
                    }
                    if (a[i] >= min(a[i - 1], a[i + 1])) {
                        ans2 += a[i] - min(a[i - 1], a[i + 1]) + 1LL;
                        if (a[i] == 1)
                            ans2 = 0x3f3f3f3f;
                    }
                } else {
                    if (a[i] <= a[i + 1]) {
                        ans1 += a[i + 1] - a[i] + 1LL;
                    }
                    if (a[i] >= a[i + 1]) {
                        ans2 += a[i] - a[i + 1] + 1LL;
                        if (a[i] == 1)
                            ans2 = 0x3f3f3f3f;
                    }
                }
            }
            // cout << ans1 << ' ' << ans2 << endl;
            ans3 = min({ans1, ans2, ans3});
        } else {
            for (int i = 2; i < n; i += 2) {
                if (a[i] <= max(a[i - 1], a[i + 1])) {
                    ans1 += max(a[i - 1], a[i + 1]) - a[i] + 1LL;
                }
                if (a[i] >= min(a[i - 1], a[i + 1])) {
                    ans2 += a[i] - min(a[i - 1], a[i + 1]) + 1LL;
                    if (a[i] == 1)
                        ans2 = 0x3f3f3f3f;
                }
            }
            ans3 = min(ans1, ans2);
            // cout << ans1 << ' ' << ans2 << endl;
            ans1 = 0, ans2 = 0;
            for (int i = 1; i <= n; i += 2) {
                if (i == n) {
                    if (a[i] <= a[i - 1]) {
                        ans1 += a[i - 1] - a[i] + 1LL;
                    }
                    if (a[i] >= a[i - 1]) {
                        ans2 += a[i] - a[i - 1] + 1LL;
                        if (a[i] == 1)
                            ans2 = 0x3f3f3f3f;
                    }
                } else if (i == 1) {
                    if (a[i] >= a[i + 1]) {
                        ans2 += a[i] - a[i + 1] + 1LL;
                        if (a[i] == 1)
                            ans2 = 0x3f3f3f3f;
                    }
                    if (a[i] <= a[i + 1]) {
                        ans1 += a[i + 1] - a[i] + 1LL;
                    }
                } else {
                    if (a[i] <= max(a[i - 1], a[i + 1])) {
                        ans1 += max(a[i - 1], a[i + 1]) - a[i] + 1LL;
                    }
                    if (a[i] >= min(a[i - 1], a[i + 1])) {
                        ans2 += a[i] - min(a[i - 1], a[i + 1]) + 1LL;
                        if (a[i] == 1)
                            ans2 = 0x3f3f3f3f;
                    }
                }
            }
            ans3 = min({ans1, ans2, ans3});
            // cout << ans1 << ' ' << ans2 << endl;
        }
        cout << ans3 << '\n';
    }
}