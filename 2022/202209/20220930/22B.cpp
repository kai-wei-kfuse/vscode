#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> pref(k + 1);
        for (int i = 1; i <= k; i++) {
            cin >> pref[i];
        }
        // cout << "233" << endl;

        pref[0] = 0;
        vector<int> ini(k + 1);
        int flag = 0, inow;
        for (int i = k; i > 1; i--) {
            ini[i] = pref[i] - pref[i - 1];
        }
        for (int i = 2; i < k; i++) {
            if (ini[i] > ini[i + 1]) {  //要递增
                flag = 1;
                break;
            }
        }
        // cout << inow << endl;
        if (flag == 0) {
            inow = ini[2];
            int need = pref[1];
            if (need >= 0) {
                int chack = need / (n - k + 1);
                if (need % (n - k + 1) != 0)
                    chack++;
                if (chack > inow) {
                    flag = 1;
                }
            } else if (need < 0) {
                int chack = need / (n - k + 1);
                if (chack > inow) {
                    flag = 1;
                }
            }
        }
        if (flag == 1) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}
//-5 -5 -5 -5 -5 -5 -4 -3 -2 -1
//-20 -24 -27 -29 -30
//-6 -4 -2 0 12 14 16
//-12 0 14 30