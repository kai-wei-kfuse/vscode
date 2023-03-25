#include <bits/stdc++.h>
using namespace std;
int lcm(int x, int y) {
    return x * y / __gcd(x, y);
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int flag = 1;
        for (int i = 2; i < n; i++) {
            int l = lcm(a[i - 1], a[i]);
            int r = lcm(a[i], a[i + 1]);
            if (__gcd(l, r) != a[i]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}