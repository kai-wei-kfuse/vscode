#include <bits/stdc++.h>
using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

int main() {
    IOS int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        a = "0" + a;
        b = "0" + b;
        int cnt = 0;
        long long num = 0;
        for (int i = 1; i < n + 1; i++) {
            if (a[i - 1] == b[i - 1] && a[i] != b[i]) cnt++;
            if (a[i] != b[i]) num++;
        }
        if (cnt > 2) {
            cout << 0 << '\n';
        } else if (cnt == 2) {
            cout << 6 << '\n';
        } else if (cnt == 1) {
            cout << 2LL * (n - 1LL) << '\n';
        } else if (cnt == 0) {
            cout << n * (1LL + n) / 2LL << '\n';
        }
    }
}