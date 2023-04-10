#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int> > a(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        // for (int i = n; i >= 1;i--){
        //     for (int j = n; j >= 1;j--){
        //         if(a[i][j]!=a[])
        //     }
        // }
        int xx = n / 2;
        if (n % 2 == 1)
            xx++;
        int cnt = 0;
        for (int i = 1; i <= xx; i++) {
            if (n % 2 == 1 && i == xx) {
                for (int j = 1; j <= xx; j++) {
                    if (a[i][j] != a[n - i + 1][n - j + 1]) {
                        cnt++;
                    }
                }
            } else
                for (int j = 1; j <= n; j++) {
                    if (a[i][j] != a[n - i + 1][n - j + 1]) {
                        cnt++;
                    }
                }
        }
        //cout << cnt << endl;
        if (cnt > k) {
            cout << "NO" << endl;
        } else {
            if ((cnt - k) % 2 == 0 || n % 2 == 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}