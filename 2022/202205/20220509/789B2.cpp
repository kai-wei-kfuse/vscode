#include <bits/stdc++.h>
using namespace std;
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0, a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                if (b % 2 != 0) {
                    cnt++;
                    b--;
                    a++;
                }
                a++;
            } else {
                if (a % 2 != 0) {
                    cnt++;
                    a--;
                    b++;
                }
                b++;
            }
        }
        for (int i = 0; i < n; i += 2) {
            if (s[i] != s[i + 1]) {
                s[i] = s[i + 1] = '3';
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '3') {
                int j = i + 1;
                for (; j < n; j++) {
                    if (s[j] != '3') {
                        break;
                    }
                }
                if (i == 0 && j == n) {
                    for (int k = i; k < j; k++) {
                        s[k] = '0';
                    }
                    i = j;
                } else if (i == 0 && j < n) {
                    for (int k = i; k < j; k++) {
                        s[k] = s[j];
                    }
                    i = j;
                } else if (i != 0 && j == n) {
                    for (int k = i; k < j; k++) {
                        s[k] = s[i - 1];
                    }
                    i = j;
                } else {
                    char x;
                    if (s[i - 1] == s[j]) {
                        x = s[j];
                    } else {
                        x = s[j];
                    }
                    for (int k = i; k < j; k++) {
                        s[k] = x;
                    }
                    i = j;
                }
            }
        }
        int yb = 1;
        for (int i = 1; i < n - 1; i++) {
            if (s[i] != s[i - 1]) {
                yb++;
            }
        }
        cout << cnt << " " << yb << endl;
    }
}