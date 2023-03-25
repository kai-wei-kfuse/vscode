#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = ' ' + s;

    vector<int> suf(N);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            cnt++;
            if (cnt != 2) {
                suf[i] = suf[i - 1] + 1;
            } else {
                suf[i] = suf[i - 1];
            }
        } else {
            cnt = 0;
            suf[i] = suf[i - 1];
        }
        /*         cout << suf[i]; */
    }
    for (int i = n; i >= 1; i--) {
        if (s[i] == '1') {
            cnt++;
            if (cnt != 2) {
                suf[i] = suf[i + 1] + 1;
            } else {
                suf[i] = suf[i + 1];
            }
        } else {
            cnt = 0;
            suf[i] = suf[i + 1];
        }
        /*         cout << suf[i]; */
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        int x = (v - (u - 1)) / 3;
        int y = suf[v] - suf[u - 1];
        if (suf[v - 1] < suf[v] && suf[u] > suf[u - 1]) {
            y--;
        }
        if (y > x) {
            cout << 0 << endl;
        } else {
            cout << x - y << endl;
        }
    }
}