#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> ve(n + 1), pref(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        sort(ve.begin() + 1, ve.end());
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + ve[i];
        }

        vector<int> win;
        win.push_back(0);
        int tmp = 0;
        for (int i = 2; i <= n; i++) {
            if (ve[i] != ve[i - 1]) {
                tmp = i - 1;
                win.push_back(tmp);
            } else if (ve[i] == ve[i - 1]) {
                win.push_back(tmp);
            }
        }

        int me = lower_bound(pref.begin(), pref.end(), m) - pref.begin();
        // if (pref[me] > m) {
        //     me--;
        // }
        if (pref[me] == m) {
            win[me]++;
        }

        for (int i = 0; i <= n; i++) {
            if (i > me) {
                win[i]++;
            }
        }
        // if (me == 0) {
        //     me = -1;
        // }
        // win.push_back(5e5);
        win.push_back(me);
        sort(win.begin(), win.end());
        for (auto i : win) {
            cout << i << ' ';
        }
        cout << endl;
        cout << me << " ";

        int ans = upper_bound(win.begin(), win.end(), me) - win.begin();
        // int ans2 = lower_bound(win.begin(), win.end(), me) - win.begin();
        if (win[ans - 1] == me) {
            ans--;
        }
        cout << win.size() - ans << endl;
        // cout << ans << endl;
    }
}