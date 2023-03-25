#include <bits/stdc++.h>
using namespace std;

const int N = 3e6 + 5;
int z[N], p[N];

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string x = s;
    string y = s.substr(0, n);
    string t = s.substr(n);
    z[1] = p[1] = 2 * n;
    reverse(t.begin(), t.end());
    s = "?" + y + t;
    t = "!" + t + y;
    // cout << s << ' ' << t << endl;
    for (int i = 2, l, r = 0; i <= 2 * n; i++) {
        if (i <= r)
            z[i] = min(z[i - l + 1], r - i + 1);
        while (s[1 + z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    // for (int i = 1; i <= 2 * n; i++) {
    //     cout << z[i] << ' ';
    // }
    // cout << endl;
    for (int i = 2, l, r = 0; i <= 2 * n; i++) {
        if (i <= r)
            p[i] = min(p[i - l + 1], r - i + 1);
        while (t[1 + p[i]] == t[i + p[i]])
            p[i]++;
        if (i + p[i] - 1 > r)
            l = i, r = i + p[i] - 1;
    }
    // for (int i = 1; i <= 2 * n; i++) {
    //     cout << p[i] << ' ';
    // }
    // cout << endl;
    for (int i = 1; i <= n; i++) {
        if (i == z[2 * n - i + 1] && n - i == p[n + i + 1]) {
            cout << x.substr(0, i) + x.substr(n + i) << endl;
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
}