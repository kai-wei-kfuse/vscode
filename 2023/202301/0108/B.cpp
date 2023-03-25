#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n * n + 2);
        int cnt = 1;
        for (int i = 1; i <= n * n; i += 2) {
            ve[i] = cnt;
            cnt++;
        }
        cnt = n * n;
        for (int i = 2; i <= n * n; i += 2) {
            ve[i] = cnt;
            cnt--;
        }
        // for (int i = 1; i <= n * n; i++) {
        //     cout << ve[i] << ' ';
        // }
        vector<vector<int> > ans(n + 2, vector<int>(n + 2));
        cnt = 1;
        for (int i = 1; i <= n; i++) {
            if (i & 1) {
                for (int j = 1; j <= n; j++) {
                    ans[i][j] = ve[cnt];
                    cnt++;
                }
            } else {
                for (int j = n; j >= 1; j--) {
                    ans[i][j] = ve[cnt];
                    cnt++;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
    }
}