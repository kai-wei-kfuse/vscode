#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1);
        int x = 0;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        for (int i = 0; i <= n; i++) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (ve[j] > i) {
                    cnt++;
                }
            }
            // cout << cnt << ' ' << i << endl;
            if (cnt == i) {
                cout << cnt << endl;
                x = 1;
                break;
            }
        }
        if (x == 0) {
            cout << "-1" << endl;
        }
    }
}