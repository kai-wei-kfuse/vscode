#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
vector<int> f(N), l(N);
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)


int main() {
    int n, m;
    IOS;
    cin >> n >> m;
    string s;
    cin >> s;
    s = ' ' + s;

    vector<int> suf(N);
    
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            cnt++;
            f[i] = cnt;
            if (cnt % 2 == 1) {
                suf[i] = suf[i - 1] + 1;
            } else {
                suf[i] = suf[i - 1];
            }
        } else {
            cnt = 0;
            suf[i] = suf[i - 1];
        }
        // cout << f[i];
    }

    // cout << endl;
    cnt = 0;
    for (int i = n; i >= 1; i--) {
        if (s[i] == '1') {
            cnt++;
            l[i] = cnt;
        } else {
            cnt = 0;
        }
        // cout << l[i];
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        int x = (v - (u - 1)) / 3;
        int tmp = f[v] + l[u];
        int y = suf[v - f[v]] - suf[u - 1 + l[u]] + tmp / 2 + tmp % 2;
        // int y = min(suf[v] - suf[u - 1], prf[u] - prf[v + 1]);
        // if (suf[v - 1] < suf[v] && suf[u] > suf[u - 1]) {
        //     y--;
        // }
        if (y > x) {
            cout << 0 << '\n';
        } else {
            cout << x - y << '\n';
        }
    }
}