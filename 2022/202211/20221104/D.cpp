#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> ve(n + 1), pref(n + 1, 0), suf(n + 2, 0), sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
        sum[i] = sum[i - 1] + ve[i];
        pref[i] = ve[i] ^ pref[i - 1];
        cout << pref[i] << ' ';
    }
    cout << endl;
    suf[n] = ve[n];
    for (int i = n - 1; i >= 1; i--) {
        suf[i] = ve[i] ^ suf[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << suf[i] << ' ';
    }
    cout << endl;
    int l, r;
    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        if ((r - l + 1) > 2) {
            if ((r - l + 1) % 2 != 0)
                if (pref[l - 1] ^ pref[r] != 0) {
                    cout << "-1" << endl;
                } else {
                    cout << 1 << endl;
                }
            else {
                int f = 0;
                for (int i = l + 2; i <= r - 2; i += 2) {
                    if (pref[l - 1] ^ pref[i] == 0 &&
                        suf[i + 1] ^ suf[r + 1] == 0) {
                        cout << "2" << endl;
                        f = 1;
                        break;
                    }
                }
                if (f == 0)
                    cout << "-1" << endl;
            }
        } else if (r == l && ve[r] == 0) {
            cout << 0 << endl;
        } else if (sum[r] - sum[l - 1] == 0) {
            cout << "0" << endl;
        } else {
            cout << "-1" << endl;
        }
        // else {
        //     cout << ((pref[l - 1] ^ pref[r - 1]) ^ (pref[l] ^ pref[r])) <<
        //     endl;
        // }
    }
}