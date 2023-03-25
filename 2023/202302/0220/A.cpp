#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int sum1 = 0, sum2 = 0;
        vector<int> x(a + 1), y(b + 1);
        for (int i = 1; i < a; i++) {
            cin >> x[i];
            sum1 += x[i];
        }
        for (int i = 1; i <= b; i++) {
            cin >> y[i];
            sum2 += y[i];
        }
        int l, r;

        l = sum2 * (b + 1) / b - sum2 + 1;
        if ((sum1 * a) % (a - 1) != 0)
            r = sum1 * a / (a - 1) - sum1;
        else {
            r = sum1 * a / (a - 1) - sum1 - 1;
        }
        cout << l << ' ' << r << endl;
    }
}