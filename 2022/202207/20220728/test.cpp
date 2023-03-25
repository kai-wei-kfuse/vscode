#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0);
int main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<double> a(n + 1);
        double sum = 0;
        int flag = 0;
        double res = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
            if (flag == 0) {
                res += a[i];
            } else if (flag == 1) {
                res += a[i] * 0.8;
            } else if (flag == 2) {
                res += a[i] * 0.5;
            }
            if (flag == 0 && res >= 200) {
                flag = 2;
            } else if (flag == 0 && res >= 100) {
                flag = 1;
            } else if ((flag == 0 || flag == 1) && res >= 200) {
                flag = 2;
            }
        }
        double x = 0, y = 0;
        double jj = 0;
        if (sum > 225.0) {
            jj = 200 + (sum - 225) * 0.5;
        } else if (sum > 100) {
            jj = 100 + (sum - 100) * 0.8;
        } else {
            jj = sum;
        }
        printf("%.3f %.3f\n", jj, res);
    }
}