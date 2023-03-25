#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<vector<int> > f(n + 1, vector<int>(3));
        f[n][a[n]]++;
        for (int i = n - 1; i >= 1; i--) {
            if (a[i] == a[i + 1]) {
                f[i][0] = f[i + 1][0];
                f[i][1] = f[i + 1][1];
                f[i][2] = f[i + 1][2];
            } else if ((a[i] + 1) % 3 == a[i + 1]) {
                f[i][0] = f[i + 1][0];
                f[i][1] = f[i + 1][1];
                f[i][2] = f[i + 1][2];
                f[i][a[i]]++;
            } else {
                if (f[i + 1][a[i]] != 0) {
                    f[i][0] = f[i + 1][0];
                    f[i][1] = f[i + 1][1];
                    f[i][2] = f[i + 1][2];
                    f[i][(a[i] + 2) % 3]--;
                } else {
                    f[i][a[i]] = 1;
                }
            }
        }
        if ((a[n] + 1) % 3 == a[1]) {
            f[n][0] = f[1][0];
            f[n][1] = f[1][1];
            f[n][2] = f[1][2];
            f[n][a[n]]++;
        } else if (a[n] == a[1]) {
            f[n][0] = f[1][0];
            f[n][1] = f[1][1];
            f[n][2] = f[1][2];
        } else {
            if (f[1][a[n]] != 0) {
                f[n][0] = f[1][0];
                f[n][1] = f[1][1];
                f[n][2] = f[1][2];
                f[n][(a[n] + 2) % 3]--;
            } else {
                f[n][a[n]] = 1;
            }
        }
        for (int i = n - 1; i >= 1; i--) {
            if (a[i] == a[i + 1]) {
                f[i][0] = f[i + 1][0];
                f[i][1] = f[i + 1][1];
                f[i][2] = f[i + 1][2];
            } else if ((a[i] + 1) % 3 == a[i + 1]) {
                f[i][0] = f[i + 1][0];
                f[i][1] = f[i + 1][1];
                f[i][2] = f[i + 1][2];
                f[i][a[i]]++;
            } else {
                if (f[i + 1][a[i]] != 0) {
                    f[i][0] = f[i + 1][0];
                    f[i][1] = f[i + 1][1];
                    f[i][2] = f[i + 1][2];
                    f[i][(a[i] + 2) % 3]--;
                } else {
                    f[i][a[i]] = 1;
                }
            }
        }
        int ans[3] = {0, 0, 0};
        for (int i = 1; i <= n; i++) {
            if (f[i][0])
                ans[0]++;
            if (f[i][1])
                ans[1]++;
            if (f[i][2])
                ans[2]++;
        }
        int flag = 0;
        for (int i = 0; i <= 2; i++) {
            if (ans[i] == n)
                flag = 1;
        }
        if (flag)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
}