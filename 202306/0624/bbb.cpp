#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int cnt = 0, last = x;
        int flag = 0;
        int a = 0, b = 0, c = 0;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            cnt |= tmp;
            if (flag == 0) {
                if ((x & cnt) == cnt) {
                    a = cnt;
                } else {
                    flag = 1;
                }
            }
        }
        cnt = 0;
        flag = 0;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            cnt |= tmp;
            if (flag == 0) {
                if ((x & cnt) == cnt) {
                    b = cnt;
                } else {
                    flag = 1;
                }
            }
        }
        flag = 0;
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            cnt |= tmp;
            if (flag == 0) {
                if ((x & cnt) == cnt) {
                    c = cnt;
                } else {
                    flag = 1;
                }
            }
        }
        if ((a | b | c) == x)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}