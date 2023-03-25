#include <bits/stdc++.h>
using namespace std;
signed main() {
    int t = 0;
    int cnt = 0;
    int a[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= a[i]; j++) {
            t++;
            if (t == 33) {
                cnt++;
            }
            if (t == (365 - 29)) {
                cnt++;
            }
            cout << "make_pair(";
            cout << '"';
            if (i < 10) {
                cout << 0 << i;
                if (j < 10) {
                    cout << 0 << j;
                } else {
                    cout << j;
                }
            } else {
                cout << i;
                if (j < 10) {
                    cout << 0 << j;
                } else {
                    cout << j;
                }
            }
            cout << '"' << ',';
            cout << cnt << "),";
            cout << endl;
        }
    }
}