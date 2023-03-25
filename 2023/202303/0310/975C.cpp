#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> ve(n + 1), pref(n + 1, 0), k(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
        pref[i] += pref[i - 1] + ve[i];
    }
    int at = 0;
    for (int i = 1; i <= m; i++) {
        int tmp;
        cin >> tmp;
        at += tmp;
        int pos = upper_bound(pref.begin() + 1, pref.begin() + 1 + n, at) - pref.begin();
        if (pos == n + 1) {
            at = 0;
            pos = 0;
        } else
            pos--;
        cout << n - pos << endl;
    }
}