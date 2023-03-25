#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 3) {
            cout << "NO" << endl;
        } else if (n & 1) {
            cout << "YES" << endl;
            int tmp = n / 2 - 1;
            for (int i = 1; i <= n; i++) {
                if (i & 1) {
                    cout << "-" << tmp << ' ';
                } else {
                    cout << tmp + 1 << ' ';
                }
            }
        } else {
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++) {
                if (i & 1) {
                    cout << 1 << ' ';
                } else {
                    cout << "-1" << ' ';
                }
            }
            cout << endl;
        }
    }
}